#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024

int main()
{
    int sockfd;
    char message[SIZE] = "Networking Lab";
    char buffer[SIZE];

    struct sockaddr_in server_addr;
    socklen_t addr_size;

    /* Create UDP socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    printf("UDP Socket created successfully\n");

    /* Configure server */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    addr_size = sizeof(server_addr);

    /* Send message */
    sendto(sockfd,
           message,
           strlen(message) + 1,
           0,
           (struct sockaddr *)&server_addr,
           addr_size);

    printf("Sent: %s\n", message);

    /* Receive uppercase message */
    recvfrom(sockfd,
             buffer,
             SIZE,
             0,
             (struct sockaddr *)&server_addr,
             &addr_size);

    printf("Received: %s\n", buffer);

    close(sockfd);

    return 0;
}
