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

    char buffer[BUFFER_SIZE];

    FILE *fp;

    //Create socket 
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    printf("Socket created successfully\n");


    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    inet_pton(AF_INET,
              "127.0.0.1",
              &serv_addr.sin_addr);

    if (connect(sock,
                (struct sockaddr *)&serv_addr,
                sizeof(serv_addr)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        perror("File open failed");
        exit(EXIT_FAILURE);
    }

    int bytes_read;

    
    while ((bytes_read =
            fread(buffer,
                  sizeof(char),
                  BUFFER_SIZE,
                  fp)) > 0)
    {
        send(sock,
             buffer,
             bytes_read,
             0);
    }

    printf("File Transfer Successful\n");

    fclose(fp);

    close(sock);

    return 0;
}
