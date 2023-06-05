#include <stdio.h>
#include <stdlib.h>


void criaMonstros(int ncols,int nrows,int parede[nrows][ncols],char monstros[nrows][ncols]) {
    MONSTRO mons1,mons2,mons3,mons4,mons5,mons6,mons7,mons8,mons9,mons10,mons11,mons12,mons13,mons14,mons15;
    mons1.monstroX = rand() % ncols;
    mons1.monstroY = rand() % nrows;
    mons2.monstroX = rand() % ncols;
    mons2.monstroY = rand() % nrows;
    mons3.monstroX = rand() % ncols;
    mons3.monstroY = rand() % nrows;
    mons4.monstroX = rand() % ncols;
    mons4.monstroY = rand() % nrows;
    mons5.monstroX = rand() % ncols;
    mons5.monstroY = rand() % nrows;
    mons6.monstroX = rand() % ncols;
    mons6.monstroY = rand() % nrows;
    mons7.monstroX = rand() % ncols;
    mons7.monstroY = rand() % nrows;
    mons8.monstroX = rand() % ncols;
    mons8.monstroY = rand() % nrows;
    mons9.monstroX = rand() % ncols;
    mons9.monstroY = rand() % nrows;
    mons10.monstroX = rand() % ncols;
    mons10.monstroY = rand() % nrows;
    mons11.monstroX = rand() % ncols;
    mons11.monstroY = rand() % nrows;
    mons12.monstroX = rand() % ncols;
    mons12.monstroY = rand() % nrows;
    mons13.monstroX = rand() % ncols;
    mons13.monstroY = rand() % nrows;
    mons14.monstroX = rand() % ncols;
    mons14.monstroY = rand() % nrows;
    mons15.monstroX = rand() % ncols;
    mons15.monstroY = rand() % nrows;
    if (parede[mons1.monstroX][mons1.monstroY]==0)
        monstros[mons1.monstroX][mons1.monstroY] = 'X';
    if (parede[mons2.monstroX][mons2.monstroY]==0)
        monstros[mons2.monstroX][mons2.monstroY] = 'X';
    if (parede[mons3.monstroX][mons3.monstroY]==0)
        monstros[mons3.monstroX][mons3.monstroY] = 'X';
    if (parede[mons4.monstroX][mons4.monstroY]==0)
        monstros[mons4.monstroX][mons4.monstroY] = 'X';
    if (parede[mons5.monstroX][mons5.monstroY]==0)
        monstros[mons5.monstroX][mons5.monstroY] = 'X';
    if (parede[mons6.monstroX][mons6.monstroY]==0)
        monstros[mons6.monstroX][mons6.monstroY] = 'X';
    if (parede[mons7.monstroX][mons7.monstroY]==0)
        monstros[mons7.monstroX][mons7.monstroY] = 'X';
    if (parede[mons8.monstroX][mons8.monstroY]==0)
        monstros[mons8.monstroX][mons8.monstroY] = 'X';
    if (parede[mons9.monstroX][mons9.monstroY]==0)
        monstros[mons9.monstroX][mons9.monstroY] = 'X';
    if (parede[mons10.monstroX][mons10.monstroY]==0)
        monstros[mons10.monstroX][mons10.monstroY] = 'X';
    if (parede[mons11.monstroX][mons11.monstroY]==0)
        monstros[mons11.monstroX][mons11.monstroY] = 'X';
    if (parede[mons12.monstroX][mons12.monstroY]==0)
        monstros[mons12.monstroX][mons12.monstroY] = 'X';
    if (parede[mons13.monstroX][mons13.monstroY]==0)
        monstros[mons13.monstroX][mons13.monstroY] = 'X';
    if (parede[mons14.monstroX][mons14.monstroY]==0)
        monstros[mons14.monstroX][mons14.monstroY] = 'X';
    if (parede[mons15.monstroX][mons15.monstroY]==0)
        monstros[mons15.monstroX][mons15.monstroY] = 'X';
}