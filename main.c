#include <stdio.h>

void logo(){

  printf("   _____                                  _       _\n");
  printf("  / ____|                                (_)     | |\n");
  printf(" | |     __ _  ___  ___  __ _ _ __    ___ _ _ __ | |__   ___ _ __\n");
  printf(" | |    / _` |/ _ \\/ __|/ _` | '__|  / __| | '_ \\| '_ \\ / _ \\ '__|\n");
  printf(" | |___| (_| |  __/\\__ \\ (_| | |    | (__| | |_) | | | |  __/ |   \n");
  printf("  \\_____\\__,_|\\___||___/\\__,_|_|     \\___|_| .__/|_| |_|\\___|_|   \n");
  printf("                                           | |                    \n");
  printf("                                           |_|                    \n");
  printf("                                                 Made by Black Ghost");

}


void encrypt(int key){

  FILE *inputFile, *outputFile;

  inputFile = fopen("input.txt", "r");
  outputFile = fopen("encrypted.txt", "w");

  if (inputFile == NULL) {
      printf("Make input.txt !!!\n");
      return;
  }


  char c;
  while ((c = fgetc(inputFile)) != EOF) {
      if (c >= 'a' && c <= 'z') {
        c = 'a' + (c - 'a' + key) % 26;

      } else if (c >= 'A' && c <= 'Z') {
        c = 'A' + (c - 'A' + key) % 26;

      }

      fputc(c, outputFile);
  }

  fclose(inputFile);
  fclose(outputFile);

}

// ====================================================

void decrypt(int key){
  FILE *inputFile, *outputFile;

  inputFile = fopen("input.txt", "r");
  outputFile = fopen("decrypted.txt", "w");

  if (inputFile == NULL) {
      printf("Make input.txt !!!\n");
      return;
  }

  char c;
  while ((c = fgetc(inputFile)) != EOF) {
      if (c >= 'a' && c <= 'z') {
        c = 'a' + (c - 'a' - key + 26) % 26;

      } else if (c >= 'A' && c <= 'Z') {
        c = 'A' + (c - 'A' - key + 26) % 26;
      }

      fputc(c, outputFile);
  }

  fclose(inputFile);
  fclose(outputFile);
}

// ====================================================

int main() {

    logo();

    int start = 1;
    int value;
    int key;

    while(start){
      printf("\n| MENU |\n");
      printf(" 1 -> Encrypt\n");
      printf(" 2 -> Decrypt\n");
      printf(" 0 -> Exit\n\n");

      printf("Enter value : ");
      scanf("%d", &value);

      switch (value) {
        case 1:
          printf(" Key for encrypt = ");
          scanf("%d", &key);
          encrypt(key);
          break;

        case 2:
          printf(" Key for decrypt = ");
          scanf("%d", &key);
          decrypt(key);
          break;

        case 0:
          start = 0;
          break;

        default:
          printf("Enter 1 , 2 or 0 !!!\n");
          break;
      }
    }

    return 0;
}
