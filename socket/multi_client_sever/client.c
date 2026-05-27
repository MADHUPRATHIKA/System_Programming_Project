#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock;
    struct sockaddr_in serv_addr;

    char message[BUFFER_SIZE];

    /* Create socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    /* Configure server */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    inet_pton(AF_INET,
              "127.0.0.1",
              &serv_addr.sin_addr);

    /* Connect */
    if (connect(sock,
                (struct sockaddr *)&serv_addr,
                sizeof(serv_addr)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter Student Name and Roll Number:\n");

    fgets(message, BUFFER_SIZE, stdin);

    /* Send message */
    send(sock,
         message,
         strlen(message),
         0);

    printf("Data sent successfully\n");

    close(sock);

    return 0;
}
