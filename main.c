#include <stdio.h>
#include "ticktacktoe.h"


int main(){
	char* player = createPlayer();

	int position;
	Board* board = createBoard();

	printf("WELCOME TO tICKtACKtOE\n\n|1| |2| |3|\n|4| |5| |6|\n|7| |8| |9|\n");
	
	while(1){

		printf("Player %c enter position: ",player[0]);
		scanf("%d",&position);

		if(inputError(board, position) == 1){
			printf("wrong input, try again!!\n");
			continue;
		}

		if(inputError(board, position)==-1){
			printf("position occupied already!!\n");
			continue;
		}

		play(board, player, position);
		

		if(isDraw(board)){
			drawBoard(board);
			printf("GAME IS A DRAW\n");
			gameClose(board, player);	
			break;
		}

		if(isWin(board)){
			drawBoard(board);
			printf("PLAYER %c WINS\n",player[0]);
			gameClose(board, player);
			break;
		}
		else{
			nextPlayer(player);
			printf("Player %c's turn\n",player[0]);
			drawBoard(board);
			continue;
		}
	}

	return 0;
}


