#include"button.h"

//����
Button::Button(const char* title, int left, int top, int right, int bottom)  //���캯�������⣬���ο�����߽�ֵ��
{
	rc.left = left;
	rc.top = top;
	rc.right = right;
	rc.bottom = bottom;
	strcpy_s(txt, title);
	size = 20;
	tag = UNKNOWN;
}

short  Button::IsInRect(int x, int y) //����: �ж�������Ƿ�������ѡ���η�Χ��
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
}   //����һ�����ְ�ť

void TxtButton::SetColor(COLORREF c, COLORREF hc, COLORREF txtc)      //��ɫ����
{
	color = c;
	hovercolor = hc;
	txtcolor = txtc;
}

void TxtButton::PaintButton(bool hover)    //���ư�ť
{
	if (hover)
		setfillcolor(hovercolor);  //�������ڰ�ť�ϣ���ɫΪhovercolor
	else
		setfillcolor(color);      //�����겻�ڰ�ť�ϣ���ɫΪhovercolor
	fillrectangle(rc.left, rc.top, rc.right, rc.bottom);
	settextstyle(size, size / 2, "����");
	settextcolor(txtcolor);
	drawtext(txt, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}