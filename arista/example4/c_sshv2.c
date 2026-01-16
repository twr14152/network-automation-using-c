#include <stdio.h>
#include <stdlib.h>

#define CMD_SIZE 512

static const char *routers[] = {
    "leaf1a",
    "leaf1b",
    "leaf2",
    NULL
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <missing_ssh_password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *password = argv[1];
    char command[CMD_SIZE];

    for (int i = 0; routers[i] != NULL; i++) {
        printf("Connecting to %s\n", routers[i]);

        int cmd_length = snprintf(
            command,
            CMD_SIZE,
            "sshpass -p '%s' ssh admin@%s < commands.txt",
            password,
            routers[i]
        );

        if (cmd_length < 0 || cmd_length >= CMD_SIZE) {
            fprintf(stderr, "Command buffer overflow for router %s\n", routers[i]);
            continue;
        }
 
        printf("Running command: %s\n", command);

        int ret = system(command);
        if (ret != 0) {
            fprintf(stderr, "SSH command failed for %s (code %d)\n", routers[i], ret);
        }
    }

    return EXIT_SUCCESS;
}

