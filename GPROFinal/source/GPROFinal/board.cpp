#include "board.h"


board::board()
{
}

void board::boardReset()
{
	for (int j = 0; j < BOARD_HEIGHT; j++) 
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			if (j < 2)
			{
				this->Board[j][i] = player2;
			}
			if (j > 5)
			{
				this->Board[j][i] = player1;
			}
			else if(j > 2 && j < 5)
			{
				this->Board[j][i] = 'O';
			}
		}
	}
}

char board::boardSpaceGet(int xpos,int ypos)
{
	char temp = (*pBoard)[xpos][ypos];
	return temp;
}

void board::boardSpaceSet(char player, int xpos, int ypos)
{
	(*pBoard)[xpos][ypos] = player;
}

bool board::playerMoveValid(char player, int xpos, int ypos)
{
	if (boardSpaceGet(xpos, ypos) != 'O')
	{
		return false;
	}
	else
	{
		return true;
	}
}

void board::playerMove(char player, int xpos, int ypos)
{

}
