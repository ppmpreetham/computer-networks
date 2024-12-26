#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {AF_INET, htons(8080), inet_addr("127.0.0.1")};

    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    char buffer[1024];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        send(sock, buffer, strlen(buffer), 0);
        recv(sock, buffer, sizeof(buffer), 0);
        printf("Server: %s\n", buffer);
    }
    close(sock);
    return 0;
}