#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>

int main() {
  char pwd[1024];
  if (getcwd(pwd, sizeof(pwd)) == NULL) {
    printf("Error occur, please contact us. vegetable@csie.ntu.edu.tw\n");
    return 1;
  }
  char* base = basename(pwd);

  if (strcmp("toolbox", base) != 0) {
    printf("You need to get into toolbox.\n");
    return -1;
  }

  if (access("obstacle", F_OK) != -1) {
    printf("You need to remove the obstacle.\n");
    return -1;
  }

  if (access("crisis", F_OK) != -1) {
    printf("You need to rename the crisis to chance.\n");
    return -1;
  }

  char chance[] = "\x1e\xe4\xf6\xa5\x2d\xc2\x43\xe3\xdd\x4b\x12\x88\xc5\xf6\x28\xec\xe3\x4e\xc9\x17\xa5\x8\x4\x54\xda\xb8\xfc\xc5\xc\x23\x6c\xec\x8c\x29\x42\xf0\xd6\x17\x4c\x66\x27\x6b\x31\xea\x10\xd5\x7d\x3d\xc9\x6d\x1a\xf8\x4e\x4b\x28\x40\x9e\xa9\xb7\x18\x73\xdf\x72\xf8\x64\x78\x6a\x3b\xc2\xc7\x1\x42\xc8\xf0\x89\xb1\xe8\x62\x5b\x9\x1a\xcd\xa3\x98\xbc\x85\x79\xb0\x9c\xb0\xd8\x18\xe0\xad\xf6\xcd\x38\xb5\x5b\x4e";
  
  FILE* f = fopen("chance", "r");
  if (f == NULL) {
    printf("You need to rename the crisis to chance.\n");
    return -1;
  }

  char content[200];
  fread(content, 1, strlen(chance), f);
  if (strncmp(content, chance, strlen(chance)) != 0) {
    printf("You need to rename the crisis to chance.\n");
    return -1;
  }

  char flag[] = FLAG;
  decrypt(flag);
  printf("%s\n", flag);
  
  return 0;
}
