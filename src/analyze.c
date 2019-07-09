#include <stdio.h>
#include <string.h>
#include <analyze.h>
#include <net.h>

void analyze(int size, unsigned char *data) {
    struct ether_frame *efrm = (struct ether_frame *)data;

    printf("-------------------\n");
    printf("size: %d byte\n", size);
    fprintf(stdout, "daddr: %02x:%02x:%02x:%02x:%02x:%02x\n", 
            efrm->daddr[0], efrm->daddr[1], efrm->daddr[2], efrm->daddr[3], efrm->daddr[4], efrm->daddr[5]);
    fprintf(stdout, "saddr: %02x:%02x:%02x:%02x:%02x:%02x\n", 
            efrm->saddr[0], efrm->saddr[1], efrm->saddr[2], efrm->saddr[3], efrm->saddr[4], efrm->saddr[5]);

    printf("type: %x\n", hton16(efrm->type));

    if (hton16(efrm->type) == IP_V4) {
        struct ip_v4_hdr *ip_v4 = (struct ip_v4_hdr *)(data + sizeof (struct ether_frame));

        printf("version: %x\n", ip_v4->version);
        printf("ihl: %d\n", ip_v4->ihl);
        printf("tot_len: %d byte\n", hton16(ip_v4->tot_len));
        printf("protocol: %d\n", ip_v4->protocol);
        printf("saddr: %03d.%03d.%03d.%03d\n", ip_v4->saddr[0], ip_v4->saddr[1], ip_v4->saddr[2], ip_v4->saddr[3]);
        printf("daddr: %03d.%03d.%03d.%03d\n", ip_v4->daddr[0], ip_v4->daddr[1], ip_v4->daddr[2], ip_v4->daddr[3]);
        int data_size = hton16(ip_v4->tot_len) - sizeof (struct ip_v4_hdr);

        if (ip_v4->protocol == 6) {
            data_size -= sizeof (struct tcp_hdr);
            printf("data size: %d\n", data_size);
            struct tcp_hdr *tcp = (struct tcp_hdr *)(ip_v4 + sizeof (struct ip_v4_hdr));
            printf("sport: %d\n", tcp->sport);
            printf("dport: %d\n", tcp->dport);

            if (data_size > 0) {
                char *data = (char *)(tcp + (sizeof (struct tcp_hdr)) - 50);
                int i;
                for (i = 0; i < data_size; i++) {
                    if (32 <= data[i] && data[i] <= 128)
                        printf("%c", data[i]);
                    else
                        printf(".");
                }
            }
        }
    } else if (hton16(efrm->type) == ARP) {
        struct arp_h *arp = (struct arp_h *)(data + sizeof (struct ether_frame));
        printf("hlen: %d\n", arp->hlen);
        printf("plen: %d\n", arp->plen);
        printf("saddr: %02x:%02x:%02x:%02x:%02x:%02x\n", arp->saddr[0], arp->saddr[1], arp->saddr[2], arp->saddr[3], arp->saddr[4], arp->saddr[5]);
        printf("sip: %03d.%03d.%03d.%03d\n", arp->sip[0], arp->sip[1], arp->sip[2], arp->sip[3]); 
        printf("target_addr: %02x:%02x:%02x:%02x:%02x:%02x\n", arp->target_addr[0], arp->target_addr[1], arp->target_addr[2], arp->target_addr[3], arp->target_addr[4], arp->target_addr[5]);
        printf("target_ip: %03d.%03d.%03d.%03d\n", arp->target_ip[0], arp->target_ip[1], arp->target_ip[2], arp->target_ip[3]); 
    }
}



