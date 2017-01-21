char key[] = KEY;

void decrypt(char*cipher){
  int ki = 0;
  while (*cipher != '\0') {
    *cipher = (*cipher - key[ki]);
    cipher += 1;
    ki += 1;
  }
}
