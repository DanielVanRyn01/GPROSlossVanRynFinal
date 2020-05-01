#pragma once
#include <iostream>
#include <fstream>
#include <time.h>

class board
{
public:
	board();
	board(int Size);
	void boardReset(int Size);
private:
	int size = 8;
	char player1 = 'R', player2 = 'B';
};