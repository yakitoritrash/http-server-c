#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <string.h>
#include <netinet/ip.h>
#include <unistd.h>

int main() {
  int client_addr_len;
  struct sockaddr_in client_addr;
  char server_response[] = "HTTP/1.1 200 OK\r\n\r\n";
  char server_denial[] = "HTTP/1.1 404 Not found\r\n\r\n";
  char client_request[129];

  int server_fd = socket(AF_INET, SOCK_STREAM, 0); 
  if (server_fd < 0) {
    perror("Socket creation failed.\n");
    return 1;
  }
  printf("Socket created.\n");

  int reuse = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
    printf("SO_REUSEADDR failed: %s \n", strerror(errno));
    return 1;
  }

  struct sockaddr_in serv_addr = {
    .sin_family = AF_INET , 
    .sin_port = htons(6969),
    .sin_addr = { htonl(INADDR_ANY) },
  };

  if (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) != 0) {
    printf("Bind failed: %s \n", strerror(errno));
    return 1;
  }
  printf("Bind successful\n");
  
  int backlog = 5; 
  if (listen(server_fd, backlog) != 0) {
    printf("Listen failed.\n");
    return 1;
  }

  while(1) {
    printf("Waiting for a client to connect...\n");
    client_addr_len = sizeof(client_addr);
    int fd = accept(server_fd, (struct sockaddr *) &client_addr, (socklen_t *)&client_addr_len);
    printf("Client accepted\n");
    read(fd, client_request, 128);

  }

  close(server_fd);
  return 0;
}
