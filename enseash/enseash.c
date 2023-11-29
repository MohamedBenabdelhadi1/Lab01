#include <unistd.h>
#include <string.h>
#define WELCOME_MSG "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define PROMPT "enseash%"

int main() {
    char command[100];
    /* Print the welcome message */
    write(1, WELCOME_MSG, strlen(WELCOME_MSG));
    /* Loop indefinitely to accept commands */
    while (1) {
        /* Print the shell prompt */
        write(1, PROMPT, strlen(PROMPT));
        /* Read the command from the user */
        int bytes_read = read(0, command, 100);
        command[bytes_read-1] = 0;
    }
    return 0;
}
