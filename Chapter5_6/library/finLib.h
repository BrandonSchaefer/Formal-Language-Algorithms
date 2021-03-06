//##########################################
// -Author: Brandon Schaefer
// -Created: 5/08/11
// -File Name: lib.h 
//##########################################
#include <set>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

#define EMPTY_SET "0"
#define NULL_CHAR "$"

typedef std::vector<std::vector<std::set<int*> > > setMatrix;
/*
#ifndef __LIB_H
#define __LIB_H

// Basic Set Functions
bool member(std::set<char*> setA, char* data);
void unionSet(std::set<char*>& setA, std::set<char*> setB);
void interSet(std::set<char*>& setA, std::set<char*> setB);
void diffSet(std::set<char*>& setA, std::set<char*> setB);
// --- End of set funcs


void insertIntoSet(std::set<char*>& set, char* data);

bool compareSets( std::set<char*> setA, std::set<char*> setB );

void displaySet(std::set<char*> setA);

bool isDigit( char digit );

bool isLowChar( char letter );

// Both of these return 0 if no terminal or var is found
// otherwise it returns the size of the term or var in the 
// char*

int isTerminal( char* term );
int isVariable( char* var );

#endif

*/


int isState(char* state);

// returns dynmically allocated memery. 
// d(state1, letter) = state2
char* newTransition(char* state1, char* letter, char* state2);

char* flattenSplitTransition(std::vector<char*> vecTranisition);
std::vector<char*> splitTransition(char* transition);

// Takes a set of states and converts it into a char*
char* convertSetToString(std::set<char*> setA);

// Takes a char* of states and converts it to a set.
std::set<char*> parseStateString(char* states);

void freeSet(std::set<char*>& setA);
void freeVector(std::vector<char*>& vec);

template <class T>
inline void freeCont(T& cont){
	
	typename T::iterator it;

	for( it = cont.begin(); it != cont.end(); it++){
		delete(*it);
	}
}
