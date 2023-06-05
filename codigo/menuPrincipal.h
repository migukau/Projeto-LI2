void menuPrincipal (int nrRows, int nrCols){
  attron(COLOR_PAIR(31));
 mvprintw (nrRows/2-4,nrCols/5,"8 8888888888 `8.`888b           ,8' 8 8888888888   8 888888888o.   8 8888888888       .8.          8 8888         8 8888        ");
 mvprintw (nrRows/2-3,nrCols/5,"8 8888        `8.`888b         ,8'  8 8888         8 8888    `88.  8 8888            .888.         8 8888         8 8888        ");
 mvprintw (nrRows/2-2,nrCols/5,"8 8888         `8.`888b       ,8'   8 8888         8 8888     `88  8 8888           :88888.        8 8888         8 8888        ");
 mvprintw (nrRows/2-1,nrCols/5,"8 8888          `8.`888b     ,8'    8 8888         8 8888     ,88  8 8888          . `88888.       8 8888         8 8888        ");
  attroff(COLOR_PAIR(31));

  attron (COLOR_PAIR(33));
 mvprintw (nrRows/2-0,nrCols/5,"8 888888888888   `8.`888b   ,8'     8 888888888888 8 8888.   ,88'  8 888888888888 .8. `88888.      8 8888         8 8888        ");
  attroff (COLOR_PAIR(33));
  
  attron (COLOR_PAIR(35));
 mvprintw (nrRows/2+1,nrCols/5,"8 8888            `8.`888b ,8'      8 8888         8 888888888P'   8 8888        .8`8. `88888.     8 8888         8 8888        ");
  attroff(COLOR_PAIR(35));
  
  attron(COLOR_PAIR(34));
 mvprintw (nrRows/2+2,nrCols/5 ,"8 8888             `8.`888b8'       8 8888         8 8888`8b       8 8888       .8' `8. `88888.    8 8888         8 8888        ");
 mvprintw (nrRows/2+3,nrCols/5 ,"8 8888              `8.`888'        8 8888         8 8888 `8b.     8 8888      .8'   `8. `88888.   8 8888         8 8888        ");
 mvprintw (nrRows/2+4,nrCols/5 ,"8 8888               `8.`8'         8 8888         8 8888   `8b.   8 8888     .888888888. `88888.  8 8888         8 8888        "); 
 mvprintw (nrRows/2+5,nrCols/5 ,"8 888888888888        `8.`          8 888888888888 8 8888     `88. 8 8888    .8'       `8. `88888. 8 888888888888 8 888888888888"); 
  attroff(COLOR_PAIR(34));
}