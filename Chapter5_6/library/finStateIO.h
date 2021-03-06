#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <set>


#define MAX_FILE_SIZE 512


#define STATES 0
#define ALPHABET 1
#define TRANSITIONS 2
#define FINAL 3

#define MAX_TRAN_SIZE 40
#define MAX_STATE_SIZE 8

void outputFiniteState(char* outPath, std::set<char*>* finiteState);
void sendOutputStream(char* pathOut, char* outputStream);


void parseFiniteState(char* path, std::set<char*>* fininteState);


