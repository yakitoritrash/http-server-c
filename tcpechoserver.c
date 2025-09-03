#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//socket - create an endpoint for communication - returns a file descriptor
//int socket(int domain, int type, int protocol);
//domain - AF_INET: IPv4 internet
//type - SOCK_STREAM (tcp?), fully duplex byte strems
//protocol - 0 - 
//a stream socket must be in a connected stae before any data may be sent or received on it.
//connection is done with connect(). 
//once connected data is transferred using read(), write() or variants of send(), recv()
//when session complete close()


int main() {
  //creating a socket
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  printf("Socket created.\n");
  if (server_fd < 0) {
    perror("Socket creation failed.\n");
  }
  //defining the address
  struct sockaddr_in SOCK_ADDR;
  SOCK_ADDR.sin_family = AF_INET;
  SOCK_ADDR.sin_port = htons(8080);
  SOCK_ADDR.sin_addr.s_addr = INADDR_ANY;

  //binding the address to teh socket
  if (bind(server_fd, (struct sockaddr *)&SOCK_ADDR, sizeof(SOCK_ADDR)) != 0) {
    perror("Bind failed\n");
  } 
  printf("Binded\n");

  int backlog = 5;
  if (listen(server_fd, backlog) != 0) {
    perror("Listen failed\n");
  }
  printf("Listening..\n");
  struct sockaddr CLIENT_ADDR;
  socklen_t client_addr_len = sizeof(CLIENT_ADDR);
  int client_fd = accept(server_fd, &CLIENT_ADDR, &client_addr_len); 
  char buffer[1024];
  ssize_t bytes_read = read(client_fd, buffer, sizeof(bytes_read));
  write(client_fd, buffer, sizeof(bytes_read));
  close(client_fd);
  close(server_fd);
}
