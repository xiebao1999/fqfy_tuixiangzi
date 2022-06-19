#include"source.h"
#include"playergame.h"
#include"player.h"
#include"levelselection.h"
#include"ending.h"
#include"gametutorial.h"
#include"set.h"

void printmenu(RECT& r, const int b1, const int b11,
	const int b2, const int b22,
	const int b3, const int b33) {
	settextcolor(GREEN);
	settextstyle(20, 10, "����");
	fillrectangle(PL * b1, PL * 12, PL * b11, PL * 13);
	r = { PL * b1, PL * 12, PL * b11, PL * 13 };
	drawtext(_T("����"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	fillrectangle(PL * b2, PL * 12, PL * b22, PL * 13);
	r = { PL * b2, PL * 12, PL * b22, PL * 13 };
	drawtext(_T("��ʼ��Ϸ"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	fillrectangle(PL * b3, PL * 12, PL * b33, PL * 13);
	r = { PL * b3, PL * 12, PL * b33, PL * 13 };
	drawtext(_T("��Ϸ�̳�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	FlushBatchDraw();

}

void isinmenuRect(EASYXMSG& k, const int b1, const int b11,
	const int b2, const int b22,
	const int b3, const int b33) {
	if (k.x > PL * b1 &&
		k.x<PL * b11 &&
		k.y>PL * 12 &&
		k.y < PL * 13
		&& k.message == WM_LBUTTONDOWN)
	{//��������
		cout << k.x << " " << k.y;
		SetMap();

	}
	else if (k.x > PL * b2 &&
		k.x<PL * b22 &&
		k.y>PL * 12 &&
		k.y < PL * 13
		&& k.message == WM_LBUTTONDOWN) {
		//���뿪ʼ��Ϸmapѡ��ҳ��
		cout << k.x << " " << k.y;
		current_level = int(printselectmap()-1);
		if (current_level >= 0)
		{
			setmap();
			flag = 1;
			playgame();
		}
		else
			flag = 0;
			return;
	}
	else if (k.x > PL * b3 &&
		k.x<PL * b33 &&
		k.y>PL * 12 &&
		k.y < PL * 13
		&& k.message == WM_LBUTTONDOWN) {
		//������Ϸ�̳�
		cout << k.x << " " << k.y;
		t = 1;
		gametutorial();

	}
}

bool ifwin()
{
	if (current_level >= 0) {//��ѡ��ؿ��ǻص����˵���current_level == -1
		for (int i = 0; i < 25; i++)
			for (int j = 0; j < 16; j++)
			{
				//�������и���
				if (map[i][j] == 3 || map[i][j] == 7)
					return 0;
			}
		return 1;
	}
	return 0;
}

void playgame() {
	Player player = Player();
	while (flag) {
		cleardevice();
		BeginBatchDraw();
		putimage(0, 0, &img_wallRound);
		printmap();
		setPlayer(player);
		FlushBatchDraw();
		char input = _getch();//�����ȡ������Ϣ

		if (input == 'a' || input == 75 || input == 'A')
		{
			player.moveleft();
		}
		else if (input == 'w' || input == 72 || input == 'W') {
			player.moveup();
		}
		else if (input == 's' || input == 80 || input == 'S') {
			player.movedown();
		}
		else if (input == 'd' || input == 77 || input == 'D') {
			player.moveright();
		}
		else if (input == 'r' || input == 'R')
		{
			setmap();
		}
		else if (input == 'i' || input == 'I')
		{
			current_level = int(printselectmap()-1);
			setmap();

		}
		else if (input == 'o' || input == 'O')
		{
			flag = 0;
		}
		//�жϻ�ʤ����
		if (ifwin())
		{
			
			printending();
			//break;
		}
		EndBatchDraw();
	}
}

void menu() {
	//const int optionButtonLenth = 4, optionButtonWeight = 6; //��ť
	const int b1 = 5, b11 = 9;//��ť
	const int b2 = 13, b22 = 17;
	const int b3 = 21, b33 = 25;
	RECT r = { 0,0,0,0 };
	EASYXMSG k; //�����Ϣ

	/**********��ʼ����****************/

	printmenu(r, b1, b11, b2, b22, b3, b33);
	k = getmessage(EM_MOUSE | EM_KEY);
	isinmenuRect(k, b1, b11, b2, b22, b3, b33);
	int a = 0;
}
