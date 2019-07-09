#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <net/ethernet.h>
#include <netpacket/packet.h>
#include <netinet/if_ether.h>

#include <types.h>
#include <net.h>

u16 hton16(u16 h) {
    u16 res = h >> 8;
    res += (h & 0x00FF) << 8;
    return res;
}

int gensock(char *device) {
    int sock, rc;
    struct ifreq req;
    struct sockaddr_ll sa;
    int ifindex;

    sock = socket(AF_PACKET, SOCK_RAW, hton16(ETH_P_ALL));
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    memset(&req, 0, sizeof req);
    strncpy(req.ifr_name, device, sizeof req.ifr_name - 1);

    rc = ioctl(sock, SIOCGIFINDEX, &req);
    if (rc < 0) {
        perror("ioctl ifindex");
        close(sock);
        return -1;
    }

    ifindex = req.ifr_ifindex;

    rc = ioctl(sock, SIOCGIFFLAGS, &req);
    if (rc < 0) {
        perror("ioctl ifflags");
        close(sock);
        return -1;
    }


    rc = ioctl(sock, SIOCSIFFLAGS, &req);
    if (rc < 0) {
        perror("ioctl promisc");
        close(sock);
        return -1;
    }

    sa.sll_family = AF_PACKET;
    sa.sll_protocol = hton16(ETH_P_ALL);
    sa.sll_ifindex = ifindex;

    rc = bind(sock, (struct sockaddr *)&sa, (socklen_t)sizeof sa); 
    if (rc < 0) {
        perror("bind");
        close(sock);
        return -1;
    }

    return sock;
}

