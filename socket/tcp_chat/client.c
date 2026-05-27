#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;

    char message[SIZE];
    char buffer[SIZE];

    /* Create socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    printf("Socket created successfully\n");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    /* Convert IP address */
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    /* Connect to server */
    if (connect(sock,
                (struct sockaddr *)&serv_addr,
                sizeof(serv_addr)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while (1)
    {
        /* Client message */
        printf("[Client]: ");
        fgets(message, SIZE, stdin);

        send(sock, message, strlen(message), 0);

        /* Exit check */
        if (strncmp(message, "exit", 4) == 0)
        {
            printf("Disconnected from server\n");
            break;
        }

        memset(buffer, 0, SIZE);

        /* Receive server reply */
        recv(sock, buffer, SIZE, 0);

        printf("[Server]: %s", buffer);

        /* Exit check */
        if (strncmp(buffer, "exit", 4) == 0)
        {
            printf("Server disconnected\n");
            break;
        }
    }

    close(sock);

    return 0;
}
