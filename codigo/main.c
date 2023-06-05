#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include "structs.h"
#include "geraMapa.h"
#include "moveJogador.h"
#include "vidaJogador.h"
#include "alteraVida.h"
#include "gameOver.h"
#include "menuPrincipal.h"
#include "luz.c"

#define COLOR_CRIMSON 100
#define COLOR_LIGHT_ORANGE 110
#define COLOR_LIGHT_YELLOW 120
#define COLOR_LIGHT_RED 130
#define COLOR_REAL_YELLOW 140
#define COLOR_LIGHT_PINK 150
#define COLOR_PINK 160
#define COLOR_BABY_BLUE 170
      
int main() {
	WINDOW *wnd = initscr();

	curs_set(0);
	int ncols, nrows, xJ, yJ;
	getmaxyx(wnd,nrows,ncols);

	char playerChar = '@';
	char map[nrows][ncols];
	int parede[nrows][ncols];

	srandom(time(NULL));
	start_color();
 
	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, false);
	keypad(stdscr, true);

	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
  
    init_pair(11,COLOR_CRIMSON,COLOR_BLACK);
    init_pair(12,COLOR_LIGHT_RED, COLOR_BLACK);
    init_pair(13,COLOR_LIGHT_ORANGE, COLOR_BLACK);
    init_pair(14,COLOR_REAL_YELLOW,COLOR_BLACK);
    init_pair(15,COLOR_LIGHT_YELLOW,COLOR_BLACK);

    init_pair(31,COLOR_CYAN,COLOR_BLACK);
	init_pair(32,COLOR_BABY_BLUE,COLOR_BLACK);
	init_pair(33,COLOR_BABY_BLUE,COLOR_BLACK);
	init_pair(34,COLOR_PINK,COLOR_BLACK);
	init_pair(35,COLOR_LIGHT_PINK,COLOR_BLACK);
	init_pair(36,COLOR_MAGENTA,COLOR_BLACK);

    init_pair(20,COLOR_GREEN,COLOR_GREEN);             //Vida
    init_pair(21,COLOR_CYAN,COLOR_CYAN);               //Mana
    init_pair(22,COLOR_CRIMSON,COLOR_CRIMSON);         //Sem Vida
    init_pair(23,COLOR_MAGENTA,COLOR_MAGENTA);         //Sem Mana
    init_pair(30,COLOR_WHITE, COLOR_BLACK);

    init_color(140, 1000, 1000 , 0);  				   //yellow
    init_color(100, 500, 0, 0);                        //crimson
    init_color(110, 1000, 500, 100);  				   //light orange
    init_color(120, 850, 850, 500);  				   //light yellow
    init_color(130, 1000, 300, 300);                   //light red
    init_color(150, 1000, 850, 850);  				   //baby pink
    init_color(160, 855, 350, 750);   				   //pink
    init_color(170,750, 1000, 1000);  			       //baby blue

	menuPrincipal(nrows,ncols);

	int key = getch();
	curs_set(1);
	switch(key) {}
	move(0,0);

	geraMapa(nrows,ncols,map,parede,&xJ,&yJ);

	STATE st;
    
	st.playerX = xJ;
	st.playerY = yJ;

	JOGADOR jog;
	jog.hpJ = 100;
	jog.mpJ = 100;
	jog.points = 0;
	
	while(1) {
 		curs_set(1);

		if(jog.hpJ == 0) {
			curs_set(0);
			move(0,0);
			gameOver(nrows,ncols,map);
			map[st.playerX][st.playerY]= ' ';
			playerChar = ' ';
		}

		if(jog.hpJ <= 20 && map[st.playerX][st.playerY] == 'O') {
			curs_set(0);
			move(0,0);
			jog.hpJ = 0;
			gameOver(nrows,ncols,map);

		}

		if (map[st.playerX][st.playerY] == 'H' && jog.hpJ != 0) {
			move(0,0);
			for (int r=0; r<nrows - 9; r++){
   	    		for (int c=0; c<ncols - 39; c++){
            		printw("%c",' ');
        		}
    		}
			geraMapa(nrows,ncols,map,parede,&xJ,&yJ);
			st.playerX = xJ;
			st.playerY = yJ;

			jog.points += 100;
		}
		if (map[st.playerX][st.playerY] == 'O' && jog.hpJ > 20) {
			move(0,0);
			for (int r=0; r<nrows - 9; r++){
   	    		for (int c=0; c<ncols - 39; c++){
            		printw("%c",' ');
        		}
    		}
			geraMapa(nrows,ncols,map,parede,&xJ,&yJ);
			jog.hpJ -= 20;
			jog.points += 200;
			
			st.playerX = xJ;
			st.playerY = yJ;
		}

		everFALL(nrows,ncols);
		alteraVida(st,&jog,nrows,ncols,map);
   		attron(COLOR_PAIR(COLOR_WHITE));
		mvaddch(st.playerX, st.playerY, playerChar | A_BOLD);
 		attroff(COLOR_PAIR(COLOR_WHITE));
		healthBar(ncols,jog);
		manaBar(ncols,jog);
		vidaJogador(ncols,jog,st);
		luz(nrows,ncols,map,st.playerX,st.playerY);
		move(st.playerX, st.playerY);
		moveJogador(&st,ncols,nrows,parede,jog.hpJ);
	}
	endwin();
	return 0;
}