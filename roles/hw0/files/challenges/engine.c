#include <stdio.h>
#include "decrypt.h"

int main() {
  char flag[] = FLAG;
  decrypt(flag);
  printf("%s\n", flag);
}
