/*
AUThOR: Faber Bernardo júnior & Igor Silva Vieira
DATA: 13/03/2022
PROGRAM SYNOPSIS: make a shopping list, just using the terminal
INPUT DATA: the struct listFile
OUTPUT DATA: the struct fileWrite
*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char copyFile[100];
  char fileName[100];
} fileWrite;

typedef struct {
  int number;
  char character[100];
  int amount;
} listFile;

fileWrite filePrint;
listFile list;
FILE* mainFile;

FILE* fileOpen(char* name, char* mode) {  // function for open the mainFile
  FILE* test = fopen(name, mode);         // fopen manipulate the FILE pointer
  if (test == NULL) {                     // test if it doesn't open, will alarm
    printf("\n\nError: The %s mainFile was not opened\n", filePrint.fileName);
    system("pause");  // it only works on windows
    exit(0);
  }
  return test;
};

void create() {
  char numberList[100];
  char compare[100];
  list.number = 0;

  while (list.number == 0) {
    printf("How many items do you want to add?\n");
    scanf("%s", numberList);

    list.number =
        atoi(numberList);  // This function returns the converted integral
                           // number as an int value. If no valid conversion
                           // could be performed, it returns zero.
    if (list.amount == 0) {
      printf("Please enter a number!\n");
    }
  }

  for (int i = 1; i < list.number + 1; i++) {
    list.amount = 0;

    printf("\nItem - %d - ", i);
    scanf("%s", list.character);  // scan the item for add in the mainFile

    while (list.amount == 0) {
      printf("amount / %s - ", list.character);
      scanf("%s", compare);  // scan the item for add in the mainFile
      list.amount =
          atoi(compare);  // This function returns the converted integral number
                          // as an int value. If no valid conversion could be
                          // performed, it returns zero.
      if (list.amount == 0) {
        printf("Please enter a number!\n");
      }
    }

    fprintf(mainFile, "- %s / amount: %d\n", list.character,
            list.amount);  // print into the mainFile can be replaced by fputs
  }
};

void write() {
  printf("File to be created\n");
  scanf("%s", filePrint.fileName);

  mainFile =
      fileOpen(filePrint.fileName, "w");  // if not exist, will create for write

  create();
  fclose(mainFile);  // close the mainFile
};

void read() {
  char word[100];  // char to storage the word

  printf("File to be read\n");
  scanf("%s", filePrint.fileName);

  mainFile = fileOpen(filePrint.fileName,
                      "r");  // will open the mainFile *.txt for read

  while (fgets(word, 100, mainFile) !=
         NULL)  // fgets will get the entire string of file while != NULL
  {
    printf("%s", word);  // print the read word while looping
  }

  fclose(mainFile);  // close the mainFile
};

void alter() {
  printf("File to be alter\n");
  scanf("%s", filePrint.fileName);

  mainFile = fileOpen(filePrint.fileName,
                      "a");  // will open the mainFile *.txt for alter

  create();
  fclose(mainFile);  // close the mainFile
};

void copy() {
  FILE* copiedFile;

  printf("File to be copy\n");
  scanf("%s", filePrint.fileName);

  mainFile = fileOpen(filePrint.fileName,
                      "r");  // will open the mainFile *.txt for read

  printf("File name to be copied\n");
  scanf("%s", filePrint.copyFile);

  copiedFile = fopen(filePrint.copyFile,
                     "w");  // will open the copiedFile *.txt for  write

  while (fgets(list.character, 100, mainFile) !=
         NULL) {  // fgets will get the entire string of file while != NULL
    fputs(list.character, copiedFile);  // fputs will put the string of
                                        // list.character in the copiedFile
  }

  fclose(mainFile);    // close the mainFile
  fclose(copiedFile);  // close the copiedFile
};

int main(void) {
  int imput;

  do {
    printf("\nSelect one of the options below");
    printf("\n(1) to create a list");
    printf("\n(2) to read an existing list");
    printf("\n(3) to edit an existing list");
    printf("\n(4) to copy an existing list");
    printf("\n(5) to exit the program\n");
    scanf("%d", &imput);  // scan the type value

    switch (imput) {
      case 1:
        write();  // The function write, create the shopping list file
        break;

      case 2:
        read();  // The function read, show the file datas in the terminal
        break;

      case 3:
        alter();  // The function alter, just imput more datas into the file
        break;

      case 4:
        copy();  // The function copy, create a copy of the file and save with a
                 // another name
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
