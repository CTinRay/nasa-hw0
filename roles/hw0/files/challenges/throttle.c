#define _XOPEN_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include "decrypt.h"

int sigsleep = 0, sigquit = 0, sigint = 0; 

void handler(int sig) {
  printf("\n\n\n\n\n\n");

  switch (sig) {
  case SIGTSTP:
    sigsleep = 1;
    printf("slept...\n");
    break;
  case SIGINT:
    sigint = 1;
    printf("interrupted...\n");
    break;
  case SIGQUIT:
    sigquit = 1;
    printf("quited...\n");
    break;
  }

  if (sigsleep == 0 || sigquit == 0 || sigint == 0) {
    printf("Give me more signal :D\n");
  } else {
    char flag[] = FLAG;
    decrypt(flag);
    printf("%s\n", flag);
    exit(0);
  }
  sleep(3);
}


int main() {
  signal(SIGTSTP, handler); 
  signal(SIGINT, handler);
  signal(SIGQUIT, handler);
  struct sigaction sa;
  sa.sa_handler = handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;

  int res = 1;
  res *= sigaction(SIGINT, &sa, NULL);
  res *= sigaction(SIGQUIT, &sa, NULL);
  res *= sigaction(SIGSTOP, &sa, NULL);
    
  if (sigaction(SIGINT, &sa, NULL) < 0) {
    printf("sigaction fail, please contact us vegetable@csie.ntu.edu.tw");
    return -1;
  }
  
  while (1) {
    printf("fly fly fly\n");
  }
  
}
