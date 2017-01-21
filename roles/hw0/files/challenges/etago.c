#include <stdio.h>
#include "decrypt.h"

int main() {
  for (int i = 0; i < 1000; ++i) {
    printf("ffff\n");
  }

  for (int i = 0; i < 1000; ++i) {
    printf("llll\n");
  }

  for (int i = 0; i < 1000; ++i) {
    printf("aaaa\n");
  }

  for (int i = 0; i < 1000; ++i) {
    printf("gggg\n");
  }

  for (int i = 0; i < 1000; ++i) {
    printf("\n");
  }

  char flag[] = FLAG;
  decrypt(flag);
  printf("%s\n", flag);

  for (int i = 0; i < 1000; ++i) {
    printf("\n");
  }
  
  for (int i = 0; i < 100000; ++i) {
    printf("etagoggogogogogogogogogogogogogogogogogogogogogogogogogo\n");
  }

  printf(":D\n");

  return 0;
}
