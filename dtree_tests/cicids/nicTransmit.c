/* Run adjust_pcap.py before this program to alter the source and destination
 * MAC and IP addresses and Ethernet type
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <time.h>
#include <inttypes.h>

#include <netinet/in.h>
#include <netinet/ip.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>
#include <arpa/inet.h> 
#define BILLION  1000000000L


// This will store all the model predictions, to be compared later
// This is global, since I'm not sure how to pass it to the pcap_loop
FILE *pred_file;
FILE *latency_file;

// keep track of packet transmission progress
int i = 0;

// Handlers for effectiveness and latency data
void eff_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void lat_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
	char *device = "enp2s0f1np1";
	char *pcap_file = "/home/admin1/netronome_tests/cicids/pktTest.pcap";
	char error[PCAP_ERRBUF_SIZE];
	pcap_t *pcap_handle, *network_handle;
	
	// Variables for packet filtering
	struct bpf_program filter;
	char filter_exp[] = "ether src 00:15:4d:13:79:ac && ether dst 08:c0:eb:a6:de:3d && ether proto 0x4d4f";
	bpf_u_int32 subnet_mask, ip;

	// Get device info for packet filtering
	if (pcap_lookupnet(device, &ip, &subnet_mask, error) != 0) {
		printf("Could not get device info - %s\n", error);
		return -1;
	}


	// Check if pcap file can be read
	pcap_handle = pcap_open_offline(pcap_file, error);
	if (pcap_handle == NULL) {
		printf("Cannot read pcap file - %s\n", error);
		return -1;
	}

	// Try connecting to interface that is linked with netronome
	network_handle = pcap_create(device, error);
	if (network_handle == NULL) {
		printf("Cannot open %s - %s", device, error);
		return -1;
	}

	// Set up send/receive handle for packet capture
	if (pcap_set_promisc(network_handle, 1) != 0) {  // set promiscuous mode on
		printf("Promiscuous mode could not be activated\n");
		return -1;
	}

	if (pcap_set_snaplen(network_handle, 9978) != 0) {  // accept only 9978 bytes of incoming packets
		printf("Could not set up snapshot length\n");
		return -1;
	}


	if (pcap_set_immediate_mode(network_handle, 1) != 0) {  // get packets as soon as they arrive
		printf("Immediate mode could not be set\n");
		return -1;
	}


	if (pcap_activate(network_handle) != 0) {  // start device handler
		printf("Device handler could not be activated\n");
		return -1;
	}
	
	// Set up handle filters
	if (pcap_compile(network_handle, &filter, filter_exp, 0, ip) != 0) {
		printf("Could not compile filter - %s\n", pcap_geterr(network_handle));
		return -1;
	}

	if (pcap_setfilter(network_handle, &filter) != 0) {
		printf("Error setting filter - %s\n", pcap_geterr(network_handle));
		return -1;
	}


	// Open file to store model predictions
	pred_file = fopen("/home/admin1/netronome_tests/cicids/p4_pred.txt", "w");
	if (pred_file == NULL) {
		printf("There's a problem with opening the prediction text file\n");
		return -1;
	}

	// Open file to store model prediction latencies
	latency_file = fopen("/home/admin1/netronome_tests/cicids/p4_lat.txt", "w");
	if (latency_file == NULL) {
		printf("There's a problem with opening the latency text file\n");
		return -1;
	}


	// collect effectiveness data
	if (pcap_loop(pcap_handle, 6957376, eff_handler, (u_char *)network_handle) != 0) {
		printf("Error with the eff pcap loop\n");
	}
	printf("\n\n");
	i = 0;


	// collect latency data
        if (pcap_loop(pcap_handle, 1000, lat_handler, (u_char *)network_handle) != 0) {
                printf("Error with the lat pcap loop\n");
        }


	pcap_close(pcap_handle);
	pcap_close(network_handle);
	pcap_freecode(&filter);
	fclose(pred_file);
	fclose(latency_file);

	return 0;
}

void eff_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

        pcap_t *network_handle = (pcap_t *)args;
        const struct ip *send_ip_hdr = (struct ip*)(packet + 14);
        struct pcap_pkthdr *pred_pktHdr = NULL;
        const u_char *pred_pkt = NULL;

        // Send test data packet
        int sendLen = header->caplen;
        if (sendLen > 1500)
                sendLen = 1500;

        if (pcap_sendpacket(network_handle, packet, sendLen) != 0) {
                printf("There's an issue with packet transmission\n");
                char *error_msg = pcap_geterr(network_handle);
                printf("%s\n", error_msg);
                printf("Packet Size: %d\n\n", header->caplen);
        } else {
                // check if packet transmitted is udp or tcp
                if (send_ip_hdr->ip_p != IPPROTO_TCP && send_ip_hdr->ip_p != IPPROTO_UDP && send_ip_hdr->ip_p != IPPROTO_ICMP && send_ip_hdr->ip_p != IPPROTO_IGMP) {
                        printf("Some unexpected packet type transmitted\n");
                }
        }

         
        if (pcap_next_ex(network_handle, &pred_pktHdr, &pred_pkt) != 1) {
                printf("There is an issue with packet capture\n");
        } else {
                printf("Response %d from netronome received\n\n", ++i);
        }

        
        // Assume a valid packet has been retrieved
        // the label is the first 32-bit word in the payload
        const struct ip *recv_ip_hdr;
        const u_char *payload;

        // These values are fixed based on my design of the response packets
        int ether_hdr_len = 14;
        int ip_hdr_len = 20;  
        int tcp_hdr_len = 20;
        int udp_hdr_len = 8;
        int icmp_igmp_hdr_len = 4;
        

        // Extract IP header to get UDP/TCP identification
        recv_ip_hdr = (struct ip *)(pred_pkt + ether_hdr_len);
        if (recv_ip_hdr->ip_p == IPPROTO_TCP) {
                payload = pred_pkt + ether_hdr_len + ip_hdr_len + tcp_hdr_len + 3;  // add 3 to get the prediction byte
                fprintf(pred_file, "%u\n", *payload);
        
        } else if (recv_ip_hdr->ip_p == IPPROTO_UDP) {
                payload = pred_pkt + ether_hdr_len + ip_hdr_len + udp_hdr_len + 3;  // add 3 to get the prediction byte
                fprintf(pred_file, "%u\n", *payload);
        
        } else if (recv_ip_hdr->ip_p == IPPROTO_ICMP || recv_ip_hdr->ip_p == IPPROTO_IGMP) {
                payload = pred_pkt + ether_hdr_len + ip_hdr_len + icmp_igmp_hdr_len + 3;  // add 3 to get the prediction byte
                fprintf(pred_file, "%u\n", *payload);

        }

}

void lat_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
	
	pcap_t *network_handle = (pcap_t *)args;
	const struct ip *send_ip_hdr = (struct ip*)(packet + 14);
	struct pcap_pkthdr *pred_pktHdr = NULL;
	const u_char *pred_pkt = NULL;

	// Account for MTU of Netronome
	int sendLen = header->caplen;
	if (sendLen > 1500)
		sendLen = 1500;
	
	
       	struct timespec start, end;
	uint64_t start_ns, end_ns, latency;

	// Send packet, start timer
	pcap_sendpacket(network_handle, packet, sendLen);
	clock_gettime(CLOCK_REALTIME, &start);
	

	// Retrieve response and clock time
	pcap_next_ex(network_handle, &pred_pktHdr, &pred_pkt);
	clock_gettime(CLOCK_REALTIME, &end);
	start_ns = (uint64_t)(start.tv_sec) * BILLION + (uint64_t)(start.tv_nsec);
	end_ns = (uint64_t)(end.tv_sec) * BILLION + (uint64_t)(end.tv_nsec);
	latency = end_ns - start_ns;
	fprintf(latency_file, "%" PRIu64 "\n", latency);
	printf("Response %d from netronome received\n\n", ++i);

}	
