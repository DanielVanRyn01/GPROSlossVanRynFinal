#include "Display.h"

int Display::getRows()
{
	return rows;
}

int Display::getRowSize()
{
	return rowSize;
}

void Display::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int c = 0; c < rowSize; c++)
		{
			cout << board[i][c] << " ";
		}
		cout << endl;
	}
}

void Display::printDivided()
{
	for (int c = 0; c < rowSize; c++)
	{
		cout << board[0][c] << "|";
	}
	for (int i = 1; i < rows; i++)
	{
		for (int c = 0; c < rowSize; c++)
		{
			cout << board[i][c] << "|";
		}
		cout << endl;
		cout << "-";
		for (int c = 1; c < rowSize; c++)
		{
			cout << "+-";
		}
		cout << endl;
	}
}

void Display::printMarked()
{
	cout << "X  ";
	for (int c = 0; c < rowSize; c++)
	{
		cout << colVals[c] << " ";
	}
	cout << endl << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << setw(2) << i << "  ";
		for (int c = 0; c < rowSize; c++)
		{
			cout << board[i][c] << " ";
		}
		cout << endl;
	}
}

bool Display::printRow(int row)
{
	if (row < rows)
	{
		for (int c = 0; c < rowSize; c++)
		{
			cout << board[row][c] << " ";
		}
		return true;
	}
	return false;
}

bool Display::printColumn(int column)
{
	if (column < rowSize)
	{
		for (int c = 0; c < rowSize; c++)
		{
			cout << board[c][column] << "\n";
		}
		return true;
	}
	return false;
}

bool Display::setPoint(int row, int column, char value)
{
	if (row < rows && column < rowSize)
	{
		board[row][column] = value;
		return true;
	}
	return false;
}

char Display::getPoint(int row, int column)
{
	if (row < rows && column < rowSize)
	{
		return board[row][column];
	}
	return ' ';
}