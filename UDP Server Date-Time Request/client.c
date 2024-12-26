#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server_addr = {AF_INET, htons(8080), inet_addr("127.0.0.1")};

    char buffer[1024];
    sendto(sock, "Time request", strlen("Time request"), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
    printf("Server time: %s", buffer);

    close(sock);
    return 0;
}