#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024
#define TIMEOUT_SEC 2

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(server_addr);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Error setting socket options");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i <= 10; i++) {
        snprintf(buffer, sizeof(buffer), "Packet %d", i);
        int acknowledged = 0;

        while (!acknowledged) {
            sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, addr_len);
            printf("Sent: %s\n", buffer);

            int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &addr_len);
            if (n > 0) {
                buffer[n] = '\0';
                printf("Received: %s\n", buffer);
                acknowledged = 1;
            } else {
                printf("Timeout, resending packet %d...\n", i);
            }
        }
    }

    close(sockfd);
    return 0;
}
