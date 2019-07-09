#include "types.h"

#ifndef YODAKA_NET
#define YODAKA_NET

/*
 * referred "ETHER TYPES" (2018/06/17)
 * https://www.iana.org/assignments/ieee-802-numbers/ieee-802-numbers.xhtml
 */
#define XEROX_PUP               0x0200   
#define XEROX_NS_IDP            0x0600   
#define IP_V4                   0x0800  // RFC7042
#define ARP                     0x0806  // RFC7042
#define FRAME_RELAY_ARP         0x0808  // RFC1701
#define VINES_LOOPBACK          0x0BAE  // RFC1701
#define VINES_ECHO              0x0BAF  // RFC1701
#define TRILL                   0x22F3  // RFC6325
#define L2_IS_IS                0x22F4  // RFC6325
#define TRANS_ETHER_BRIDGING    0x6558  // RFC1701
#define RAW_FRAME_RELAY         0x6559  // RFC1701
#define CRONUS_VLN              0x8003  // RFC824
#define CRONUS_DIRECT           0x8004  // RFC824
#define RARP                    0x8035  // RFC903
#define C_TAG                   0x8100  // RFC7042
#define SNMP                    0x814C  // Joyce_K_Reynolds
#define IP_V6                   0x86DD  // RFC7042
#define TCP_IP_COMP             0x876B  // RFC1144,RFC1701
#define IP_AS                   0x876C  // RFC1701
#define SECURE_DATA             0x876D  // RFC1701
#define EPON                    0x8808  // RFC7042
#define PPP                     0x880B  // RFC7042
#define GSMP                    0x880C  // RFC7042
#define MPLS                    0x8847  // RFC5332
#define MPLS_UA_LABEL           0x8848  // RFC5332
#define MCAP                    0x8861  // RFC7042
#define PPPOE_DISCOVERY         0x8863  // RFC2516
#define PPPOE_SESSION           0x8864  // RFC2516
#define IEEE_802_1X             0x888E  // IEEE Std 802.1X
#define S_TAG                   0x88A8  // IEEE Std 802.1Q
#define IEEE_802x5              0x88B5  // IEEE Std 802
#define IEEE_802x6              0x88B6  // IEEE Std 802
#define IEEE_802x7              0x88B7  // IEEE Std 802
#define IEEE_802_11I            0x88C7  // IEEE Std 802.11i
#define LLDP                    0x88CC  // IEEE Std 802.1AB
#define IEEE_802_1AE            0x8800000   // IEEE Std 802.1AE
#define VLAN_TAG                0x880000000 // IEEE Std 802.1Q-2014
#define MVRP                    0x88F5  // IEEE Std 802.1Q
#define MMRP                    0x88F6  // IEEE Std 802.1Q
#define IEEE_802_11R            0x890D  // IEEE Std 802.11r
#define IEEE_802_21             0x8917  // IEEE Std 802.21
#define IEEE_802_1QBE           0x8929  // IEEE Std 802.1Qbe
#define FGL                     0x893B  // RFC7172
#define IEEE_802_1QBG           0x8940  // IEEE Std 802.1Qbg
#define TRILL_RBRIDGE           0x8946  // RFC7178
#define GEO_NETWORKING          0x8947  // IEEE ETSI EN 302 636-4-1
#define NSH                     0x894F  // RFC8300
#define LOWPAN                  0xA0ED  // RFC7973
#define GRE                     0xB7EA  // RFC8157
// #define RESERVED                0xFFFF  // RFC1701

struct ether_frame {
    u8 daddr[6];
    u8 saddr[6];
    u16 type;
} __attribute__((packed));

struct ip_v4_hdr {
    u8 ihl:4, version:4;
    u8 tos;
    u16 tot_len;
    u16 id;
    u16 flag_off;
    u8 ttl;
    u8 protocol;
    u16 check;
    u8 saddr[4];
    u8 daddr[4];
    u32 opt;
} __attribute__((packed));

struct arp_h {
    u16 hdw;
    u16 protocol;
    u8 hlen;
    u8 plen;
    u16 opr;
    u8 saddr[6];
    u8 sip[4];
    u8 target_addr[6];
    u8 target_ip[4];
} __attribute__((packed));

struct tcp_hdr {
    u16 sport;
    u16 dport;
    u32 seq_num;
    u32 ack_num;
    u8 off;
    u8 ctrl_flag;
    u16 window;
    u16 check;
    u16 urg_ptr;
    u32 opt;
} __attribute__((packed));

int gensock(char *);
//void analize(int, struct ether_frame *);
u16 hton16(u16 h);

#endif





