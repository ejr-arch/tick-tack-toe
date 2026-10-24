#include <stdio.h>
#include <stdlib.h>
#include "ticktacktoe.h"

Board* createBoard(){
	Board* board = (Board*)malloc(sizeof(Board));
	for(int i=0;i<9;i++)board->board[i]=' ';
	board->empSpace = 9;
	return board;
}

char* createPlayer(){
	char* player = malloc(sizeof(char));
	player[0] = 'O';
	return player;
}
void drawBoard(Board* board)
{	

	printf("|%c| |%c| |%c|\n|%c| |%c| |%c|\n|%c| |%c| |%c|\n",board->board[0],board->board[1],board->board[2],board->board[3],board->board[4],board->board[5],board->board[6],board->board[7],board->board[8]);

}


void play(Board* board, char* player, int position)
{
	board->board[position-1] = *player;
	board->empSpace--;
}

void nextPlayer(char* player){
	if(player[0]=='X')
		player[0] = 'O';
	else player[0] = 'X';
}

boolean isBoardFull(Board* board){
	if(board->empSpace == 0)return 1;
	return 0;
}

boolean isWin(Board* board)
{
	//horizontally - 3 rows
	if(board->board[0]==board->board[1]){
		if(board->board[1]==board->board[2]){
			if(board->board[0]==' '||board->board[1]==' '||board->board[2]==' ')return 0;
			else return 1;
		}
	}
	if(board->board[3]==board->board[4]){
		if(board->board[4]==board->board[5]){
			if(board->board[3]==' '||board->board[4]==' '||board->board[5]==' ')return 0;
			else return 1;
		}
	}
	if(board->board[6]==board->board[7]){
		if(board->board[7]==board->board[8]){
			if(board->board[6]==' '||board->board[7]==' '||board->board[8]==' ')return 0;
			else return 1;
		}
	}
	//vertically - 3 columns
	if(board->board[0]==board->board[3]){
		if(board->board[3]==board->board[6]){
			if(board->board[0]==' '||board->board[3]==' '||board->board[6]==' ')return 0;
			else return 1;
		}
	}
	if(board->board[1]==board->board[4]){
		if(board->board[4]==board->board[7]){
			if(board->board[1]==' '||board->board[4]==' '||board->board[7]==' ')return 0;
			else return 1;
		}
	}
	if(board->board[2]==board->board[5]){
		if(board->board[5]==board->board[8]){
			if(board->board[2]==' '||board->board[5]==' '||board->board[8]==' ')return 0;
			else return 1;
		}
	}

	//diagonally - 2 diagonals
	if(board->board[0]==board->board[4]){
		if(board->board[4]==board->board[7]){
			if(board->board[1]==' '||board->board[4]==' '||board->board[7]==' ')return 0;
			else return 1;
		}
	}
	if(board->board[2]==board->board[5]){
		if(board->board[5]==board->board[8]){
			if(board->board[2]==' '||board->board[5]==' '||board->board[8]==' ')return 0;
			else return 1;
		}
	}

	return 0;
}

boolean isDraw(Board* board){
	if(isBoardFull(board)&&!isWin(board))return 1;
	return 0;
}

/*boolean isGameOver(char* board){
	if(isWin(board) || isDraw(board))return 1;
	return 0;
}*/

int inputError(Board* board,int position)
{
	if(board->board[position-1]!=' ')
		return -1;

	if(position>9||position<1)
		return 1;
		
	return 0;
}

void gameClose(Board* board, char* player){
	free(board->board);
	free(player);
}

