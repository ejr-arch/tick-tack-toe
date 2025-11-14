#include<stdio.h>
#include"game.h"
int main(){
	char p_player='X',c_player='O';
	int c;
	//printf("Player 1: %c\nPlayer 2: %c\n",p_player,c_player);
	do{
		display();
		printf("%c's turn\n",c_player);
		printf("Enter the position: ");
		scanf("%d",&c);
		move(c,p_player,c_player);
		if(game_won(c_player,p_player))break;
		p_player=c_player;
		c_player=turn(p_player,c_player);
	}while(!game_won(c_player,p_player) && !game_over());

	return 0;
}
