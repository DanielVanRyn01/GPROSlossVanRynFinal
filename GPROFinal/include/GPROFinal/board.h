#pragma once
#include <iostream>
#include <fstream>
#include <time.h>

const int BOARD_HEIGHT = 8;
const int BOARD_WIDTH = 8;

class board
{
public:
	board();
	void boardReset();
	char boardSpaceGet(int xpos,int ypos);
	void boardSpaceSet(char player, int xpos, int ypos);
	bool playerMoveValid(char player,int xpos, int ypos);
	void playerMove(char player, int xpos, int ypos);
private:
	char Board[BOARD_HEIGHT][BOARD_WIDTH] = {'O'};
	char (*pBoard)[BOARD_HEIGHT][BOARD_WIDTH] = &Board;
	char player1 = 'R', player2 = 'B';
};