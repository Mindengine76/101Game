
#include <iostream>
#include <ctime>
using namespace std;



const int row = 10;
const int elements = 10;
int MaxShips = 5;
 
bool isrunning; 


int Matrix[row][elements];

void Clear()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			Matrix[i][j] = 0;
		}

	}
}

void Display()
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int NumberofShips()
{
	int counter = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			if (Matrix[i][j] == 1)
				counter++;	
		}
	
	}
	return counter;
}

void SetShips()
{
	int Spawned = 0;
	while (Spawned < MaxShips)
	{
		int x = rand() % row; 
		int y = rand() % elements;

		if (Matrix[x][y] != 1)
		{
			Spawned++;
			Matrix[x][y] = 1;
		}
	}
}

bool Guess(int x, int y)
{
	if (Matrix[x][y] == 1)
	{
		Matrix[x][y] = 2;
		return true;
	}
	return false;
}






int main()
{
	
	srand(time(NULL));
	Clear();
	SetShips();
	int pos1, pos2;
	char prompt;
	while (1)
	{
		cout << "Please input target location" << endl;
		cin >> pos1 >> pos2;
		if (Guess(pos1, pos2))
			cout << "Direct hit you sunk my battle ship!!!!  :( " << endl;
		else
			cout << "Sorry you missed!!!" << endl; 
			cout << "Number of ships still active:  " << NumberofShips() << endl;
			cout << "Do you Give up? y/n" << endl;
			cin >> prompt;
			if (prompt == 'y')
				break;
	}
	cout << "GAME OVER" << endl;
	Display();
	system("pause");
	return 0;
}