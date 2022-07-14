#include "function.h"

FILE* fileOpen(char* name, char* mode) {  // function for open the mainFile
  FILE* test = fopen(name, mode);         // fopen manipulate the FILE pointer
  if (test == NULL) {                     // test if it doesn't open, will alarm
    printf("\n\nError: The %s mainFile was not opened\n", file.fileName);
    system("pause");  // it only works on windows
    exit(EXIT_FAILURE);
  }
  return test;
};

// used for create the file
void create() {
  char compare[CHAR_MAX];
  list.index = 0;

  while (list.index == 0) {
    printf("How many items do you want to add?\n");
    scanf("%s", compare);

    list.index = atoi(compare);  // This function returns the converted integral
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

// used for open the file in write mode
void write() {
  printf("File to be created\n");
  scanf("%s", file.fileName);

  mainFile =
      fileOpen(file.fileName, "w");  // if not exist, will create for write

  create();
  fclose(mainFile);  // close the mainFile
};

// user for open the file in read mode
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

// used for open the file in alter mode
void alter() {
  printf("File to be alter\n");
  scanf("%s", file.fileName);

  mainFile = fileOpen(file.fileName,
                      "a");  // will open the mainFile *.txt for alter

  create();
  fclose(mainFile);  // close the mainFile
};

// user for open a new file in write mode
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