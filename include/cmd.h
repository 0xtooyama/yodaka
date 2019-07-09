#include <stdio.h>

#include <net/if.h>
#include <types.h>

#ifndef YODAKA_CMD
#define YODAKA_CMD

#define n 

#define MODE_HELP       "help"
#define MODE_PLIST      "plist"
#define MODE_ANALYZE    "analyze"
#define MODE_SEND       "send"

#define MODE_F_ANALYZE  0x01
#define MODE_F_SEND     0x02

#define OPT_S   "-s"
#define OPT_D   "-d"
#define OPT_I   "-i"
#define OPT_O   "-o"
//#define OPT_P   "-p"

#define OPT_SIF         0x01    // -s
#define OPT_DIF         0x02    // -d
#define OPT_INFILE      0x04    // -i
#define OPT_OUTFILE     0x08    // -o
//#define OPT_ANALYZE_PROTOCOL    0x0F    // -p

struct cmd_t {
    u8 mode;
    u8 flag;
    char sif_name[IFNAMSIZ];
    char dif_name[IFNAMSIZ];
    char infile_name[256];
    char outfile_name[256];
};

int cmd_parse(int , char **, struct cmd_t *);

#endif




















