#include <stdbool.h>

typedef struct{
	char cells[9];
	int emptyCells;
}Board;

typedef enum {
	INPUT_OCCUPIED,
	INPUT_OK,
	INPUT_OUT_OF_RANGE
}inputState;

typedef enum {
	GAME_WON,
	GAME_DRAW,
	GAME_PLAYING
}gameState;

Board* createBoard();

void drawBoard(Board* board);

void play(Board* board, char player, int position);

bool isBoardFull(Board* board);

bool isDraw(Board* board);

bool isWin(Board* board);

gameState checkGameState(Board* board);

inputState checkInput(Board* board, int position);

char nextPlayer(char player);

void gameClose(Board* board);
