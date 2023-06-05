typedef struct state {
	int playerX;
	int playerY; 
} STATE; 

typedef struct jogador {
	STATE posJ;
	int hpJ;
	int mpJ;
	int points;
} JOGADOR;

typedef struct monstro {
    int vida;
    int mp;
    int monstroX;
    int monstroY;
} MONSTRO;