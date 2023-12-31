#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#define OPCODE_RRQ		1
#define OPCODE_WRQ		2
#define OPCODE_DATA		3
#define OPCODE_ACK		4
#define OPCODE_ERROR	5

#define BUFFER_SIZE		516 // car il faut 2 octets pour le opcode + 2 octects pour le block id + 512 octets pour les data

void getFile(char *fileName, struct sockaddr *sock_addr, int sockfd) {

    int requestLength = (int)(2 + strlen(fileName) + 1 + 5 + 1);
    char  buffer[BUFFER_SIZE];
    int sendSize;
    int recvSize;
    char opcode;
    socklen_t addrSize;
    unsigned short blockId; //unsigned short car 2 octets
    unsigned short blockCounter = 0;
    FILE  *fileOut;

    struct sockaddr sock_in_addr;

    buffer[0] = 0;
    buffer[1] = OPCODE_RRQ;
    strcpy(&buffer[2], fileName);
    strcpy(&buffer[2 + strlen(fileName) + 1], "octet");


    if ((fileOut = fopen(fileName, "w+")) == NULL) {
        printf("Error : unable to open file %s\n", fileName);
        return;
    }


    sendSize = sendto(sockfd, buffer, requestLength, 0, sock_addr, sizeof(struct sockaddr));
    if (sendSize == -1 || sendSize != requestLength) {
        printf("error while sendto: %d\n", sendSize);
        return;
    }

    while(1) {

        addrSize = sizeof(struct sockaddr);
        recvSize = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, &sock_in_addr, &addrSize);
        if (recvSize == -1) {
            printf("error while recvfrom: %d\n", recvSize);
        }
        opcode = buffer[1];
        if(opcode == OPCODE_ERROR) {
            printf("error opcode %s\n", &buffer[4]);
            return;
        }

        blockId = ((unsigned short)buffer[2] << 8) | (unsigned short)buffer[3];

        requestLength = 4;//On passe la taille en 2

        buffer[0] = 0;
        buffer[1] = OPCODE_ACK;
        sendSize = sendto(sockfd, buffer, requestLength, 0, &sock_in_addr, sizeof(struct sockaddr));

        printf("received block id %d : %d bytes\n", blockId, recvSize-4);
        if ((recvSize - 4 > 0)  &&  (blockId > blockCounter)) {
            fwrite(&buffer[4], 1, recvSize - 4, fileOut);
            blockCounter++;
        }

        if(recvSize - 4 < 512) {
            fclose(fileOut);
            return;
        }
    }
}


int main(int argc, char *args[]) {
    int s;
    struct addrinfo hints;
    struct addrinfo *res;
    char PORT[10];
    char ipbuf[INET_ADDRSTRLEN];
    int sockfd;

    memset(&hints,0,sizeof(struct addrinfo));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;

    if(argc != 3) {
        printf("Usage: getftp <host> <local file>\n");
        return 0;
    }
    printf("host: %s, file: %s\n",args[1], args[2]);
    sprintf(PORT,"%d",69);


    if ((s = getaddrinfo(args[1], PORT, &hints, &res)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }
    inet_ntop(AF_INET, &((struct sockaddr_in *)res->ai_addr)->sin_addr, ipbuf, sizeof(ipbuf));
    printf("connecting to server : %s \n", ipbuf);
    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
        printf("error while creating socket\n");
    }

    getFile(args[2], res->ai_addr, sockfd);

    close(sockfd);
    freeaddrinfo(res);

}
