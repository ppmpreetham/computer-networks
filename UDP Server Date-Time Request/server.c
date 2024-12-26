#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server_addr = {AF_INET, htons(8080), INADDR_ANY};
    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[1024];

    while (1) {
        recvfrom(server_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &addr_len);
        time_t current_time = time(NULL);
        snprintf(buffer, sizeof(buffer), "%s", ctime(&current_time));
        sendto(server_fd, buffer, strlen(buffer), 0, (struct sockaddr*)&client_addr, addr_len);
    }
    close(server_fd);
    return 0;
}   