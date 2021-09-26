#include <iostream>;
#include <string>;

int row{};
int col{};
char table[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
bool draw = false;
int choice;


void game()
{
	int currentPlayer = 1;

	if (currentPlayer == 1)
	{
		currentPlayer = 1;
		std::cout << "\nPlayer 1 [X] take your turn: ";
	}
	else
	{
		currentPlayer = 2;
		std::cout << "\nPlayer 2 [O] take your turn: ";
	}

	std::cin >> choice;

	switch (choice)
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
}


void drawBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << " | " << table[i][j] << " | ";
		}
		std::cout << std::endl;
	} 
}



int main()
{
	std::cout << "Welcome to Tic Tac Toe!\n\n";
	drawBoard();
	game();

	
	
}