#include "structs.h"

void everFALL (int nrRows,int nrCols){ //nome do jogo na parte de baixo
    attron(COLOR_PAIR(11));
    mvprintw(nrRows - 7, ((nrCols - 40) / 2) - 34, "                                           _|_|_|_|    _|_|    _|        _|        ");
    attron(COLOR_PAIR(12));
    mvprintw(nrRows - 6, ((nrCols - 40) / 2) - 34, "   _|_|    _|      _|    _|_|    _|  _|_|  _|        _|    _|  _|        _|        ");
    attron(COLOR_PAIR(13));
    mvprintw(nrRows - 5, ((nrCols - 40) / 2) - 34, " _|_|_|_|  _|      _|  _|_|_|_|  _|_|      _|_|_|    _|_|_|_|  _|        _|        ");
    attron(COLOR_PAIR(14));
    mvprintw(nrRows - 4, ((nrCols - 40) / 2) - 34, " _|          _|  _|    _|        _|        _|        _|    _|  _|        _|        ");
    attron(COLOR_PAIR(15));
    mvprintw(nrRows - 3, ((nrCols - 40) / 2) - 34, "   _|_|_|      _|        _|_|_|  _|        _|        _|    _|  _|_|_|_|  _|_|_|_|  ");
}

void healthBar(int nrCols, JOGADOR jog) { //barra de hp
    attron(COLOR_PAIR(20));
    for (int i = 34; i >= 35 - (jog.hpJ / 4); i--) {
        mvprintw(3, nrCols - i, "-");
    }
    attroff(COLOR_PAIR(20));
    
    attron(COLOR_PAIR(22));
    for (int i = 34 - (jog.hpJ / 4); i >= 10; i--) {
        mvprintw(3, nrCols - i, "-");
    }
    attroff(COLOR_PAIR(22)); 
}

void manaBar(int nrCols, JOGADOR jog) { //barra de mp
    attron(COLOR_PAIR(21));
    for (int i = 34; i >= 35 - (jog.mpJ / 4); i--) {
        mvprintw(6, nrCols - i, "-");
    }
    attroff(COLOR_PAIR(21));
    
    attron(COLOR_PAIR(23));
    for (int i = 34 - (jog.mpJ / 4); i >= 10; i--) {
        mvprintw(6, nrCols - i, "-");
    }
    attroff(COLOR_PAIR(23)); 
}

void vidaJogador (int nrCols,JOGADOR jog,STATE st){ //caixa com os elementos importantes
    int i;
    attron (COLOR_PAIR(14));
    mvprintw (1,nrCols-37, "+---------------------------------+");
    mvprintw (14,nrCols-37,"+---------------------------------+");
    
    for(i = 2;i<14;i++){
        mvprintw (i,nrCols-37,"|");
        mvprintw (i,nrCols-3,"|");
        }
    attroff (COLOR_PAIR(14));
    
    mvprintw (2,nrCols-36, "  HP: %d/100 ",jog.hpJ); 
   
    mvprintw (5,nrCols-36, "  MP: %d/100 ",jog.mpJ);

    mvprintw (8,nrCols-36, "  PONTOS: %d",jog.points);   

    mvprintw (11,nrCols-36,"  Coordenadas: (%d,%d)", st.playerX, st.playerY);
}