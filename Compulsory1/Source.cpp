#include <iostream>;
#include <string>;
#include <conio.h>
#include <Windows.h>
#include <vector>

void game();
void checkDraw();
void drawBoard();
void calcWinner();

int row{};
int col{};
std::vector <std::vector<char>> table = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
//char table[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int choice;
bool gameWon = false;
int currentPlayer = 1;


void game()
{
	checkDraw();

	if (currentPlayer == 1)
	{
		std::cout << "\nPlayer 1 [X] take your turn: ";
	}
	else
	{
		std::cout << "\nPlayer 2 [O] take your turn: ";
	}

	char ch = _getch();
	int i = (int)((char)ch - '0');

	switch (i)
	{
	case 1: row = 0, col = 0;
		break;
	case 2: row = 0, col = 1;
		break;
	case 3: row = 0, col = 2;
		break;
	case 4: row = 1, col = 0;
		break;
	case 5: row = 1, col = 1;
		break;
	case 6: row = 1, col = 2;
		break;
	case 7: row = 2, col = 0;
		break;
	case 8: row = 2, col = 1;
		break;
	case 9: row = 2, col = 2;
		break;
	default:
		std::cout << "Invalid input";
		break;
	}

	if (currentPlayer == 1) 
	{
		table[row][col] = 'X';
	}
	else if (currentPlayer == 2) 
	{
		table[row][col] = 'O';
	}

	if (currentPlayer == 2)
	{
		currentPlayer = 1;
		std::cout << "\nPlayer 1 [X] take your turn: ";
	}
	else
	{
		currentPlayer = 2;
		std::cout << "\nPlayer 2 [O] take your turn: ";
	}
}

void checkDraw()
{
	int counter;
	bool draw = false;

	for (int i = 0; i < 3; i++) 
	{
		
		for (int j = 0; j < 3; j++)
		{
			if (table[i][j] == 'X')
			{
				draw = true;
				continue;
			}
			else if (table[i][j] == 'O') 
			{
				draw = true;
				continue;
			}
			else {
				draw = false;
				break;
			}
		}
		
		
	}
	if (draw == true)
	{
		std::cout << "It's a draw!";
		return;
	}
}

void drawBoard()
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << "-------------" << std::endl;
		std::cout << "| ";
		for (int j = 0; j < 3; j++)
		{
			std::cout << table[i][j] << " | ";
		}
	
		std::cout << std::endl;
	} 
	std::cout << "-------------" << std::endl;
}

void calcWinner()
{
	for (int i=0; i < 3; i++)
	{
		if (table[i][0] == table[i][1] && table[i][1] == table[i][2])
		{
			if (table[i][0] == 'X')
				currentPlayer = 1;
			else
				currentPlayer = 2;

			gameWon = true;
			system("cls");
			drawBoard();
			std::cout << "Player " << currentPlayer << " wins!!" << std::endl;

		}
		if (table[0][i] == table[1][i] && table[1][i] == table[2][i])
		{
			if (table[0][i] == 'X')
				currentPlayer = 1;
			else
				currentPlayer = 2;

			gameWon = true;
			system("cls");
			drawBoard();
			std::cout << "Player " << currentPlayer << " wins!!" << std::endl;

		}
		if (table[0][0] == table[1][1] && table[1][1] == table[2][2])
		{
			if (table[0][0] == 'X')
				currentPlayer = 1;
			else
				currentPlayer = 2;

			gameWon = true;
			system("cls");
			drawBoard();
			std::cout << "Player " << currentPlayer << " wins!!" << std::endl;

		}
		if (table[0][2] == table[1][1] && table[1][1] == table[2][0])
		{
			if (table[0][2] == 'X')
				currentPlayer = 1;
			else
				currentPlayer = 2;

			gameWon = true;
			system("cls");
			drawBoard();
			std::cout << "Player " << currentPlayer << " wins!!" << std::endl;

		}
	}
}


int main()
{
	
	char answer{ 'y' };

	
	while (tolower(answer) == 'y') 
	{
		std::cout << "Welcome to Tic Tac Toe!\n\n";
		system("pause");
		gameWon = false;
		table = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
		
		while (gameWon == false) 
		{
			system("cls");
			drawBoard();
			calcWinner();
			if (gameWon == true)
			{
				if (currentPlayer == 1)
				{
					currentPlayer = 2;
				}
				else if (currentPlayer == 2)
				{
					currentPlayer = 1;
				}
				break;
			}
			game();
		}
		std::cout << "Do you want to play again? y/n: ";
		std::cin >> answer;
		/*if (answer == 'y') {
			gameWon = false;
			return 0;
		}
		else if (tolower(answer) == 'n')
		{
			exit(0);
		}*/
	}
	
}