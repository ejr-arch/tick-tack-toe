typedef enum{
	FALSE=0,
	TRUE=1
}boolean;

typedef struct{
	char* board;
	int empSpace;
}Board;

Board* createBoard();

char* createPlayer();

void drawBoard(Board* board);

void play(Board* board, char* player, int position);

boolean isBoardFull(Board* board);

boolean isWin(Board* board);

boolean isDraw(Board* board);

//boolean isGameOver(char* board);

int inputError(Board* board, int position);

void nextPlayer(char* player);

void gameClose(Board* board, char* player);
