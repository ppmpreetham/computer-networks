#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server_addr = {AF_INET, htons(8080), inet_addr("127.0.0.1")};

    char buffer[1024];
    socklen_t addr_len = sizeof(server_addr);

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&server_addr, addr_len);
        recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
        printf("Server: %s", buffer);
    }
    close(sock);
    return 0;
}