#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char buffer[BUFFER_SIZE];

    FILE *fp;

    /* Create socket */
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    printf("Socket created successfully\n");

    /* Configure server */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    /* Bind */
    if (bind(server_fd,
             (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    /* Listen */
    listen(server_fd, 3);

    printf("Waiting for client...\n");

    /* Accept connection */
    new_socket = accept(server_fd,
                        (struct sockaddr *)&address,
                        (socklen_t *)&addrlen);

    if (new_socket < 0)
    {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected\n");

    /* Open output file */
    fp = fopen("received.txt", "w");

    if (fp == NULL)
    {
        perror("File open failed");
        exit(EXIT_FAILURE);
    }

    int bytes_received;

    /* Receive file data */
    while ((bytes_received =
            recv(new_socket,
                 buffer,
                 BUFFER_SIZE,
                 0)) > 0)
    {
        fwrite(buffer,
               sizeof(char),
               bytes_received,
               fp);
    }

    printf("File Transfer Successful\n");

    fclose(fp);

    close(new_socket);
    close(server_fd);

    return 0;
}
