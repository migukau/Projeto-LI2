#include "structs.h"   

void vistaMapa(int nrRows,int nrCols,char map[nrRows][nrCols],int visao[nrRows][nrCols],int percorrido[nrRows][nrCols]) {

    attron(COLOR_PAIR(COLOR_WHITE));
    int r,c;

    for (r=0; r<nrRows - 9; r++){
   	    for (c=0; c<nrCols - 39; c++){
            attron(COLOR_PAIR(COLOR_BLACK));
            printw("%c",map[r][c]);
            attroff(COLOR_PAIR(COLOR_BLACK));
        }
        printw("\n");
    }

    move(0,0);

    for (r=0; r<nrRows - 9; r++){
   	    for (c=0; c<nrCols - 39; c++){
            if (map[r][c] == '^' && visao[r][c] == 1) {
                attron(COLOR_PAIR(COLOR_RED));
                printw("%c",map[r][c]);
                attroff(COLOR_PAIR(COLOR_RED));
            }
            else {
                if (map[r][c] == '+' && visao[r][c] == 1) {
                    attron(COLOR_PAIR(COLOR_GREEN));
                    printw("%c",map[r][c]);
                    attroff(COLOR_PAIR(COLOR_GREEN));
                }
                else {
                    if (map[r][c] == 'O' && visao[r][c] == 1) {
                        attron(COLOR_PAIR(COLOR_BLUE));
                        printw("%c",map[r][c]);
                        attroff(COLOR_PAIR(COLOR_BLUE));
                    }
                    else {
                        if (map[r][c] == 'H' && visao[r][c] == 1) {
                            attron(COLOR_PAIR(COLOR_BLUE));
                            printw("%c",map[r][c]);
                            attroff(COLOR_PAIR(COLOR_BLUE));
                        }
                        else {
                            if (visao[r][c] == 1) {
                                attron(COLOR_PAIR(COLOR_WHITE));
                                printw("%c",map[r][c]); //imprime o mapa
                                attroff(COLOR_PAIR(COLOR_WHITE));
                            }
                            else {
                                if (percorrido[r][c] == 1 && visao[r][c] == 1) {
                                    attron(COLOR_PAIR(COLOR_YELLOW));
                                    printw("%c",map[r][c]); //imprime o mapa
                                    attroff(COLOR_PAIR(COLOR_YELLOW));
                                }
                            }
                        }
                    }
   	            }
            }
        }
        printw("\n");
    }
    attroff(COLOR_PAIR(COLOR_WHITE));
}