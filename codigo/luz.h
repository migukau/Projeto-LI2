#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define COLOR_BABY_BLUE 170

void luz(int nRows, int nCols, char map[nRows][nCols], int playerX, int playerY) {
    int row, col;

    for (row = 0; row < nRows-9 ; row++) {
        for (col = 0; col < nCols-39; col++) {

            double distance = sqrt(pow(row - playerX, 2) + pow(col - playerY, 2));

            if (distance <= 5) {
                if(row==playerX && col ==playerY) {}// Se as coordenadas forem as do jogador nao desenha nada
            
                else if (map[row][col] == '#') {
                    mvaddch(row, col, '#' | A_BOLD);
                }

                else if (map[row][col] == '.') {
                    mvaddch(row, col, '.' | A_BOLD);
                }

                else if (map[row][col] == 'O') {
                    attron(COLOR_PAIR(COLOR_BLUE));
                    mvaddch(row, col, 'O' | A_BOLD);
                    attroff(COLOR_PAIR(COLOR_BLUE));
                }

                else if (map[row][col] == 'H') {
                    attron(COLOR_PAIR(COLOR_YELLOW));
                    mvaddch(row, col, 'H' | A_BOLD);
                    attroff(COLOR_PAIR(COLOR_YELLOW));
                }

                else if (map[row][col] == '+') {
                    attron(COLOR_PAIR(COLOR_GREEN));
                    mvaddch(row, col, '+' | A_BOLD);
                    attroff(COLOR_PAIR(COLOR_GREEN));
                }

                else if (map[row][col] == '^') {
                    attron(COLOR_PAIR(COLOR_RED));
                    mvaddch(row, col, '^' | A_BOLD);
                    attroff(COLOR_PAIR(COLOR_RED));
                }
            }
        }
    }
}