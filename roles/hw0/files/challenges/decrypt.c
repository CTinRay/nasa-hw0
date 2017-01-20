char key[] = KEY;

void decrypt(char*cipher){
  int ki = 0;
  while (*cipher != '\0') {
    *cipher = (*cipher - key[ki]) + 256;
    cipher += 1;
    ki += 1;
  }
}
