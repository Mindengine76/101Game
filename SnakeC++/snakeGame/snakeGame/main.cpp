#include <iostream> // i love you iostream
#include <string> // Not needed but I put it in due to habit
#include <conio.h> // a C header file (don't ask me why, it just works-- like buying a woman flowers....why do women love flowers? You can't eat them or do anything useful like that, i put it down to hormones)

using namespace std;


// Game challenge: Create a snake game ONLY using FUNCTIONS  and 'if' statements (Maybe a bit of cheating was involved with the use of an additional library) 

bool gameOver; // terminates the game like Arnie
const int width = 70; // dimensions of the map
const int height = 20; // dimensions of the map

int x, y, fruitx, fruity, score;
int tailX[50];// using an array to create the tail of the snake
int tailY[50];
int endTail;// end of the snake (for collisions)


enum eDirection {STOP, LEFT, RIGHT, UP, DOWN}; // to be used by input function (hopefully)
eDirection dir;



void setUp()
{
	gameOver = false; // while the game is running, bool value is equal to false
	dir = STOP; // begin with no movement ( better safe than sorry)
	x = width / 2; // center head of snake
	y = height / 2; // center head 
	fruitx = rand() % width; // random spawn
	fruity = rand() % height; // random spawn
	score = 0;
}
void draw() 
{
	system("cls"); // clear screen
	for (int i = 0; i < width + 2; i++) // set the top boarder 
	
		cout << "#"; // use the hash to create the map boarder
		cout << endl;
	

	for (int i = 0; i < height; i++) // top boarder of the map
	{
		for (int j = 0; j < width + 2; j++) // sides of the map
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x) // when the i and j iterators reaches this co ordinate, print the head of snake
				cout << "0"; // snake head 
			else if (i == fruity && j == fruitx) // when the iterator reaches this point print 'F' for the fruit
				cout << "F"; // fruit 
			else
			{	
				bool printTail = false;
				for (int k = 0; k < endTail; k++)
				{

					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";  //tail portion of the snake
						printTail = true;
					}
				}
				if (!printTail)
					cout << " "; // leaves nothingness in it's wake! (the serpent that eat the world
			}
				

			if (j == width - 1) // boarder of the map
				cout << "#"; 

		}
		cout << endl; 
		
	}
	for (int i = 0; i < width + 2; i++) // bottom of the map ( plus 2 to fill gap on bottom edge of map ( just to make it pretty)
	
		cout << "#";
		cout << endl;
		cout << "SCORE:" << score << endl; // prints out how many fruits have been eaten (which is difficult because my processor is so quick!)
	
}
void Input() 
{
	if (_kbhit()) // determines if a key was pressed  
	{
		switch (_getch()) // gets a char entry from the console ( or so wiki says), but just as easily be black magic (otherwise known as C programming language) 
		{
		case 'a':
			dir = LEFT; // does what is says on the tin
				break;
		case 'd':
			dir = RIGHT; // do I really need to explain this?
			break;
		case 'w':
			dir = UP; // really?
			break;
		case 's':
			dir = DOWN; // ok, it creates world peace ( with rainbows and unicorns)
			break;
		case 'x':
			gameOver = true; // keyboard event 'x' to quit the game
			break;
		}
	}
}
void logic() 
{
	int prevX = tailX[0]; // using the arrays to create the tail
	int prevY = tailY[0];
	int prev2X, prev2Y; // old position
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < endTail; i++) // for loop for tail 
	{
		prev2X = tailX[i]; 
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}



	switch (dir)
	{
	case LEFT: // go left iterator takes away from the x value
		x--;
		break;
	case RIGHT: // opposite
		x++;
		break;
	case UP:  // iteratior takes away from the y value
		y--;
		break;
	case DOWN: // you get the idea, lots of taking or adding depending on direction of the screen
		y++;
		break;
	default: // visual studios gave me this! When I added this switch statement, not sure why, but it works! So thank you visual studios, I'm sorry I cursed you so much.
		break;
	}

	if (x > width || x < 0 || y > height || y < 0) // set a boarder limit for the snake head. If it goes out of the map GAME OVER!
		gameOver = true; 

	// 

	if (x == fruitx && y == fruity) // re-spawns the fruit 
	{
		
		score += 10;
		fruitx = rand() % width; // random spawn
		fruity = rand() % height; // random spawn
		endTail += 1;
	}
}


int main() // game loop 
{
	setUp();

	while (!gameOver)
	{
		draw();
		Input();
		logic();

		}
	return 0;
}

