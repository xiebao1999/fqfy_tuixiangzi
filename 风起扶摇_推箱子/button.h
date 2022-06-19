#pragma once
#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#include "source.h"
class Button     //��ť��
{
protected:
	RECT rc;//���ư�ť�ľ��η�Χ
	char txt[14];//��ť����ʾ����
	short size;//���ִ�С
	short tag;//��¼��һ�ε���IsInRect����ʱ��õ�״̬
public:
	Button(const char* title = NULL, int left = 0, int top = 0, int right = 4 * PL, int bottom = PL);
	short IsInRect(int x, int y);
};


class TxtButton :public Button         //��ť����
{
private:
	COLORREF color;//��ť��ɫ
	COLORREF hovercolor;//���ָ��ťʱ��ť����ɫ
	COLORREF txtcolor;//��ť�ı���ɫ
public:
	TxtButton(const char* title, int left = 0, int top = 0, int right = 4 * PL, int bottom = PL, COLORREF clr = WHITE, COLORREF hcolor = YELLOW, COLORREF txtclr = BLACK);

	void SetColor(COLORREF c = WHITE, COLORREF hc = YELLOW, COLORREF txtc = BLACK);

	void PaintButton(bool hover = false);


};

#endif // !BUTTON_H

