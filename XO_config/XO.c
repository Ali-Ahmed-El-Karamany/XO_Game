#include<stdio.h>
#include<conio.h>
#include"..\Type Defs\type_defs.h"
#include"XO.h"

// global variables
uint8_t position;
uint8_t configArr[2];
uint8_t XO_Board[9] = { '1','2','3','4','5','6','7','8','9' };
uint8_t gameState = CONTINUE;

// Function takes X-O board and print it on the console
void drawBoard(uint8_t* board)
{
	for (uint8_t i = 0; i < 9; i++)
	{
		if (i%3==0)
		{
			printf("\n\n");
		}

		printf("\t\t\t%c", board[i]);
	}

	printf("\n\n");
}


// Function takes the vlaue(X,O) and updates the board
void updateBoard(uint8_t* board, uint8_t position, uint8_t value)
{
	board[position-1] = value;
	drawBoard(board);
}


// Function takes the player's number and asks the player to choose between X and O (case insensitive)
// checks if the input symbol is not wrong or was not chosen before so return(SYM_OK)
// checks if the input symbol is wrong or was chosen before so return(WRONG_SYMBOL)
EN_playerSymbolErr_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol)
{
	if (playerNumber == 1)
	{
		if (symbol[playerNumber - 1] == 'X' || symbol[playerNumber - 1] == 'O' || symbol[playerNumber - 1] == 'x' || symbol[playerNumber - 1] == 'o')
		{
			return SYM_OK;
		}

		else
		{
			printf("Wrong symbol player 1, please choose either 'x' or 'o' \n");
			return WRONG_SYM;
		}
	}

	else
	{
		if (symbol[playerNumber - 1] == 'X' || symbol[playerNumber - 1] == 'O' || symbol[playerNumber - 1] == 'x' || symbol[playerNumber - 1] == 'o')
		{
			if (symbol[playerNumber - 1] == symbol[playerNumber - 2])
			{
				printf("Symbol has been choosen before, please choose another one");
				return WRONG_SYM;
			}

			else
			{
				return SYM_OK;
			}
		}

		else
		{
			printf("Wrong symbol player 2, please choose either 'x' or 'o' \n");
			return WRONG_SYM;
		}

	}
}

//  Function asks each player about their preferred symbol and saves it in the configArray
void setPlayerConfig(uint8_t* configArray)
{
	uint8_t symbolSatus = WRONG_SYM;

	while (symbolSatus == WRONG_SYM)
	{
		printf("Player 1: choose a symbol 'x' or 'o' \n");
		scanf(" %c", &configArray[0]);
		symbolSatus = getPlayerSymbol(1, configArray);

	}

	symbolSatus = WRONG_SYM;

	while (symbolSatus)
	{
		printf("Player 2: choose a symbol 'x' or 'o' \n");
		scanf(" %c", &configArray[1]);
		symbolSatus = getPlayerSymbol(2, configArray);
	}
	system("cls");
}


// Function takes the player's number then load his config, ask him for the position then updates the board
void loadAndUpdate(uint8_t playerNumber)
{
	printf("please enter the position to play \n");
	scanf(" %hhd", &position);
	system("cls");


	// Checks if the position was taken before
	if (XO_Board[position - 1] == 'X' || XO_Board[position - 1] == 'x' || XO_Board[position - 1] == 'O' || XO_Board[position - 1] == 'o')
	{
		printf("wrong position, this was taken before please choose a free one \n \n");
		drawBoard(XO_Board);
		loadAndUpdate(playerNumber);

	}

	else if (position >= 1 && position <= 9)
	{
		system("cls");
		updateBoard(XO_Board, position, configArr[playerNumber - 1]);
	}

	else
	{
		printf("wrong position, please choose a position from 1 to 9 \n \n");
		drawBoard(XO_Board);
		loadAndUpdate(playerNumber);
	}
	
}


// Function checks after each move if there is a win, draw or continue playing.
void getGameState(uint8_t* board, uint8_t* gameState)
{
	if (XO_Board[0] == XO_Board[1] && XO_Board[1] == XO_Board[2])
	{
		*gameState = 0;
	}

	else if (XO_Board[3] == XO_Board[4] && XO_Board[4] == XO_Board[5])
	{
		*gameState = 0;
	}

	else if (XO_Board[6] == XO_Board[7] && XO_Board[7] == XO_Board[8])
	{
		*gameState = 0;
	}

	else if (XO_Board[0] == XO_Board[3] && XO_Board[3] == XO_Board[6])
	{
		*gameState = 0;
	}

	else if (XO_Board[1] == XO_Board[4] && XO_Board[4] == XO_Board[7])
	{
		*gameState = 0;
	}

	else if (XO_Board[2] == XO_Board[5] && XO_Board[5] == XO_Board[8])
	{
		*gameState = 0;
	}

	else if (XO_Board[0] == XO_Board[4] && XO_Board[4] == XO_Board[8])
	{
		*gameState = 0;
	}

	else if (XO_Board[2] == XO_Board[4] && XO_Board[4] == XO_Board[6])
	{
		*gameState = 0;
	}

	else if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
			board[3] != '4' && board[4] != '5' && board[5] != '6' &&
			board[6] != '7' && board[7] != '8' && board[8] != '9')
	{
		*gameState = 1;
	}
	else
	{
		*gameState = 2;
	}
}