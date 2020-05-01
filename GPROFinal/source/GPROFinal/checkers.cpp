#include "checkers.h"

checkers::checkers()
{
	board = Display(STATES[0],8,8);
	boardReset();
	board.printMarked();
	playCheckers();
}

void checkers::boardReset()
{
	for (int j = 0; j < board.getRows(); j++) {
		for (int i = 0; i < board.getRowSize(); i++) {
			if (((i % 2 != 0 && j % 2 == 0)||(i % 2 == 0 && j % 2 != 0)) && (i < 3)) 
			{
				board.setPoint(i, j, STATES[2]);
				player2pieces++;
			}
			else if (((i % 2 != 0 && j % 2 == 0) || (i % 2 == 0 && j % 2 != 0)) && (i >= board.getRows() - 3)) 
			{
				board.setPoint(i, j, STATES[1]);
				player1pieces++;
			}
			else
			{
				board.setPoint(i, j, STATES[0]);
			}
		}
	}
}

void checkers::playCheckers()
{
	bool valid1 = false,valid3 = false;
	int valid2 = -1;
	int input[2];
	int input2[2];
	int player = 1;
	int winner = 0;
	while (winner == 0)
	{
		cout << "Which piece would you like to move?" << endl;
		getRowColumn(input, board.getRows(), board.getRowSize());
		valid1 = playerCheck(board.getPoint(input[0], input[1]), player);
		while (!valid1)
		{
			cout << "Invalid piece" << endl;
			board.printMarked();
			cout << "Which piece would you like to move?";
			getRowColumn(input, board.getRows(), board.getRowSize());
			valid1 = playerCheck(board.getPoint(input[0], input[1]), player);
		}
		cout << "Where would you like to move it?" << endl;
		getRowColumn(input2, board.getRows(), board.getRowSize());
		valid2 = playerMoveValid(player, input2, input);
		while (valid2 == -1)
		{
			cout << "Invalid Location" << endl;
			board.printMarked();
			cout << "Where would you like to move it?" << endl;
			getRowColumn(input2, board.getRows(), board.getRowSize());
			valid2 = playerMoveValid(player, input2, input);
		}
		valid3 = playerMove(player, valid2, input2, input);
		cout << valid3 << endl;
		if (player == 1)
		{
			player++;
		}
		else if (player == 2)
		{
			player--;
		}
		if (player1pieces == 0)
		{
			winner = 2;
			cout << "Player " << winner << " Wins!";
		}
		if (player2pieces == 0)
		{
			winner = 1;
			cout << "Player " << winner << " Wins!";
		}
		board.printMarked();
	}
}

bool checkers::playerCheck(char input,int player)
{
	if (valueToInt(input) == player)
		return true;
	else
		return false;
}

int checkers::playerMoveValid(int player,int end[2],int start[2])
{
	if ((end[0] % 2) - (end[1] % 2) != 0)
	{
		if (board.getPoint(end[0], end[1]) == STATES[0])
		{
			return 0; //moveable
		}
		else if (board.getPoint(start[0] + (2 * (end[0] - start[0])), start[1] + (2 * (end[1] - start[1]))) == 'O' && !playerCheck(board.getPoint(end[0],end[1]),player))
		{
			return 1; //moveable but has to jump
		}
	}
	return -1; //false
}

bool checkers::playerMove(int player,int jump, int end[2], int start[2])
{
	if (jump == 0)
	{
		board.setPoint(end[0], end[1], STATES[player]);
		board.setPoint(start[0], start[1], STATES[0]);
		return true;
	}
	else if (jump == 1)
	{
		board.setPoint(start[0] + (2 * (end[0] - start[0])), start[1] + (2 * (end[1] - start[1])), STATES[player]);
		board.setPoint(end[0], end[1], STATES[0]);
		board.setPoint(start[0], start[1], STATES[0]);
		if (player == 1)
			player2pieces--;
		if (player == 2)
			player1pieces--;
		return true;
	}
	else 
		return false;
}

int checkers::valueToInt(char piece)
{
	for (int c = 0; c < 5; c++)
	{
		if (piece == STATES[c])
		{
			return c;
		}
	}
	return -1;
}
