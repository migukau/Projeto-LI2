void do_movement_action(STATE *st, int dx, int dy) {
	st->playerX += dx;
	st->playerY += dy; 
}
 
void moveJogador(STATE *st,int ncols,int nrows,int parede[nrows][ncols],int hp) { 
	int key = getch();

	if (hp!=0) {
		mvaddch(st->playerX, st->playerY, ' ');
		switch(key) {
			case KEY_A1:
			case '7': if (parede[st->playerX - 1][st->playerY - 1] == 0) {do_movement_action(st, -1, -1);} break;
			case KEY_UP:
			case '8': if (parede[st->playerX - 1][st->playerY + 0] == 0) {do_movement_action(st, -1, +0);} break;
			case KEY_A3:
			case '9': if (parede[st->playerX - 1][st->playerY + 1] == 0) {do_movement_action(st, -1, +1);} break;
			case KEY_LEFT:
			case '4': if (parede[st->playerX + 0][st->playerY - 1] == 0) {do_movement_action(st, +0, -1);} break;
			case KEY_B2: 
			case '5': break;
			case KEY_RIGHT:
			case '6': if (parede[st->playerX + 0][st->playerY + 1] == 0) {do_movement_action(st, +0, +1);} break;
			case KEY_C1:
			case '1': if (parede[st->playerX + 1][st->playerY - 1] == 0) {do_movement_action(st, +1, -1);} break;
			case KEY_DOWN:
			case '2': if (parede[st->playerX + 1][st->playerY + 0] == 0) {do_movement_action(st, +1, +0);} break;
			case KEY_C3:
			case '3': if (parede[st->playerX + 1][st->playerY + 1] == 0) {do_movement_action(st, +1, +1);} break;
			case 'q': endwin(); exit(0); break;
		}
	}
	switch(key) {
		case 'q': endwin(); exit(0); break;
	}
}