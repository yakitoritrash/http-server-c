#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <string.h>
#include <netinet/ip.h>
#include <unistd.h>

int main() {
  int server_fd = socket(AF_INET, SOCK_STREAM, 0); 
  if (server_fd < 0) {
    perror("Socket creation failed.\n");
    return 1;
  }
  printf("Socket created.\n");

  struct sockaddr_in client_addr;
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

  } 
}
