#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

//handles boards up to 26x26

const int defaultBoardSize = 26;
const char colVals[defaultBoardSize] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

class Display
{
public:
	Display(vector<char> values, int rows, int rowSize)
	{
		this->rows = rows;
		this->rowSize = rowSize;
		for (int i = 0; i < defaultBoardSize; i++)
		{
			for (int c = 0; c < defaultBoardSize; c++)
			{
				board[i][c] = 0;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int c = 0; c < rowSize; c++)
			{
				int temp = i * rowSize + c;
				board[i][c] = values[temp];
			}
		}

	};
	Display(int rows, int rowSize)
	{
		this->rows = rows;
		this->rowSize = rowSize;
		for (int i = 0; i < defaultBoardSize; i++)
		{
			for (int c = 0; c < defaultBoardSize; c++)
			{
				board[i][c] = 0;
			}
		}
	};
	Display()
	{
		rows = defaultBoardSize;
		rowSize = defaultBoardSize;
		for (int i = 0; i < defaultBoardSize; i++)
		{
			for (int c = 0; c < defaultBoardSize; c++)
			{
				board[i][c] = 0;
			}
		}
	};
	Display(Display& copy)
	{
		this->rows = copy.getRows();
		this->rowSize = copy.getRowSize();
		//this->board = copy.getBoard();
	}
	~Display() {}

	int getRows(); //gets number of rows
	int getRowSize(); //gets number of columns
	void print(); //prints the board based on rows and rowSize
	void printDivided(); // prints like tic-tac-toe
	void printMarked(); //prints with alphanumeric characters on the sides to mark rows and columns
	bool printRow(int row); //prints given row if valid (returns false if not)
	bool printColumn(int column); //prints given column as a column if valid(returns false if not)
	bool setPoint(int row, int column, char value); //sets a point of the board to a different character (returns false if not valid)
	char getPoint(int row, int column); //gets a point on the board, returns ' ' if invalid
private:
	char board[defaultBoardSize][defaultBoardSize];
	int rowSize;
	int rows;
};