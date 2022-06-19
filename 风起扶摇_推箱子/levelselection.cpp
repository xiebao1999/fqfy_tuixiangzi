#include"source.h"
#include"levelselection.h"
#include"button.h"

void Cover()    //打印标题
{
	RECT r = { 0,0,899,449 };
	settextcolor(RGB(0, 255, 20));
	settextstyle(40, 20, "宋体");
	drawtext(_T("选 择 关 卡"), &r, DT_CENTER || DT_TOP);
}

short printselectmap() {                           //打印整个关卡选择页面
	initgraph(PL * 30, PL * 15);
	/*IMAGE img1;
	loadimage(&img1, _T("D:\\1学习互助组\\image\\背景1.jpg"));
	outtextxy(0, 0, "宽度");
	putimage(0, 0, &img1);*/
	setbkmode(TRANSPARENT);
	setbkcolor(RGB(130, 130, 130));
	cleardevice();
	Cover();
	TxtButton f1("第一关", 110, 60, 220, 100, YELLOW, GREEN);
	f1.PaintButton();
	TxtButton f2("第二关", 250, 60, 360, 100, YELLOW, GREEN);
	f2.PaintButton();
	TxtButton f3("第三关", 390, 60, 500, 100, YELLOW, GREEN);
	f3.PaintButton();
	TxtButton f4("第四关", 530, 60, 640, 100, YELLOW, GREEN);
	f4.PaintButton();
	TxtButton f5("第五关", 670, 60, 780, 100, YELLOW, GREEN);
	f5.PaintButton();
	TxtButton f6("第六关", 110, 140, 220, 180, YELLOW, GREEN);
	f6.PaintButton();
	TxtButton f7("第七关", 250, 140, 360, 180, YELLOW, GREEN);
	f7.PaintButton();
	TxtButton f8("第八关", 390, 140, 500, 180, YELLOW, GREEN);
	f8.PaintButton();
	TxtButton f9("第九关", 530, 140, 640, 180, YELLOW, GREEN);
	f9.PaintButton();
	TxtButton f10("第十关", 670, 140, 780, 180, YELLOW, GREEN);
	f10.PaintButton();
	TxtButton blast("返回主菜单", 740, 390, 850, 430, YELLOW, GREEN);
	blast.PaintButton();
	MOUSEMSG mmsg;
	short hover1 = UNKNOWN;//识别鼠标是否在第1关按钮上
	short hover2 = UNKNOWN;//识别鼠标是否在第2关按钮上
	short hover3 = UNKNOWN;//识别鼠标是否在第3关按钮上
	short hover4 = UNKNOWN;//识别鼠标是否在第4关按钮上
	short hover5 = UNKNOWN;//识别鼠标是否在第5关按钮上
	short hover6 = UNKNOWN;//识别鼠标是否在第6关按钮上
	short hover7 = UNKNOWN;//识别鼠标是否在第7关按钮上
	short hover8 = UNKNOWN;//识别鼠标是否在第8关按钮上
	short hover9 = UNKNOWN;//识别鼠标是否在第9关按钮上
	short hover10 = UNKNOWN;//识别鼠标是否在第10关按钮上
	short hover11 = UNKNOWN;//识别鼠标是否在第返回上一级关按钮上
	short test;            //表示按钮按的哪一个键，1-10表示相应关卡，-1表示返回上一级
	bool choose = false;
	while (!choose)
	{
		mmsg = GetMouseMsg();
		switch (mmsg.uMsg)
		{
		case WM_MOUSEMOVE:
			hover1 = f1.IsInRect(mmsg.x, mmsg.y);
			hover2 = f2.IsInRect(mmsg.x, mmsg.y);
			hover3 = f3.IsInRect(mmsg.x, mmsg.y);
			hover4 = f4.IsInRect(mmsg.x, mmsg.y);
			hover5 = f5.IsInRect(mmsg.x, mmsg.y);
			hover6 = f6.IsInRect(mmsg.x, mmsg.y);
			hover7 = f7.IsInRect(mmsg.x, mmsg.y);
			hover8 = f8.IsInRect(mmsg.x, mmsg.y);
			hover9 = f9.IsInRect(mmsg.x, mmsg.y);
			hover10 = f10.IsInRect(mmsg.x, mmsg.y);
			hover11 = blast.IsInRect(mmsg.x, mmsg.y);
			break;
		case WM_LBUTTONDOWN:
			hover1 = f1.IsInRect(mmsg.x, mmsg.y);
			hover2 = f2.IsInRect(mmsg.x, mmsg.y);
			hover3 = f3.IsInRect(mmsg.x, mmsg.y);
			hover4 = f4.IsInRect(mmsg.x, mmsg.y);
			hover5 = f5.IsInRect(mmsg.x, mmsg.y);
			hover6 = f6.IsInRect(mmsg.x, mmsg.y);
			hover7 = f7.IsInRect(mmsg.x, mmsg.y);
			hover8 = f8.IsInRect(mmsg.x, mmsg.y);
			hover9 = f9.IsInRect(mmsg.x, mmsg.y);
			hover10 = f10.IsInRect(mmsg.x, mmsg.y);
			hover11 = blast.IsInRect(mmsg.x, mmsg.y);
			if (hover1 == ALREADY_IN || hover1 == JUST_IN)
			{
				test = 1;
				choose = true;
			}
			if (hover2 == ALREADY_IN || hover2 == JUST_IN)
			{
				test = 2;
				choose = true;
			}
			if (hover3 == ALREADY_IN || hover3 == JUST_IN)
			{
				test = 3;
				choose = true;
			}
			if (hover4 == ALREADY_IN || hover4 == JUST_IN)
			{
				test = 4;
				choose = true;
			}
			if (hover5 == ALREADY_IN || hover5 == JUST_IN)
			{
				test = 5;
				choose = true;
			}
			if (hover6 == ALREADY_IN || hover6 == JUST_IN)
			{
				test = 6;
				choose = true;
			}
			if (hover7 == ALREADY_IN || hover7 == JUST_IN)
			{
				test = 7;
				choose = true;
			}
			if (hover8 == ALREADY_IN || hover8 == JUST_IN)
			{
				test = 8;
				choose = true;
			}
			if (hover9 == ALREADY_IN || hover9 == JUST_IN)
			{
				test = 9;
				choose = true;
			}
			if (hover10 == ALREADY_IN || hover10 == JUST_IN)
			{
				test = 10;
				choose = true;
			}
			if (hover11 == ALREADY_IN || hover11 == JUST_IN)
			{
				test = 0;
				flag = 0;
				choose = true;
			}

			break;
		}
		BeginBatchDraw();
		if (hover1 == JUST_IN || hover1 == JUST_OUT)
			f1.PaintButton(hover1 == JUST_IN);
		else if (hover2 == JUST_IN || hover2 == JUST_OUT)
			f2.PaintButton(hover2 == JUST_IN);
		else if (hover3 == JUST_IN || hover3 == JUST_OUT)
			f3.PaintButton(hover3 == JUST_IN);
		else if (hover4 == JUST_IN || hover4 == JUST_OUT)
			f4.PaintButton(hover4 == JUST_IN);
		else if (hover5 == JUST_IN || hover5 == JUST_OUT)
			f5.PaintButton(hover5 == JUST_IN);
		else if (hover6 == JUST_IN || hover6 == JUST_OUT)
			f6.PaintButton(hover6 == JUST_IN);
		else if (hover7 == JUST_IN || hover7 == JUST_OUT)
			f7.PaintButton(hover7 == JUST_IN);
		else if (hover8 == JUST_IN || hover8 == JUST_OUT)
			f8.PaintButton(hover8 == JUST_IN);
		else if (hover9 == JUST_IN || hover9 == JUST_OUT)
			f9.PaintButton(hover9 == JUST_IN);
		else if (hover10 == JUST_IN || hover10 == JUST_OUT)
			f10.PaintButton(hover10 == JUST_IN);
		else if (hover11 == JUST_IN || hover11 == JUST_OUT)
			blast.PaintButton(hover11 == JUST_IN);
		EndBatchDraw();
	}
	cleardevice();
	return test;

}