void alteraVida(STATE st,JOGADOR *jog,int nrRows,int nrCols,char map[nrRows][nrCols]) {
    if (map[st.playerX][st.playerY]=='^' && jog->hpJ != 0) {jog->hpJ -=4;}

	if (map[st.playerX][st.playerY]=='+' && jog->hpJ < 100) {
        jog->hpJ +=4; map[st.playerX][st.playerY] = '.';
        }
}