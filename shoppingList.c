//#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fileWrite {
  char copyFile[100];
  char fileName[100];
} fp;

struct listFile {
  int number;
  char character[100];
  int amount;
} list;

FILE* mainFile;

FILE* fileOpen(char* name, char* mode) {  // function for open the mainFile
  FILE* test = fopen(name, mode);
  if (test == NULL) {  // test if it doesn't open, will alarm
    printf("\n\nError: The %s mainFile was not opened\n", fp.fileName);
    system("pause");  // it only works on windows
    exit(0);
  }
  return test;
};

void create() {
  printf("How many items do you want to add?\n");
  scanf("%d", &list.number);

  for (int i = 1; i < list.number + 1; i++) {
    printf("Item - %d\n", i);
    scanf("%s", list.character);  // scan the item for add in the mainFile
    printf("Amount - %s\n", list.character);
    scanf("%d", &list.amount);  // scan the item for add in the mainFile
    fprintf(mainFile, "%d - %s - %d\n", i, list.character,
            list.amount);  // print into the mainFile
  }
};

void write() {
  printf("File to be created\n");
  scanf("%s", fp.fileName);
  mainFile = fileOpen(fp.fileName, "w");  // if not exist, will create

  create();
  fclose(mainFile);  // close the mainFile
};

void read() {
  printf("File to be read\n");
  scanf("%s", fp.fileName);
  mainFile = fileOpen(fp.fileName, "r");  // will open the mainFile *.txt

  char word[100];  // char to storage the word
  while (fgets(word, 100, mainFile) !=
         NULL)  // fgets will capture the word to repeat while != NULL
  {
    printf("%s", word);  // print the read word while looping
  }

  fclose(mainFile);  // close the mainFile
};

void alter() {
  printf("File to be alter\n");
  scanf("%s", fp.fileName);
  mainFile = fileOpen(fp.fileName, "a");  // will open the mainFile *.txt

  create();
  fclose(mainFile);  // close the mainFile
};

void copy() {
  FILE* copiedFile;
  printf("File to be copy\n");
  scanf("%s", fp.fileName);
  mainFile = fileOpen(fp.fileName, "r");

  printf("File name to be copied\n");
  scanf("%s", fp.copyFile);
  copiedFile = fopen(fp.copyFile, "w");

  while (fgets(list.character, 100, mainFile) != NULL) {
    fputs(list.character, copiedFile);
  }

  fclose(mainFile);    // close the mainFile
  fclose(copiedFile);  // close the copiedFile
};

int main(void) {
  setlocale(LC_ALL, "pt_BR.UTF-8");  // set language to pt-BR
  int imput;
  do {
    printf("\nSelect one of the options below");
    printf("\n(1) to create a list");
    printf("\n(2) to read an existing list");
    printf("\n(3) to edit an existing list");
    printf("\n(4) to copy an existing list");
    printf("\n(5) to exit the program\n");
    scanf("%d", &imput);  // scan the type valye
    switch (imput) {
      case 1:
        write();  // execute the function write
        break;
      case 2:
        read();  // execute the function read
        break;
      case 3:
        alter();  // execute the function alter
        break;
      case 4:
        copy();  // execute the function copy
        break;
      case 5:
        printf("\n\nFinish program!\n\n");
        return 0;
        break;

      default:
        printf("Invalid value\n");
        printf("Error!\n");
        printf("Finish program!\n ");
        break;
    }

  } while (imput <= 4);

  printf("\n");
  system("pause");  // it only works on windows
  return 0;
}