#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {AF_INET, htons(8080), inet_addr("127.0.0.1")};

    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    FILE *fp = fopen("file_to_send.txt", "rb");

    char buffer[1024];
    int bytes;
    while ((bytes = fread(buffer, sizeof(char), sizeof(buffer), fp)) > 0) {
        send(sock, buffer, bytes, 0);
    }
    fclose(fp);

    close(sock);
    return 0;
}