#pragma once
#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#include "source.h"
class Button     //按钮类
{
protected:
	RECT rc;//绘制按钮的矩形范围
	char txt[14];//按钮上显示文字
	short size;//文字大小
	short tag;//记录上一次调用IsInRect函数时获得的状态
public:
	Button(const char* title = NULL, int left = 0, int top = 0, int right = 4 * PL, int bottom = PL);
	short IsInRect(int x, int y);
};


class TxtButton :public Button         //按钮子类
{
private:
	COLORREF color;//按钮颜色
	COLORREF hovercolor;//鼠标指向按钮时按钮的颜色
	COLORREF txtcolor;//按钮文本颜色
public:
	TxtButton(const char* title, int left = 0, int top = 0, int right = 4 * PL, int bottom = PL, COLORREF clr = WHITE, COLORREF hcolor = YELLOW, COLORREF txtclr = BLACK);

	void SetColor(COLORREF c = WHITE, COLORREF hc = YELLOW, COLORREF txtc = BLACK);

	void PaintButton(bool hover = false);


};

#endif // !BUTTON_H

