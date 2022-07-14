// FUNCTION LIBRARY

#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#define CHAR_MAX 100
#include "struct.h"

fileCreate file;
listFile list;
FILE* mainFile;

// function for open the mainFile
FILE* fileOpen(char* name, char* mode);

// used for create the file
void create();

// used for open the file in write mode
void write();

// user for open the file in read mode
void read();

// used for open the file in alter mode
void alter();

// user for open a new file in write mode
void copy();

#endif  // FILE_H
