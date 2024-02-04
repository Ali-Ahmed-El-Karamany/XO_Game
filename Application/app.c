#include<stdio.h>
#include"..\Type Defs\type_defs.h"
#include"..\XO_config\XO.h"
#include"app.h"

// // global variables itialization
extern uint8_t position;
extern uint8_t configArr[2];
extern uint8_t XO_Board[9];
extern uint8_t gameState;


void appStart()
{
	setPlayerConfig(configArr);
	printf("\nPlayer 1 Symbol is :%c \n ", configArr[0]);
	printf("\nPlayer 2 Symbol is :%c \n ", configArr[1]);
	drawBoard(XO_Board);

	uint8_t i;
	for (i = 0; i < 9; i++)
	{
		if (i % 2 == 0)
		{
			printf("Player 1 turn \n");
			loadAndUpdate(1);
			getGameState(XO_Board, &gameState);
		}

		else
		{
			printf("Player 2 turn \n");
			loadAndUpdate(2);
			getGameState(XO_Board, &gameState);

		}

		if (gameState != CONTINUE)
		{
			break;
		}
	}

	if (gameState == WIN)
	{
		if (i % 2 == 0)
		{
			printf("CONGRAAATS PLAYER ONE, YOU'RE THE WINEER ");
		}

		else
		{
			printf("CONGRAAATS PLAYER TWO, YOU'RE THE WINEER");
		}
	}

	else
	{
		printf("GAME DRAW");
	}
}



int main()
{
	appStart();
}