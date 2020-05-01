#pragma once
#include <iostream>
using namespace std;

const int defaultRstr = 26;
//alphabet for translating inputs
const char colmVals[defaultRstr] =
{ 
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' 
};

int getRow(int restrict = defaultRstr); //asks for a row, returns int based on response (pass int if row is restricted (default 26))
int getColumn(int restrict = defaultRstr); //asks for a col, returns int based on response (pass int if col is restricted (default 26))
void getRowColumn(int answ[2], int rowRestrict, int colRestrict); //answ is changed so 0 is row and 1 is column
int charToInt(char input, int restrict = defaultRstr);
