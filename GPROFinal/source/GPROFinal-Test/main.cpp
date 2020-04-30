#include "GPROFinal/GPROFinal.h"
#include "GPROFinal/board.h"
#include <iostream>
using namespace std;
int main()
{
	int f, bar = 2;
	f = foo(bar);

	board game;
	game.boardReset();
	//cout << game.boardSpaceGet(bar, f) << endl;
//	game.boardSpaceSet('R', bar, f);
	//cout << game.boardSpaceGet(0, 0);
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			cout << game.boardSpaceGet(j, i) << " ";
		}
		cout << endl;
	}
}