//#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int imput;
struct fileWrite {
  char copyFile[1000];
  char fileName[1000];
} fp;

struct listFile {
  int number;
  char character[1000];
} list;

FILE *file;
FILE *copiedFile;

void flush_in() {  // clean the buffer
  int ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
  }
};

void write() {
  printf("File to be created\n");
  scanf("%s", fp.fileName);
  file = fopen(fp.fileName, "w");  // if not exist, will create

  if (file != NULL)  // if anything is wrong, will alarm
    printf("\n%s file was opened successfully\n", fp.fileName);
  else {
    printf("\n\nError: The %s file was not opened\n", fp.fileName);
    system("pause");
    exit(0);
  }
  printf("How many items do you want to add?\n");
  scanf("%d", &list.number);

  for (int i = 1; i < list.number + 1; i++) {
    printf("Item - %d\n", i);
    scanf("%s", list.character);  // scan the item for add in the file
    fprintf(file, "%d - %s\n", i, list.character);  // print into the file
  }
  fclose(file);  // close the file
};

void read() {
  printf("File to be read\n");
  scanf("%s", fp.fileName);
  file = fopen(fp.fileName, "r");  // will open the file *.txt

  if (file != NULL)  // if anything is wrong, will alarm
    printf("\n%s file was opened successfully\n", fp.fileName);
  else {
    printf("\n\nError: The %s file was not opened\n", fp.fileName);
    system("pause");
    exit(0);
  }
  char word[100];  // char to storage the word
  while (fgets(word, 100, file) !=
         NULL)  // fgets will capture the word to repeat while !n NULL
  {
    printf("%s", word);  // print the read word while looping
  }
  fclose(file);  // close the file
};

void alter() {
  printf("File to be alter\n");
  scanf("%s", fp.fileName);
  file = fopen(fp.fileName, "a");  // will open the file *.txt

  if (file != NULL)  // if anything is wrong, will alarm
    printf("\n%s file was opened successfully\n", fp.fileName);
  else {
    printf("\n\nError: The %s file was not opened\n", fp.fileName);
    system("pause");
    exit(0);
  }
  printf("How many items do you want to add?\n");
  scanf("%d", &list.number);
  for (int i = 1; i < list.number + 1; i++) {
    printf("Item - %d\n", i);
    scanf("%s", list.character);  // scan the item for add in the file
    fprintf(file, "%d - %s\n", i, list.character);  // print into the file
  }
  fclose(file);  // close the file
};

void copy() {
  printf("File to be copy\n");
  scanf("%s", fp.fileName);
  file = fopen(fp.fileName, "r");

  if (file != NULL)  // if anything is wrong, will alarm
    printf("\n%s file was opened successfully\n", fp.fileName);
  else {
    printf("\n\nError: The %s file was not opened\n", fp.fileName);
    system("pause");
    exit(0);
  }

  printf("File name to be copied\n");
  scanf("%s", fp.copyFile);
  copiedFile = fopen(fp.copyFile, "w");
  while (fgets(list.character, 1000, file) != NULL) {
    fputs(list.character, copiedFile);
  }
  fclose(file);
  fclose(copiedFile);
};

int main(void) {
  setlocale(LC_ALL, "pt_BR.UTF-8");  // set language to pt-BR
  do {
    printf("\nSelect one of the options below");
    printf("\n(1) to create a list");
    printf("\n(2) to read an existing list");
    printf("\n(3) to edit an existing list");
    printf("\n(4) to copy an existing list");
    printf("\n(5) to exit the program\n");
    scanf("%d", &imput);  // scan the type valye
    switch (imput) {
      case 1:                              //
        setlocale(LC_ALL, "pt_BR.UTF-8");  // set language to pt-BR
        write();                           // execute the function write
        break;
      case 2:
        setlocale(LC_ALL, "pt_BR.UTF-8");  // set language to pt-BR
        read();                            // execute the function read
        break;
      case 3:
        setlocale(LC_ALL, "pt_BR.UTF-8");  // set language to pt-BR
        alter();                           // execute the function alter
        break;
      case 4:
        setlocale(LC_ALL, "pt_BR.UTF-8");
        copy();
        break;
      case 5:
        setlocale(LC_ALL, "pt_BR.UTF-8");  // set language to pt-BR
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
  system("pause");
  return 0;
}