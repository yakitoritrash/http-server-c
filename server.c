#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>

int main() {
  int server_fd = socket(AF_INET, SOCK_STREAM, 0); 
  if (server_fd < 0) {
    perror("Socket creation failed.\n");
  }
  printf("Socket created.\n");
  
  struct sockaddr_in client_addr;

}
