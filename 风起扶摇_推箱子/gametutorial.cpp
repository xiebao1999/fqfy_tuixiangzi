#include"gametutorial.h"
//添加了5张图片img_tutorial_a,img_tutorial_b,img_tutorial_c,img_tutorial_e
//新建了一个头文件,包含一个函数gametutorial()
//一个了全局变量t,在playergame中gametutorial()前初始化为1
void gametutorial() {

	if (t == 1) {
	initgraph(PL * 30, PL * 15);
	BeginBatchDraw();
	putimage(0, 0, &background);
	//游 戏 介 绍
	setfillcolor(GREEN);
	fillrectangle(PL * 2, PL * 1, PL * 10, PL * 14);
	setbkmode(TRANSPARENT);
	char s1[] = "游 戏 介 绍";
	char s2[] = "推箱子游戏1981年由日";
	char s3[] = "林宏行首创，是在1982年12";
	char s4[] = "月由Thinking Rabbit 公司";
	char s5[] = "首次发行，名“仓库番”。";
	char s6[] = "箱子只可以推, 不可以拉, ";
	char s7[] = "而且一次只能推动一个，胜";
	char s8[] = "利条件就是把所有的箱子";
	char s9[] = "都推到目的地。推箱子游戏";
	char s10[] = "是一种老少皆宜的益智游戏";
	char s11[] = "，既可以开发青少年学生的";
	char s12[] = "智力，又可以防止老年痴呆";
	char s13[] = "症，全家一起攻关促进和睦";
	settextstyle(20, 10, "宋体");
	outtextxy(110, 30 , s1);
	outtextxy(100, 60, s2);
	outtextxy(60, 90, s3);
	outtextxy(60, 120, s4);
	outtextxy(60,150,s5);
	outtextxy(60,180,s6);
	outtextxy(60,210,s7);
	outtextxy(60,240,s8);
	outtextxy(60,270,s9);
	outtextxy(60,300,s10);
	outtextxy(60,330,s11);
	outtextxy(60,360,s12);
	outtextxy(60,390,s13);

	//游戏教程

		setfillcolor(GREEN);
		fillrectangle(PL * 13, PL * 1, PL * 29, PL * 14);
		putimage(PL * 14, PL * 1, &img_tutorial_a);
		putimage(PL * 22, PL * 1, &img_tutorial_b);
		char t1[] = "1.玩法介绍：我们可以通过键盘上的上下左右键";
		char t2[] = "来操作人物进行移动与推动箱子。当所有箱子成功地被";
		char t3[] = "推到指定位置，即如上述图中所有箱子变为红色，则关";
		char t4[] = "卡成功";
		outtextxy(PL * 15, PL * 8, t1);
		outtextxy(PL * 13, PL * 9, t2);
		outtextxy(PL * 13, PL * 10, t3);
		outtextxy(PL * 13, PL * 11, t4);

		setfillcolor(YELLOW);
		settextcolor(BLACK);
		fillrectangle(PL * 13, PL * 13, PL * 16, PL * 14);
		fillrectangle(PL * 26, PL * 13, PL * 29, PL * 14);
		char t5[] = "  继 续";
		char t6[] = "  返 回";
		outtextxy(PL * 26, PL * 13, t5);
		outtextxy(PL * 13, PL * 13, t6);
	}
	
	else if (t == 2) {
		settextcolor(WHITE);
		setfillcolor(GREEN);
		fillrectangle(PL * 13, PL * 1, PL * 29, PL * 14);
		putimage(PL * 14, PL * 1, &img_tutorial_c);
		putimage(PL * 22, PL * 1, &img_tutorial_d);
		char t1[] = "2.游戏策略：因为关卡地图的复杂与差异，每一";
		char t2[] = "关箱子推到目的地的顺序是有所差异的，所以我们需要";
		char t3[] = "根据地图与目的地的位置找出箱子正确的归位循序与地";
		char t4[] = "点。如上述图中箱子顺序即可成功";
		outtextxy(PL * 15, PL * 8, t1);
		outtextxy(PL * 13, PL * 9, t2);
		outtextxy(PL * 13, PL * 10, t3);
		outtextxy(PL * 13, PL * 11, t4);

		setfillcolor(YELLOW);
		settextcolor(BLACK);
		fillrectangle(PL * 13, PL * 13, PL * 16, PL * 14);
		fillrectangle(PL * 26, PL * 13, PL * 29, PL * 14);
		char t5[] = "  继 续";
		char t6[] = "  返 回";
		outtextxy(PL * 26, PL * 13, t5);
		outtextxy(PL * 13, PL * 13, t6);
	}
	
	else if (t == 3) {
		settextcolor(WHITE);
		setfillcolor(GREEN);
		fillrectangle(PL * 13, PL * 1, PL * 29, PL * 14);
		putimage(PL * 14, PL * 1, &img_tutorial_d);
		putimage(PL * 22, PL * 1, &img_tutorial_e);
		char t1[] = "3.玩法提升：有些关卡存在不止一种的成功路径";
		char t2[] = "那么在不同的路径之中，我们可以去寻找人物所用步数";
		char t3[] = "最少的路径。如上述图中我们推动靠墙与不靠墙的箱子";
		char t4[] = "都可以成功，但图1的步数较少。我相信这可以很好地";
		char t5[] = "开发我们的智力。快开始游戏吧！";

		outtextxy(PL * 15, PL * 8, t1);
		outtextxy(PL * 13, PL * 9, t2);
		outtextxy(PL * 13, PL * 10, t3);
		outtextxy(PL * 13, PL * 11, t4);
		outtextxy(PL * 13, PL * 12, t5);
		setfillcolor(YELLOW);
		settextcolor(BLACK);
		fillrectangle(PL * 13, PL * 13, PL * 16, PL * 14);
		char t6[] = "  返 回";
		outtextxy(PL * 13, PL * 13, t6);
	}
	ExMessage n;
	FlushBatchDraw();
	while (1) {
		n = getmessage(EM_MOUSE);
		if (n.message == WM_LBUTTONDOWN) {
			if (n.x >= PL * 26 && n.x <= PL * 29 && n.y >= PL * 13 && n.y <= PL * 14) {
				t++;
				gametutorial();
				return;
			}
			else if (n.x >= PL * 13 && n.x <= PL * 16 && n.y >= PL * 13 && n.y <= PL * 14) {
				return;
			}
		}
	}

	EndBatchDraw();
}
