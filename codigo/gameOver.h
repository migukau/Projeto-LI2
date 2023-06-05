void gameOver (int nrRows,int nrCols,char map[nrRows][nrCols]) {
    for (int r=0; r<nrRows; r++){
        for (int c=0; c<nrCols; c++){
          map[r][c] = ' ';
        }
    }
    for (int r=0; r<nrRows; r++){
        for (int c=0; c<nrCols; c++){
          printw("%c",map[r][c]); //imprime o mapa
        }
        printw("\n");
    }
    attron(COLOR_PAIR(11));
    mvprintw((nrRows/2)-2, (nrCols/6), "     _/_/_/         _/_/        _/      _/       _/_/_/_/                   _/_/      _/      _/       _/_/_/_/       _/_/_/");
    attroff(COLOR_PAIR(11));
    attron(COLOR_PAIR(12));
    mvprintw((nrRows/2)-1, (nrCols/6), "  _/             _/    _/      _/_/  _/_/       _/                       _/    _/    _/      _/       _/             _/    _/");
    attroff(COLOR_PAIR(12));
    attron(COLOR_PAIR(13));
    mvprintw((nrRows/2) , (nrCols/6), "_/  _/_/        _/_/_/_/      _/  _/  _/       _/_/_/                   _/    _/    _/      _/       _/_/_/         _/_/_/");
    attroff(COLOR_PAIR(13));
    attron(COLOR_PAIR(14));
    mvprintw((nrRows/2)+1, (nrCols/6), "_/    _/       _/    _/      _/      _/       _/                       _/    _/      _/  _/         _/             _/    _/");
    attroff(COLOR_PAIR(14));
    attron(COLOR_PAIR(15));
    mvprintw((nrRows/2)+2, (nrCols/6), " _/_/_/       _/    _/      _/      _/       _/_/_/_/                   _/_/          _/           _/_/_/_/       _/    _/");
    attroff(COLOR_PAIR(15));
}