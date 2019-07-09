#include <net/if.h>
#include <stdio.h>
#include <string.h>

#include <types.h>
#include <cmd.h>

int cmd_parse(int argc, char **argv, struct cmd_t *cmd) {
    cmd->mode = 0;
    int i = 0;

    if (argc == 1 || !strcmp(argv[1], MODE_HELP)) {
        // call help
        return 0;
    }

    if (!strcmp(argv[1], MODE_ANALYZE)) {
        cmd->mode = MODE_F_ANALYZE;
    } else if (!strcmp(argv[1], MODE_SEND)) {
        cmd->mode = MODE_F_SEND;
    } else {
        return -1;
    }

    argc--;
    argv++;

    cmd->flag = 0;
    for (--argc, ++argv; *argv; argv++, argc--) {
        if (!strcmp(*argv, OPT_S)) {
            // -s
            if (--argc && *(++argv)[0] != '-') {
                strncpy(cmd->sif_name, *argv, sizeof cmd->sif_name - 1);
                cmd->flag |= OPT_SIF;
            } else return -1;
        } else if (!strcmp(*argv, OPT_D)) {
            // -d
            if (--argc && *(++argv)[0] != '-') {
                strncpy(cmd->dif_name, *argv, sizeof cmd->dif_name - 1);
                cmd->flag |= OPT_DIF;
            } else return -1;
        } else if  (!strcmp(*argv, OPT_I)) {
            // -i
            if (--argc && *(++argv)[0] != '-') {
                strncpy(cmd->infile_name, *argv, sizeof cmd->infile_name - 1);
                cmd->flag |= OPT_INFILE;
            } else return -1;
        } else if (!strcmp(*argv, OPT_O)) {
            // -o
            if (--argc && *(++argv)[0] != '-') {
                strncpy(cmd->outfile_name, *argv, sizeof cmd->outfile_name - 1);
                cmd->flag |= OPT_OUTFILE;
            } else return -1;
        } else return -1;
    }
}

