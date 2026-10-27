#include <stdio.h>
#include "ticktacktoe.h"


int main(){
	char player = 'X';

	int position;
	Board* board = createBoard();

	printf("WELCOME TO tICKtACKtOE\n\n|1| |2| |3|\n|4| |5| |6|\n|7| |8| |9|\n");
	
	while(1){

		printf("Player %c enter position: ",player);
		scanf("%d",&position);

		/*if(inputError(board, position) == 1){
			printf("wrong input, try again!!\n");
			continue;
		}

		if(inputError(board, position)==-1){
			printf("position occupied already!!\n");
			continue;
		}*/

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
		
		/*if(isDraw(board)){
			drawBoard(board);
			printf("GAME IS A DRAW\n");
			gameClose(board);	
			break;
		}

		if(isWin(board)){
			drawBoard(board);
			printf("PLAYER %c WINS\n",player);
			gameClose(board);
			break;
		}
		else{
			nextPlayer(player);
			printf("Player %c's turn\n",player);
			drawBoard(board);
			continue;
		}*/

		switch(checkGameState(board)){
			case GAME_WON:
				drawBoard(board);
				printf("PLAYER %c WINS\n",player);
				gameClose(board);
				break;

			case GAME_DRAW:
				drawBoard(board);
				printf("GAME IS A DRAW\n");
				gameClose(board);	
				break;

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


