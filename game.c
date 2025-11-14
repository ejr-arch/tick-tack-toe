#include<stdio.h>
#include"game.h"

char board[3][3]={
			{' ',' ',' '},
			{' ',' ',' '},
			{' ',' ',' '}
};


void move(int c,char p_player,char c_player){
	switch(c){
		case 1:
			board[0][0]=c_player;
		break;
		case 2:
			board[0][1]=c_player;
		break;
		case 3:	
			board[0][2]=c_player;
                break;
		case 4:
			board[1][0]=c_player;
		break;
		case 5:
			board[1][1]=c_player;
	        break;
		case 6:
			board[1][2]=c_player;
                break;
		case 7:
			board[2][0]=c_player;
                break;
		case 8:
			board[2][1]=c_player;
                break;
		case 9:
			board[2][2]=c_player;
		break;
		default:
			printf("Invalid move\n");
	}
}

void display(){
	printf("|%c||%c||%c|\n|%c||%c||%c|\n|%c||%c||%c|\n",board[0][0],board[0][1],board[0][2],board[1][0],board[1][1],board[1][2],board[2][0],board[2][1],board[2][2]);
}

char turn(char p_player,char c_player){
	if(p_player=='X')c_player='O';
	else c_player='X';
	return c_player;
}

BOOLEAN game_over(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == ' ')
                return FALSE;  // still moves left
        }
    }
    return TRUE;  // no empty spaces -> draw
}


BOOLEAN game_won(char c_player, char p_player){
	if(
	(board[0][0]==c_player && board[1][1]==c_player && board[2][2]==c_player) ||	//left diagonal
	(board[0][2]==c_player && board[1][1]==c_player && board[2][0]==c_player) ||	//right diagonal
	(board[0][1]==c_player && board[1][1]==c_player && board[2][1]==c_player) ||	//center column
	(board[0][0]==c_player && board[1][0]==c_player && board[2][0]==c_player) ||	//left column
	(board[0][2]==c_player && board[1][2]==c_player && board[2][2]==c_player) ||	//right column
	(board[0][0]==c_player && board[0][1]==c_player && board[0][2]==c_player) ||	//upper row
	(board[1][0]==c_player && board[1][1]==c_player && board[1][2]==c_player) ||	//middle row
	(board[2][0]==c_player && board[2][1]==c_player && board[2][2]==c_player)	//lower row 
	){
		printf("%c won,%c lost\n",c_player,p_player);
		return TRUE;
	}
	else{
		printf("draw\n");
		return FALSE;
	}
}

