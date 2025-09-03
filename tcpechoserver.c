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
  if (server_fd < 0) {
    errno;
  }
  struct sockaddr_in SOCK_ADDR;
  SOCK_ADDR.sin_family = AF_INET;
  SOCK_ADDR.sin_port = 8080;
  SOCK_ADDR.sin_addr = INADDR_ANY;

}
