#pragma once
#include "Display.h"
#include "Input.h"
#include <iostream>
#include <fstream>
#include <time.h>

const int BOARD_HEIGHT = 8;
const int BOARD_WIDTH = 8;
const char STATES[5] = { 'O','r','b','R','B' };

class checkers
{
public:
	checkers();
	void boardReset();
	void playCheckers();
	bool playerCheck(char input,int player);
	int playerMoveValid(int player,int end[2],int start[2]);
	bool playerMove(int player,int jump, int end[2],int start[2]);
	char playerJump(char player, int xpos, int ypos);
	int valueToInt(char piece);
private:
	Display board;
	int player1 = 1, player2 = 2;
	int player1pieces = 0, player2pieces = 0;
};