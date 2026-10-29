#include <stdlib.h>
#include "ticktacktoe.h"

Board* createBoard(void){
	Board* board = (Board*)malloc(sizeof(Board));
	for(int i=0;i<9;i++)board->cells[i]=' ';
	board->emptyCells = 9;
	return board;
}

void play(Board* board, char player, int position)
{
	board->cells[position-1] = player;
	board->emptyCells--;
}

char nextPlayer(char player){
	return player == 'X'? 'O': 'X';
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
		{0,4,8},{2,4,6} //diagonal lines
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

inputState checkInput(Board* board,int position)
{
	if(position>9||position<1)
		return INPUT_OUT_OF_RANGE;

	if(board->cells[position-1]!=' ')
		return INPUT_OCCUPIED;	
		
	return INPUT_OK;
}

void gameClose(Board* board){
	free(board);
}

