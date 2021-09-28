#include <iostream>;
#include <string>;
#include <conio.h>
#include <Windows.h>
#include <vector>

void game(); //Input, switches player, assigns player token.
void checkDraw(); //Ends the game if board is filled.
void drawBoard(); //Draws the board with loops.
void calcWinner(); //Calculates the winner.

int row{};
int col{};
std::vector <std::vector<char>> table = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int choice;
bool gameWon = false;
int currentPlayer = 1;
bool draw = false;

void game()
{

	if (currentPlayer == 1)
	{
		std::cout << "\nPlayer 1 [X] take your turn: ";
	}
	else
	{
		std::cout << "\nPlayer 2 [O] take your turn: ";
	}

	char ch = _getch(); //Saves the players from having to press enter for better playability.
	int i = (int)((char)ch - '0');

	switch (i) //Numerical input for each slot in the vector.
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

	if (currentPlayer == 1) //Assigns a token to the players.
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

	

	for (int i = 0; i < 3; i++) 
	{
		
		for (int j = 0; j < 3; j++)
		{
			if (table[i][j] == 'X') //Checks for X chars in the vector.
			{
				draw = true;
				continue;
			}
			else if (table[i][j] == 'O') //Checks for O chars in the vector.
			{
				draw = true;
				continue;
			}
			else //The board is not filled and the main loop moves to next players turn.
			{ 
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
	for (int i = 0; i < 3; i++) //Draws the board.
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
		if (table[i][0] == table[i][1] && table[i][1] == table[i][2]) //Checks if a player has won horizontally.
		{
			if (table[i][0] == 'X') //Checks which player has won.
				currentPlayer = 1;
			else
				currentPlayer = 2;

			gameWon = true;
			system("cls"); //Clears the screen.
			drawBoard(); //Draws the new updated board.
			std::cout << "Player " << currentPlayer << " wins!!" << std::endl; //Announces the winner.

		}
		if (table[0][i] == table[1][i] && table[1][i] == table[2][i]) //Checks if a player has won vertically.
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
		if (table[0][0] == table[1][1] && table[1][1] == table[2][2]) //Checks diagonal 1.
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
		if (table[0][2] == table[1][1] && table[1][1] == table[2][0]) //Checks diagonal 2.
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
	
	char answer{ 'y' }; //Makes the game run the first time.
	
	while (tolower(answer) == 'y') //Loops the game while the answer is y.
	{

		currentPlayer = 1; //Makes sure it's player 1's turn every new game.

		std::cout << "Welcome to Tic Tac Toe!\n\n";
		system("pause");
		gameWon = false;
		table = { {'1','2','3'},{'4','5','6'},{'7','8','9'} }; //Resets the board to it's original state.
		
		while (gameWon == false) 
		{
			system("cls");
			drawBoard();
			checkDraw();
			calcWinner();
			if (gameWon == true) //Shows the correct winner (messy hotfix).
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
			else if (draw == true) //Ends the game if it's a draw.
			{
				std::cout << std::endl;
				break;
			}
			game();
		}
		std::cout << "Do you want to play again? y/n: ";
		std::cin >> answer;
	
	}
	
}