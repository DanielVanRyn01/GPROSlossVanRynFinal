#include "Input.h"



int getRow(int restrict)
{
	int answer = restrict;
	cout << "Choose a row (1, 2, 3, etc)\n";
	cin >> answer;
	while (answer >= restrict)
	{
		cout << "Improper response, please try again\n";
		cout << "Choose a row (1, 2, 3, etc)\n";
		cin >> answer;
	}
	return answer-1;
}

int getColumn(int restrict)
{
	int answer = restrict;
	char temp;
	cout << "Choose a column (A, B, C, etc)\n";
	cin >> temp;
	answer = charToInt(temp);
	while (answer > restrict)
	{
		cout << "Improper response, please try again\n";
		cout << "Choose a column (A, B, C, etc)\n";
		cin >> temp;
		answer = charToInt(temp);
	}
	return answer;
}

void getRowColumn(int answ[2], int rowRestrict = defaultRstr, int colRestrict = defaultRstr)
{
	answ[0] = getRow();
	answ[1] = getColumn();
}

int charToInt(char input, int restrict)
{
	for (int c = 0; c < restrict; c++)
	{
		if (input == colmVals[c])
		{
			return c;
		}
	}
	return -1;
}