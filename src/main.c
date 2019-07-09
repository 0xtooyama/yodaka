#include <stdio.h>

#include <cmd.h>
#include <types.h>
#include <net.h>
#include <analyze.h>

int main(int argc, char **argv) {
    int rc;
    struct cmd_t cmd;
    rc = cmd_parse(argc, argv, &cmd);
    if (rc < 0) {
        fprintf(stderr, "Try 'yodaka help'.\n");
        return -1;
    }

    int sock = gensock(cmd.sif_name);
    if (sock > 0) {
        unsigned int size = 0;
        char buf[65535];
        int i = 0;
        while (1) {
            printf("%d\n", i);
            if ((size = read(sock, buf, sizeof buf)) <= 0) {
                perror("read");
            }
            // analyze(size, (struct ether_frame *)buf);
            analyze(size, buf);
            i++;
        }

        close(sock);
    }

    printf("%x\n", cmd.flag);
    printf("%s\n", cmd.sif_name);
}
/*
int main(int argc, char **argv) {
    int sock, size;
    char buf[4096];

    cmd_parse(argc, argv);

    sock = gensock("eth0");
    if (sock < 0) {
        fprintf(stderr, "gensock : error\n");
        return -1;
    }

    while (1) {
        size = read(sock, buf, sizeof buf );
        printf("%d\n", size);
        analize(size, (struct ether_frame *)buf);
    }
}
*/
