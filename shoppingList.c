/*
AUThOR: Faber Bernardo júnior & Igor Silva Vieira
DATA: 13/03/2022
PROGRAM SYNOPSIS: make a shopping list, just using the terminal
INPUT DATA: the struct listFile
OUTPUT DATA: the struct fileCreate
*/

#include <stdio.h>
#include <stdlib.h>

#define CHAR_MAX 100

typedef struct {
  char fileCopy[CHAR_MAX];
  char fileName[CHAR_MAX];
} fileCreate;

typedef struct {
  int index;
  char character[CHAR_MAX];
  int amount;
} listFile;

fileCreate file;
listFile list;
FILE* mainFile;

FILE* fileOpen(char* name, char* mode) {  // function for open the mainFile
  FILE* test = fopen(name, mode);         // fopen manipulate the FILE pointer
  if (test == NULL) {                     // test if it doesn't open, will alarm
    printf("\n\nError: The %s mainFile was not opened\n", file.fileName);
    system("pause");  // it only works on windows
    exit(0);
  }
  return test;
};

void create() {
  char compare[CHAR_MAX];
  list.index = 0;

  while (list.index == 0) {
    printf("How many items do you want to add?\n");
    scanf("%s", compare);

    list.index =
        atoi(compare);  // This function returns the converted integral
                        // number as an int value. If no valid conversion
                        // could be performed, it returns zero.
    if (list.index == 0) {
      printf("Please enter a number!\n");
    }
  }

  for (int i = 1; i < list.index + 1; i++) {
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
  scanf("%s", file.fileName);

  mainFile =
      fileOpen(file.fileName, "w");  // if not exist, will create for write

  create();
  fclose(mainFile);  // close the mainFile
};

void read() {
  char word[CHAR_MAX];  // char to storage the word

  printf("File to be read\n");
  scanf("%s", file.fileName);

  mainFile = fileOpen(file.fileName,
                      "r");  // will open the mainFile *.txt for read

  while (fgets(word, CHAR_MAX, mainFile) !=
         NULL)  // fgets will get the entire string of file while != NULL
  {
    printf("%s", word);  // print the read word while looping
  }

  fclose(mainFile);  // close the mainFile
};

void alter() {
  printf("File to be alter\n");
  scanf("%s", file.fileName);

  mainFile = fileOpen(file.fileName,
                      "a");  // will open the mainFile *.txt for alter

  create();
  fclose(mainFile);  // close the mainFile
};

void copy() {
  FILE* copiedFile;

  printf("File to be copy\n");
  scanf("%s", file.fileName);

  mainFile = fileOpen(file.fileName,
                      "r");  // will open the mainFile *.txt for read

  printf("File name to be copied\n");
  scanf("%s", file.fileCopy);

  copiedFile = fopen(file.fileCopy,
                     "w");  // will open the copiedFile *.txt for  write

  while (fgets(list.character, CHAR_MAX, mainFile) !=
         NULL) {  // fgets will get the entire string of file while != NULL
    fputs(list.character, copiedFile);  // fputs will put the string of
                                        // list.character in the copiedFile
  }

  fclose(mainFile);    // close the mainFile
  fclose(copiedFile);  // close the copiedFile
};

int main(void) {
  int input;

  do {
    printf("\nSelect one of the options below");
    printf("\n(1) to create a list");
    printf("\n(2) to read an existing list");
    printf("\n(3) to edit an existing list");
    printf("\n(4) to copy an existing list");
    printf("\n(5) to exit the program\n");
    scanf("%d", &input);  // scan the type value

    switch (input) {
      case 1:
        write();  // The function write, create the shopping list file
        break;

      case 2:
        read();  // The function read, show the file datas in the terminal
        break;

      case 3:
        alter();  // The function alter, just input more datas into the file
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

  } while (input <= 4);

  printf("\n");
  system("pause");  // it only works on windows
}
