#include"gametutorial.h"
//�����5��ͼƬimg_tutorial_a,img_tutorial_b,img_tutorial_c,img_tutorial_e
//�½���һ��ͷ�ļ�,����һ������gametutorial()
//һ����ȫ�ֱ���t,��playergame��gametutorial()ǰ��ʼ��Ϊ1
void gametutorial() {

	if (t == 1) {
	initgraph(PL * 30, PL * 15);
	BeginBatchDraw();
	putimage(0, 0, &background);
	//�� Ϸ �� ��
	setfillcolor(GREEN);
	fillrectangle(PL * 2, PL * 1, PL * 10, PL * 14);
	setbkmode(TRANSPARENT);
	char s1[] = "�� Ϸ �� ��";
	char s2[] = "��������Ϸ1981������";
	char s3[] = "�ֺ����״�������1982��12";
	char s4[] = "����Thinking Rabbit ��˾";
	char s5[] = "�״η��У������ֿⷬ����";
	char s6[] = "����ֻ������, ��������, ";
	char s7[] = "����һ��ֻ���ƶ�һ����ʤ";
	char s8[] = "���������ǰ����е�����";
	char s9[] = "���Ƶ�Ŀ�ĵء���������Ϸ";
	char s10[] = "��һ�����ٽ��˵�������Ϸ";
	char s11[] = "���ȿ��Կ���������ѧ����";
	char s12[] = "�������ֿ��Է�ֹ����մ�";
	char s13[] = "֢��ȫ��һ�𹥹شٽ�����";
	settextstyle(20, 10, "����");
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

	//��Ϸ�̳�

		setfillcolor(GREEN);
		fillrectangle(PL * 13, PL * 1, PL * 29, PL * 14);
		putimage(PL * 14, PL * 1, &img_tutorial_a);
		putimage(PL * 22, PL * 1, &img_tutorial_b);
		char t1[] = "1.�淨���ܣ����ǿ���ͨ�������ϵ��������Ҽ�";
		char t2[] = "��������������ƶ����ƶ����ӡ����������ӳɹ��ر�";
		char t3[] = "�Ƶ�ָ��λ�ã���������ͼ���������ӱ�Ϊ��ɫ�����";
		char t4[] = "���ɹ�";
		outtextxy(PL * 15, PL * 8, t1);
		outtextxy(PL * 13, PL * 9, t2);
		outtextxy(PL * 13, PL * 10, t3);
		outtextxy(PL * 13, PL * 11, t4);

		setfillcolor(YELLOW);
		settextcolor(BLACK);
		fillrectangle(PL * 13, PL * 13, PL * 16, PL * 14);
		fillrectangle(PL * 26, PL * 13, PL * 29, PL * 14);
		char t5[] = "  �� ��";
		char t6[] = "  �� ��";
		outtextxy(PL * 26, PL * 13, t5);
		outtextxy(PL * 13, PL * 13, t6);
	}
	
	else if (t == 2) {
		settextcolor(WHITE);
		setfillcolor(GREEN);
		fillrectangle(PL * 13, PL * 1, PL * 29, PL * 14);
		putimage(PL * 14, PL * 1, &img_tutorial_c);
		putimage(PL * 22, PL * 1, &img_tutorial_d);
		char t1[] = "2.��Ϸ���ԣ���Ϊ�ؿ���ͼ�ĸ�������죬ÿһ";
		char t2[] = "�������Ƶ�Ŀ�ĵص�˳������������ģ�����������Ҫ";
		char t3[] = "���ݵ�ͼ��Ŀ�ĵص�λ���ҳ�������ȷ�Ĺ�λѭ�����";
		char t4[] = "�㡣������ͼ������˳�򼴿ɳɹ�";
		outtextxy(PL * 15, PL * 8, t1);
		outtextxy(PL * 13, PL * 9, t2);
		outtextxy(PL * 13, PL * 10, t3);
		outtextxy(PL * 13, PL * 11, t4);

		setfillcolor(YELLOW);
		settextcolor(BLACK);
		fillrectangle(PL * 13, PL * 13, PL * 16, PL * 14);
		fillrectangle(PL * 26, PL * 13, PL * 29, PL * 14);
		char t5[] = "  �� ��";
		char t6[] = "  �� ��";
		outtextxy(PL * 26, PL * 13, t5);
		outtextxy(PL * 13, PL * 13, t6);
	}
	
	else if (t == 3) {
		settextcolor(WHITE);
		setfillcolor(GREEN);
		fillrectangle(PL * 13, PL * 1, PL * 29, PL * 14);
		putimage(PL * 14, PL * 1, &img_tutorial_d);
		putimage(PL * 22, PL * 1, &img_tutorial_e);
		char t1[] = "3.�淨��������Щ�ؿ����ڲ�ֹһ�ֵĳɹ�·��";
		char t2[] = "��ô�ڲ�ͬ��·��֮�У����ǿ���ȥѰ���������ò���";
		char t3[] = "���ٵ�·����������ͼ�������ƶ���ǽ�벻��ǽ������";
		char t4[] = "�����Գɹ�����ͼ1�Ĳ������١�����������Ժܺõ�";
		char t5[] = "�������ǵ��������쿪ʼ��Ϸ�ɣ�";

		outtextxy(PL * 15, PL * 8, t1);
		outtextxy(PL * 13, PL * 9, t2);
		outtextxy(PL * 13, PL * 10, t3);
		outtextxy(PL * 13, PL * 11, t4);
		outtextxy(PL * 13, PL * 12, t5);
		setfillcolor(YELLOW);
		settextcolor(BLACK);
		fillrectangle(PL * 13, PL * 13, PL * 16, PL * 14);
		char t6[] = "  �� ��";
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
