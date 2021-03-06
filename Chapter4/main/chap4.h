#include <set>

// remove recusive start symbols
void alg4_1(char* pathIn, char* pathOut);

// Remove lambda rules
void alg4_2(char* pathIn, char* pathOut);

// Remove chain rules
void alg4_3(char* pathIn, char* pathOut);

// Generate strings that derive terminal, remove ones that dont
void alg4_4_2(char* pathIn, char* pathOut);

// Remove un-reachable productions
void alg4_4_4(char* pathIn, char* pathOut);

// Chomsky Normal Form
void alg4_5(char* pathIn, char* pathOut);

// CYK Algorithm
void alg4_6(char* pathIn, char* pathOut, char* input);

// Removal of Direct Left Recursion
void alg4_7(char* pathIn, char* pathOut);
void alg4_7_GNF(std::set<char*>* grammer, char* var);

//Greibach Normal Form
void alg4_8(char* pathIn, char* pathOut);
