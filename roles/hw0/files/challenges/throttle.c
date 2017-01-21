#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int sleep = 0, quit = 0, sigint = 0; 

void handler(int signal) {
  switch (signal) {
  case SIGSTOP:
    sleep = 1;
    printf("slept...\n");
    break;
  case SIGINT:
    sigint = 1;
    printf("interrupted...\n");
    break;
  case SIGQUIT:
    quit = 1;
    printf("quited...\n");
    break;
  }

  if (sleep == 0 || quit == 0 || sigint == 0) {
    printf("Give me more signam :D\n");
  } else {
    char flag[] = FLAG;
    decrypt(flag);
    printf("%s\n", flag);
  }
  
}


int main() {
  signal(SIGHUP, handler); 
  signal(SIGINT, handler);
  signal(SIGQUIT, handler);

  while (true) {
    printf("fly fly fly\n");
  }
  
}
