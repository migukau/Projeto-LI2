#include <stdio.h>
#include <stdlib.h>

void geraMapa(int nrRows,int nrCols,char map[nrRows][nrCols],int parede[nrRows][nrCols],int *xJ,int *yJ){
    srand48(time(NULL));

    int r,c,vezes,tempX,tempY;

    char mapaTemp[nrRows][nrCols];

    for (r=0; r<nrRows - 9; r++){//limpa a area de jogo para depois ser gerado um novo mapa
   	    for (c=0; c<nrCols - 39; c++){
            printw("%c",' ');
        }
    }

    for (r=0; r<nrRows; r++){ 
   	    for(c=0; c<nrCols; c++){
   		    if ((drand48())<0.45){ //mapa aleatório com 45% de paredes
   			    map[r][c]='#';
   		    }
   		    else{
   			    map[r][c]='.';
   		    }
   	    }
    }

    for (r=0; r<nrRows; r++){
   	    for (c=0; c<nrCols; c++){
            mapaTemp[r][c] = map[r][c]; //uso de um mapa temporário 
   	    }
    }

    for (vezes=0; vezes<6; vezes++) {
        for (r=2; r<(nrRows-2); r++){
            for (c=2; c<(nrCols-2); c++){
                int contador=0;
                int conta = 0;
                contador = ( (map[r-1][c-1]=='#') + (map[r][c-1]=='#') + (map[r+1][c-1]=='#') + (map[r-1][c]=='#') + (map[r+1][c]=='#') + (map[r-1][c+1]=='#') + (map[r][c+1]=='#') + (map[r+1][c+1]=='#')); //conta paredes com 1 de raio 
                if (r-2>0 && r+2<nrRows && c-2>0 && c+2<nrCols) {
                    for (int lin=r-2;lin<r+3;lin++) {
                        for (int col=c-2;col<c+3;col++) {
                            if (map[lin][col] == '#')
                                conta++; //conta paredes com 2 de raio
                        }
                    }
                }
                if (contador>=5 || conta <= 2) //atualiza o mapa temporário
                    mapaTemp[r][c]='#';
                else
                    mapaTemp[r][c]='.';
            }
        }
        for (r=0; r<nrRows; r++){
            for (c=0; c<nrCols; c++){
                map[r][c] = mapaTemp[r][c]; //passagem para o mapa original
            }
        }
    }

    for (vezes=0; vezes<1; vezes++) {        
        for (r=2; r<(nrRows-2); r++){
            for (c=2; c<(nrCols-2); c++){
                int contador=0;
                contador = ( (map[r-1][c-1]=='#') + (map[r][c-1]=='#') + (map[r+1][c-1]=='#') + (map[r-1][c]=='#') + (map[r+1][c]=='#') + (map[r-1][c+1]=='#') + (map[r][c+1]=='#') + (map[r+1][c+1]=='#')); //conta paredes com 1 de raio
                if (contador>=5)
                    mapaTemp[r][c]='#';
                else
                    mapaTemp[r][c]='.';
            }
        }
        for (r=0; r<nrRows; r++){
            for (c=0; c<nrCols; c++){
                map[r][c] = mapaTemp[r][c]; //passagem para o mapa original
            }
        }
    }

    for (r=0; r<nrRows; r++){
   	    map[r][0]='#'; //paredes na parte esquerda
    }


    for (r=0; r<nrRows; r++){
   	    map[r][nrCols-40]='#'; //paredes na parte direita        
    }


    for (c=0; c<nrCols; c++){
   	    map[0][c]='#'; //paredes na parte superior
    }


    for (c=0; c<nrCols; c++){
   	    map[nrRows-10][c]='#'; //paredes na parte inferior       
    }

    for (r=0; r<nrRows - 9; r++){
   	    for (c=0; c<nrCols - 39; c++){
            if (map[r][c] == '#') //matriz para ver se é parede ou não
                parede[r][c]=1;
            else
                parede[r][c]=0;
   	    }
    }

    for (int picos=0;picos<10;picos++) {//gera os picos em coordenadas aleatórias que nao sejam uma parede ou outro obstáculo
            tempX=random() % (nrRows - 11);
		    tempY=random() % (nrCols - 41);

        	if(parede[tempX][tempY]==0) map[tempX][tempY]='^';
	}

	for (int vidas=0;vidas<5;vidas++) {//gera as vidas em coordenadas aleatórias que nao sejam uma parede ou outro obstáculo
            tempX=random() % (nrRows - 11);
		    tempY=random() % (nrCols - 41);

        	if (parede[tempX][tempY]==0) map[tempX][tempY]='+';
	}

    do { //gera um buraco em coordenadas aleatórias que não sejam uma parede ou outro obstáculo
        tempX=random() % (nrRows - 11);
		tempY=random() % (nrCols - 41);

        if(parede[tempX][tempY]==0) map[tempX][tempY]='O';

   	} while (parede[tempX][tempY] != 0);

    do { //gera uma escada em coordenadas aleatórias que não sejam uma parede ou um buraco ou outro obstáculo
        tempX=random() % (nrRows - 11);
		tempY=random() % (nrCols - 41);

        if (parede[tempX][tempY]==1) map[tempX][tempX]='H';
   	} while (parede[tempX][tempY] != 0);

    do { //gera o jogador em coordenadas aleatórias que não sejam uma parede
        *xJ = random() % (nrRows - 11);
        *yJ = random() % (nrCols - 41);
    } while (parede[*xJ][*yJ] != 0);

}