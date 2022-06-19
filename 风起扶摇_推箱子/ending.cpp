#include"ending.h"

void printending() {
	
	initgraph(PL * 30, PL * 15, EW_SHOWCONSOLE);
	BeginBatchDraw();
	int t1 = PL * 30, t2 = PL * 15;
	putimage(0, 0, &background);
	setbkmode(TRANSPARENT);
	char s1[] = "关卡成功";
	char s2[] = "下一关";
	char s3[] = "返回开始界面";
	char s4[] = "用时：02分30秒";
	settextcolor(RED);
	settextstyle(40, 20, _T("仿宋体"));
	outtextxy(t1 / 2 - 80, t2 / 10, s1);
	settextstyle(20, 10, _T("仿宋体"));
	outtextxy(t1 / 2 - 70, t2 / 10 + 40, s4);
	settextcolor(BLACK);
	settextstyle(40, 20, _T("宋体"), 0, 0, 500, 0, 0, 0);
	outtextxy(t1 / 2 - 60, t2 / 5 * 2 + 10, s2);
	outtextxy(t1 / 2 - 120, t2 / 5 * 3 + 20, s3);
	ExMessage m;
	FlushBatchDraw();
	while (1) {
		m = getmessage(EM_MOUSE);
		if (m.message == WM_LBUTTONDOWN) {
			if (m.x >= t1 / 2 - 60 && m.x <= t1 / 2 + 60 && m.y >= t2 / 5 * 2 + 10 && m.y <= t2 / 5 * 2 + 60) {
				//下一关
				//标识符 flag == 1;
				current_level++;
				setmap();
				return;
			}
			if (m.x >= t1 / 2 - 120 && m.x <= t1 / 2 + 120 && m.y >= t2 / 5 * 3 + 20 && m.y <= t2 / 5 * 3 + 70) {

				flag = 0;
				return;
			}
		}
	}
	
	EndBatchDraw();
}