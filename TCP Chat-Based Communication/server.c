#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {AF_INET, htons(8080), INADDR_ANY};

    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);
    int client_fd = accept(server_fd, NULL, NULL);

    char buffer[1024];
    while (1) {
        recv(client_fd, buffer, sizeof(buffer), 0);
        printf("Client: %s\n", buffer);
        fgets(buffer, sizeof(buffer), stdin);
        send(client_fd, buffer, strlen(buffer), 0);
    }
    close(client_fd);
    close(server_fd);
    return 0;
}