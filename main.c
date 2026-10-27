#include <stdio.h>
#include "ticktacktoe.h"

void drawBoard(Board* board)
{	
	printf("|%c| |%c| |%c|\n|%c| |%c| |%c|\n|%c| |%c| |%c|\n",board->cells[0],board->cells[1],board->cells[2],board->cells[3],board->cells[4],board->cells[5],board->cells[6],board->cells[7],board->cells[8]);

}

int main(){
	char player = 'X';

	int position;
	Board* board = createBoard();

	printf("WELCOME TO tICKtACKtOE\n\n|1| |2| |3|\n|4| |5| |6|\n|7| |8| |9|\n");
	
	while(1){

		printf("Player %c enter position: ",player);

		if (scanf("%d", &position) != 1) { //1 returned on numeral stored. 0 on non and -1 on EOF(input done).
			int c; 
			while ((c = getchar()) != '\n' && c != EOF) {} //queue cleaning to prevent loop in case of character input than a number.
			printf("Enter a number 1-9\n");
			continue;
		}

		switch(checkInput(board,position)){
			case INPUT_OUT_OF_RANGE:
				printf("input out of range, try again!!\n");
				continue;
				break;

			case INPUT_OCCUPIED:
				printf("position occupied already, try again!!\n");
				continue;
				break;

			case INPUT_OK:
				break;
		}

		play(board, player, position);
		
		switch(checkGameState(board)){
			case GAME_WON:
				drawBoard(board);
				printf("PLAYER %c WINS\n",player);
				gameClose(board);
				return 0;

			case GAME_DRAW:
				drawBoard(board);
				printf("GAME IS A DRAW\n");
				gameClose(board);	
				return 0;

			case GAME_PLAYING:
				player = nextPlayer(player);
				printf("Player %c's turn\n",player);
				drawBoard(board);
				continue;
				break;
		}
	}

	return 0;
}


