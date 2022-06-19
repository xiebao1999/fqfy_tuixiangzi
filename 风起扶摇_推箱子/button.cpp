#include"button.h"

//构造
Button::Button(const char* title, int left, int top, int right, int bottom)  //构造函数（标题，矩形框各个边界值）
{
	rc.left = left;
	rc.top = top;
	rc.right = right;
	rc.bottom = bottom;
	strcpy_s(txt, title);
	size = 20;
	tag = UNKNOWN;
}

short  Button::IsInRect(int x, int y) //功能: 判断鼠标点击是否在所框选矩形范围内
{
	bool inside = x > rc.left && x < rc.right&& y<rc.bottom&& y>rc.top;
	if (inside)
	{
		if (tag == LAST_IN)
			return ALREADY_IN;
		else
		{
			tag = LAST_IN;
			return JUST_IN;
		}
	}
	else
	{
		if (tag == LAST_OUT)
			return ALREADY_OUT;
		else
		{
			tag = LAST_OUT;
			return JUST_OUT;
		}
	}
}

TxtButton::TxtButton(const char* title, int left, int top, int right, int bottom, COLORREF clr, COLORREF hcolor, COLORREF txtclr) :
	Button(title, left, top, right, bottom), color(clr), hovercolor(hcolor), txtcolor(txtclr) {
	;
}   //构造一个文字按钮

void TxtButton::SetColor(COLORREF c, COLORREF hc, COLORREF txtc)      //颜色设置
{
	color = c;
	hovercolor = hc;
	txtcolor = txtc;
}

void TxtButton::PaintButton(bool hover)    //绘制按钮
{
	if (hover)
		setfillcolor(hovercolor);  //如果鼠标在按钮上，颜色为hovercolor
	else
		setfillcolor(color);      //如果鼠标不在按钮上，颜色为hovercolor
	fillrectangle(rc.left, rc.top, rc.right, rc.bottom);
	settextstyle(size, size / 2, "宋体");
	settextcolor(txtcolor);
	drawtext(txt, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}