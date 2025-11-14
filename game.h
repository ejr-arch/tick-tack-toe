typedef enum {
    FALSE = 0,
    TRUE = 1
}BOOLEAN;

void move(int c,char p_player, char c_player);
char turn(char p_player,char c_player);
void display();
BOOLEAN game_won(char c_player, char p_player);
BOOLEAN game_over();

