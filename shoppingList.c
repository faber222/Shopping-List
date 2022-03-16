/*
AUThOR: Faber Bernardo júnior & Igor Silva Vieira
DATA: 13/03/2022
PROGRAM SYNOPSIS: make a shopping list, just using the terminal
INPUT DATA: the struct listFile
OUTPUT DATA: the struct fileCreate
*/

#include <stdio.h>
#include <stdlib.h>

#include "function.h"

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