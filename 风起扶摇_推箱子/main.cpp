#include"source.h"
#include"playergame.h"
#include"player.h"
#include"set.h"

int main() {
	initgraph(PL * 30, PL * 15, EW_SHOWCONSOLE);
	setbkmode(TRANSPARENT);
	loading();
	//music(music_mode);
	while (1) {
		cleardevice();
		BeginBatchDraw();
		putimage(0, 0, &img_start);
		setfillcolor(BROWN);
		menu();
		FlushBatchDraw();
		EndBatchDraw();
	}
}