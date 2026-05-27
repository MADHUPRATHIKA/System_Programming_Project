#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024

int main()
{
    int sockfd;
    char buffer[SIZE];

    struct sockaddr_in server_addr, client_addr;
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
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    /* Bind socket */
    if (bind(sockfd,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is waiting for message...\n");

    addr_size = sizeof(client_addr);

    /* Receive message */
    recvfrom(sockfd,
             buffer,
             SIZE,
             0,
             (struct sockaddr *)&client_addr,
             &addr_size);

    printf("Received from client: %s\n", buffer);

    /* Convert to uppercase */
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        buffer[i] = toupper(buffer[i]);
    }

    /* Send back to client */
    sendto(sockfd,
           buffer,
           strlen(buffer) + 1,
           0,
           (struct sockaddr *)&client_addr,
           addr_size);

    printf("Uppercase message sent back\n");

    close(sockfd);

    return 0;
}
