#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {AF_INET, htons(8080), INADDR_ANY};

    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);
    int client_fd = accept(server_fd, NULL, NULL);

    time_t current_time = time(NULL);
    char *time_str = ctime(&current_time);
    send(client_fd, time_str, strlen(time_str), 0);

    close(client_fd);
    close(server_fd);
    return 0;
}