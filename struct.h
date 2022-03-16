// STRUCT LIBRARY

#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char fileCopy[CHAR_MAX];
  char fileName[CHAR_MAX];
} fileCreate;

typedef struct {
  int index;
  char character[CHAR_MAX];
  int amount;
} listFile;

#endif  // STRUCT_H