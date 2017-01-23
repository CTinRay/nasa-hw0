#define _D_BSD_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/select.h>


void bind_port(int socket, int port){
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = INADDR_ANY;
    if( bind( socket, (struct sockaddr *)&sa, sizeof(struct sockaddr_in) ) < 0 ){
        perror("Can not bind port!\n");
        exit(-1);
    }
#ifdef DEBUG
    fprintf( stderr, "Bind %d to port %d\n", socket, port );
#endif
};

struct sockaddr_in fill_sockaddr(int port, char*ip){
    struct sockaddr_in sa;
    memset( &sa, 0, sizeof(sa) );
    sa.sin_family = AF_INET;
    sa.sin_port = port;
    if( inet_aton( ip, &sa.sin_addr ) == 0 ){
        perror( "IP is invalid!\n" );
        exit(-1);
    }
    return sa;
};

int main () {
  system("1s -al ./top-secret-base64-encoded-sha1sum-1413d9ae974b265cae3a8575128658ee4901b53f");
  int fdsock = socket(AF_INET, SOCK_STREAM, 0);
  bind_port(fdsock, 9487);
  fd_set watch_fdset;
  listen(fdsock,5);
  while (1) {
    accept(fdsock, NULL, NULL);
  }
}
