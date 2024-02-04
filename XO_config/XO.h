#ifndef XO_H
#define XO_H



typedef enum EN_playerSymbolErr_t
{
	SYM_OK, WRONG_SYM

}EN_playerSymbolErr_t;


typedef enum EN_gameState_t
{
	WIN, DRAW, CONTINUE

}EN_gameState_t;




void drawBoard(uint8_t* board);
void updateBoard(uint8_t* board, uint8_t position, uint8_t value);
EN_playerSymbolErr_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol);
void setPlayerConfig(uint8_t* configArray);
void loadAndUpdate(uint8_t playerNumber);
void getGameState(uint8_t* board, uint8_t* gameState);



#endif // !XO_H
