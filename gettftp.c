#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
// Define error messages
#define NOT_ENOUGH_ARGS "Not enough argument\n"
#define TOO_MUCH_ARGUMENTS "too much arguments\n"

int terminal = STDOUT_FILENO;

struct stat sbFileInput;
// Function to check the format of command-line arguments
void checkFormat(int argc, char ** argv){
    // Check if the number of arguments is sup to 4
    if (argc>4){
        write(terminal,TOO_MUCH_ARGUMENTS,sizeof(TOO_MUCH_ARGUMENTS));
        close(terminal);
        exit(EXIT_FAILURE);
    }
    // Check if the number of arguments is inf to 4
    if (argc<4){
        write(terminal,NOT_ENOUGH_ARGS,sizeof(NOT_ENOUGH_ARGS));
        close(terminal);
        exit(EXIT_FAILURE);
    }
}

int main(int argc,char ** argv){

    checkFormat(argc,argv);
// Call the checkFormat function to validate the arguments
    close(terminal);
    return 0;
}