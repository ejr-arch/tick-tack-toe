#include <stdio.h>
#include <stdlib.h>
#include "ticktacktoe.h"

Board* createBoard(){
	Board* board = (Board*)malloc(sizeof(Board));
	for(int i=0;i<9;i++)board->cells[i]=' ';
	board->emptyCells = 9;
	return board;
}

/*char* createPlayer(){
	char* player = malloc(sizeof(char));
	player[0] = 'O';
	return player;
}
*/
void drawBoard(Board* board)
{	

	printf("|%c| |%c| |%c|\n|%c| |%c| |%c|\n|%c| |%c| |%c|\n",board->cells[0],board->cells[1],board->cells[2],board->cells[3],board->cells[4],board->cells[5],board->cells[6],board->cells[7],board->cells[8]);

}


void play(Board* board, char player, int position)
{
	board->cells[position-1] = player;
	board->emptyCells--;
}

void nextPlayer(char player){
	if(player=='X')
		player = 'O';
	else player = 'X';
}

bool isBoardFull(Board* board){
	if(board->emptyCells == 0)return true;
	return false;
}

bool isWin(Board* board){
	int i;
	char a;
	//horizontally - 3 rows
	int winDirections[8][3]={
		
		{0,1,2},{3,4,5},{6,7,8}, //horizontal lines
		{0,3,6},{1,4,7},{2,5,8}, //vertical lines
		{0,4,8},{2,4,6}
	};

	for(i=0;i<8;i++){
		a = board->cells[winDirections[i][0]];
		if(a!=' ' && a == board->cells[winDirections[i][1]] && a == board->cells[winDirections[i][2]]) return true;
	}
	return false;
}

bool isDraw(Board* board){
	if(!isWin(board) && isBoardFull(board)) return true;
	return false;
}

gameState checkGameState(Board* board){
	if(isWin(board)) return GAME_WON;
	else if(isDraw(board)) return GAME_DRAW;
	else return GAME_PLAYING;
}
/*bool isWin(Board* board)
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

bool isDraw(Board* board){
	if(isBoardFull(board)&&!isWin(board))return 1;
	return 0;
	if(checkGameState(board)== GAME_DRAW) return 1;
	return 0;
}

bool isGameOver(char* board){
	if(isWin(board) || isDraw(board))return 1;
	return 0;
}*/

inputState checkInput(Board* board,int position)
{
	if(board->cells[position-1]!=' ')
		return INPUT_OCCUPIED;

	if(position>9||position<1)
		return INPUT_OUT_OF_RANGE;
		
	return INPUT_OK;
}

void gameClose(Board* board){
	free(board);
}

