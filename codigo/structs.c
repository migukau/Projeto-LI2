typedef struct state { //coordenadas do jogador
	int playerX;
	int playerY; 
} STATE; 

typedef struct jogador { //estatísticas do jogador
	STATE posJ;
	int hpJ;
	int mpJ;
	int points;
} JOGADOR;

typedef struct monstro { //estatísticas do monstro
    int vida;
    int mp;
    int monstroX;
    int monstroY;
} MONSTRO;