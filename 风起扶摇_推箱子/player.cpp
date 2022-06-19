#include"source.h"
#include"playergame.h"
#include"player.h"
/*
   ������:���
   ���ܣ�Ĭ�Ϲ��캯���������ݳ�Ա��ʼ��
   ��������
   ����ֵ��û�з���ֵ
*/
Player::Player() {
	level = 0;
	x = 0;
	y = 0;
	nx = ny = 0;
	nnx = nny = 0;
	actualx = 0;
	actuay = 0;
}

/*
   �����ˣ����
   ���ܣ����캯���������ݳ�Ա��ʼ��
   ������int x1, int y1;
   ����ֵ��û�з���ֵ
*/
Player::Player(int x1, int y1, int le) {
	level = le;
	x = x1;
	y = y1;
	nx = ny = x1;
	nnx = nny = y1;
	actualx = x1;
	actuay = y1;
}

void Player::findPlayer(int x1, int y1, int le) {
	level = le;
	x = x1;
	y = y1;
	nx = ny = x1;
	nnx = nny = y1;
}

/*
   �����ˣ����
   ���ܣ�
		1.�ж�С���ڵ�ͼ�е��Ǹ�λ��
		2.�ҵ�λ�ú������ƶ�
			 ����������
				 1.���ǰ���ǿյأ�ֱ�ӽ����ƶ�����ͼ����Ӧ���귢���仯��
				 2.���ǰ�������ӣ���Ҫ������������Ƿ���Ŀ�ĵ��ϣ�
					   a.�������һ��λ���ǿյػ���Ŀ�ĵأ���ô���Խ����ƶ�����ͼ������ͻᷢ���仯��
					   b.������ǿյػ���Ŀ�ĵأ���ô����ǽ�ڣ������ƶ�������д��
   ��������
   ����ֵ����
*/
/*
�յ� 0
ǽ 1
���� 2
Ŀ�ĵ� 3
�� 4
Ŀ�ĵ�+���� 5
��+Ŀ�ĵ� 7



*/
void Player::moveup() {
	//վ�ڿյأ�ǰ���ǿյص����
	if (map[this->x][this->y] == 4 && map[this->x - 1][this->y] == 0) {
		map[this->x - 1][this->y] = 4;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյ���,ǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 4 && map[this->x - 1][this->y] == 3) {
		map[this->x - 1][this->y] = 7;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ��������(���Ӳ���Ŀ�ĵ�)��ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 4 && map[this->x - 1][this->y] == 2 && map[this->x - 2][this->y] == 0) {
		map[this->x - 2][this->y] = 2;
		map[this->x - 1][this->y] = 4;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ�������ӣ�������Ŀ�ĵأ���ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 4 && map[this->x - 1][this->y] == 5 && map[this->x - 2][this->y] == 0) {
		map[this->x - 2][this->y] = 2;
		map[this->x - 1][this->y] = 7;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ�������ӣ�����Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 4 && map[this->x - 1][this->y] == 2 && map[this->x - 2][this->y] == 3) {
		map[this->x - 2][this->y] = 5;
		map[this->x - 1][this->y] = 4;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ�������ӣ���Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 4 && map[this->x - 1][this->y] == 5 && map[this->x - 2][this->y] == 3) {
		map[this->x - 2][this->y] = 5;
		map[this->x - 1][this->y] = 7;
		map[this->x][this->y] = 0;
	}
	//վ��Ŀ�ĵأ�ǰ���ǿյ�
	else if (map[this->x][this->y] == 7 && map[this->x - 1][this->y] == 0) {
		map[this->x - 1][this->y] = 4;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 7 && map[this->x - 1][this->y] == 3) {
		map[this->x - 1][this->y] = 7;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ�����Ŀ�ĵأ���ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 7 && map[this->x - 1][this->y] == 2 && map[this->x - 2][this->y] == 0) {
		map[this->x - 2][this->y] = 2;
		map[this->x - 1][this->y] = 4;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ���Ŀ�ĵأ���ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 7 && map[this->x - 1][this->y] == 5 && map[this->x - 2][this->y] == 0) {
		map[this->x - 2][this->y] = 2;
		map[this->x - 1][this->y] = 7;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ�����Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 7 && map[this->x - 1][this->y] == 2 && map[this->x - 2][this->y] == 3) {
		map[this->x - 2][this->y] = 5;
		map[this->x - 1][this->y] = 4;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ���Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 7 && map[this->x - 1][this->y] == 5 && map[this->x - 2][this->y] == 3) {
		map[this->x - 2][this->y] = 5;
		map[this->x - 1][this->y] = 7;
		map[this->x][this->y] = 3;
	}
}

/*
   �����ˣ����
   ���ܣ�
		1.�ж�С���ڵ�ͼ�е��Ǹ�λ��
		2.�ҵ�λ�ú������ƶ�
			 ����������
				 1.���ǰ���ǿյأ�ֱ�ӽ����ƶ�����ͼ����Ӧ���귢���仯��
				 2.���ǰ�������ӣ���Ҫ������������Ƿ���Ŀ�ĵ��ϣ�
					   a.�������һ��λ���ǿյػ���Ŀ�ĵأ���ô���Խ����ƶ�����ͼ������ͻᷢ���仯��
					   b.������ǿյػ���Ŀ�ĵأ���ô����ǽ�ڣ������ƶ�������д��
   ��������
   ����ֵ����
*/
void Player::movedown() {
	//վ�ڿյأ�ǰ���ǿյص����
	if (map[this->x][this->y] == 4 && map[this->x + 1][this->y] == 0) {
		map[this->x + 1][this->y] = 4;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյ���,ǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 4 && map[this->x + 1][this->y] == 3) {
		map[this->x + 1][this->y] = 7;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ��������(���Ӳ���Ŀ�ĵ�)��ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 4 && map[this->x + 1][this->y] == 2 && map[this->x + 2][this->y] == 0) {
		map[this->x + 2][this->y] = 2;
		map[this->x + 1][this->y] = 4;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ�������ӣ�������Ŀ�ĵأ���ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 4 && map[this->x + 1][this->y] == 5 && map[this->x + 2][this->y] == 0) {
		map[this->x + 2][this->y] = 2;
		map[this->x + 1][this->y] = 7;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ�������ӣ�����Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 4 && map[this->x + 1][this->y] == 2 && map[this->x + 2][this->y] == 3) {
		map[this->x + 2][this->y] = 5;
		map[this->x + 1][this->y] = 4;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ�������ӣ���Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 4 && map[this->x + 1][this->y] == 5 && map[this->x + 2][this->y] == 3) {
		map[this->x + 2][this->y] = 5;
		map[this->x + 1][this->y] = 7;
		map[this->x][this->y] = 0;
	}
	//վ��Ŀ�ĵأ�ǰ���ǿյ�
	else if (map[this->x][this->y] == 7 && map[this->x + 1][this->y] == 0) {
		map[this->x + 1][this->y] = 4;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 7 && map[this->x + 1][this->y] == 3) {
		map[this->x + 1][this->y] = 7;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ�����Ŀ�ĵأ���ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 7 && map[this->x + 1][this->y] == 2 && map[this->x + 2][this->y] == 0) {
		map[this->x + 2][this->y] = 2;
		map[this->x + 1][this->y] = 4;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ���Ŀ�ĵأ���ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 7 && map[this->x + 1][this->y] == 5 && map[this->x + 2][this->y] == 0) {
		map[this->x + 2][this->y] = 2;
		map[this->x + 1][this->y] = 7;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ�����Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 7 && map[this->x + 1][this->y] == 2 && map[this->x + 2][this->y] == 3) {
		map[this->x + 2][this->y] = 5;
		map[this->x + 1][this->y] = 4;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ���Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 7 && map[this->x + 1][this->y] == 5 && map[this->x + 2][this->y] == 3) {
		map[this->x + 2][this->y] = 5;
		map[this->x + 1][this->y] = 7;
		map[this->x][this->y] = 3;
	}
}

/*
   �����ˣ����
   ���ܣ�
		1.�ж�С���ڵ�ͼ�е��Ǹ�λ��
		2.�ҵ�λ�ú������ƶ�
			 ����������
				 1.���ǰ���ǿյأ�ֱ�ӽ����ƶ�����ͼ����Ӧ���귢���仯��
				 2.���ǰ�������ӣ���Ҫ������������Ƿ���Ŀ�ĵ��ϣ�
					   a.�������һ��λ���ǿյػ���Ŀ�ĵأ���ô���Խ����ƶ�����ͼ������ͻᷢ���仯��
					   b.������ǿյػ���Ŀ�ĵأ���ô����ǽ�ڣ������ƶ�������д��
   ��������
   ����ֵ����
*/
void Player::moveleft() {
	//վ�ڿյأ�ǰ���ǿյص����
	if (map[this->x][this->y] == 4 && map[this->x][this->y - 1] == 0) {
		map[this->x][this->y - 1] = 4;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյ���,ǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 4 && map[this->x][this->y - 1] == 3) {
		map[this->x][this->y - 1] = 7;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ��������(���Ӳ���Ŀ�ĵ�)��ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 4 && map[this->x][this->y - 1] == 2 && map[this->x][this->y - 2] == 0) {
		map[this->x][this->y - 2] = 2;
		map[this->x][this->y - 1] = 4;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ�������ӣ�������Ŀ�ĵأ���ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 4 && map[this->x][this->y - 1] == 5 && map[this->x][this->y - 2] == 0) {
		map[this->x][this->y - 2] = 2;
		map[this->x][this->y - 1] = 7;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ�������ӣ�����Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 4 && map[this->x][this->y - 1] == 2 && map[this->x][this->y - 2] == 3) {
		map[this->x][this->y - 2] = 5;
		map[this->x][this->y - 1] = 4;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ�������ӣ���Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 4 && map[this->x][this->y - 1] == 5 && map[this->x][this->y - 2] == 3) {
		map[this->x][this->y - 2] = 5;
		map[this->x][this->y - 1] = 7;
		map[this->x][this->y] = 0;
	}
	//վ��Ŀ�ĵأ�ǰ���ǿյ�
	else if (map[this->x][this->y] == 7 && map[this->x][this->y - 1] == 0) {
		map[this->x][this->y - 1] = 4;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 7 && map[this->x][this->y - 1] == 3) {
		map[this->x][this->y - 1] = 7;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ�����Ŀ�ĵأ���ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 7 && map[this->x][this->y - 1] == 2 && map[this->x][this->y - 2] == 0) {
		map[this->x][this->y - 2] = 2;
		map[this->x][this->y - 1] = 4;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ���Ŀ�ĵأ���ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 7 && map[this->x][this->y - 1] == 5 && map[this->x][this->y - 2] == 0) {
		map[this->x][this->y - 2] = 2;
		map[this->x][this->y - 1] = 7;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ�����Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 7 && map[this->x][this->y - 1] == 2 && map[this->x][this->y - 2] == 3) {
		map[this->x][this->y - 2] = 5;
		map[this->x][this->y - 1] = 4;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ���Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 7 && map[this->x][this->y - 1] == 5 && map[this->x][this->y - 2] == 3) {
		map[this->x][this->y - 2] = 5;
		map[this->x][this->y - 2] = 7;
		map[this->x][this->y] = 3;
	}
}

/*
   �����ˣ����
   ���ܣ�
		1.�ж�С���ڵ�ͼ�е��Ǹ�λ��
		2.�ҵ�λ�ú������ƶ�
			 ����������
				 1.���ǰ���ǿյأ�ֱ�ӽ����ƶ�����ͼ����Ӧ���귢���仯��
				 2.���ǰ�������ӣ���Ҫ������������Ƿ���Ŀ�ĵ��ϣ�
					   a.�������һ��λ���ǿյػ���Ŀ�ĵأ���ô���Խ����ƶ�����ͼ������ͻᷢ���仯��
					   b.������ǿյػ���Ŀ�ĵأ���ô����ǽ�ڣ������ƶ�������д��
   ��������
   ����ֵ����
*/
void Player::moveright() {
	//վ�ڿյأ�ǰ���ǿյص����
	if (map[this->x][this->y] == 4 && map[this->x][this->y + 1] == 0) {
		map[this->x][this->y + 1] = 4;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյ���,ǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 4 && map[this->x][this->y + 1] == 3) {
		map[this->x][this->y + 1] = 7;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ��������(���Ӳ���Ŀ�ĵ�)��ǰǰ���ǿյ�   //////
	else if (map[this->x][this->y] == 4 && map[this->x][this->y + 1] == 2 && map[this->x][this->y + 2] == 0) {
		map[this->x][this->y + 2] = 2;
		map[this->x][this->y + 1] = 4;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ�������ӣ�������Ŀ�ĵأ���ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 4 && map[this->x][this->y + 1] == 5 && map[this->x][this->y + 2] == 0) {
		map[this->x][this->y + 2] = 2;
		map[this->x][this->y + 1] = 7;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ�������ӣ�����Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 4 && map[this->x][this->y + 1] == 2 && map[this->x][this->y + 2] == 3) {
		map[this->x][this->y + 2] = 5;
		map[this->x][this->y + 1] = 4;
		map[this->x][this->y] = 0;
	}
	//վ�ڿյأ�ǰ�������ӣ���Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 4 && map[this->x][this->y + 1] == 5 && map[this->x][this->y + 2] == 3) {
		map[this->x][this->y + 2] = 5;
		map[this->x][this->y + 1] = 7;
		map[this->x][this->y] = 0;
	}
	//վ��Ŀ�ĵأ�ǰ���ǿյ�
	else if (map[this->x][this->y] == 7 && map[this->x][this->y + 1] == 0) {
		map[this->x][this->y + 1] = 4;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 7 && map[this->x][this->y + 1] == 3) {
		map[this->x][this->y + 1] = 7;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ�����Ŀ�ĵأ���ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 7 && map[this->x][this->y + 1] == 2 && map[this->x][this->y + 2] == 0) {
		map[this->x][this->y + 2] = 2;
		map[this->x][this->y + 1] = 4;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ���Ŀ�ĵأ���ǰǰ���ǿյ�
	else if (map[this->x][this->y] == 7 && map[this->x][this->y + 1] == 5 && map[this->x][this->y + 2] == 0) {
		map[this->x][this->y + 2] = 2;
		map[this->x][this->y + 1] = 7;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ�����Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 7 && map[this->x][this->y + 1] == 2 && map[this->x][this->y + 2] == 3) {
		map[this->x][this->y + 2] = 5;
		map[this->x][this->y + 1] = 4;
		map[this->x][this->y] = 3;
	}
	//վ��Ŀ�ĵأ�ǰ�������ӣ���Ŀ�ĵأ���ǰǰ����Ŀ�ĵ�
	else if (map[this->x][this->y] == 7 && map[this->x][this->y + 1] == 5 && map[this->x][this->y + 2] == 3) {
		map[this->x][this->y + 2] = 5;
		map[this->x][this->y + 2] = 7;
		map[this->x][this->y] = 3;
	}
}


//����
void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	if (dstimg == NULL)
	{
		return;
	}
	// ������ʼ��
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = dstimg->getwidth();
	int dst_height = dstimg->getheight();
	// ʵ��͸����ͼ ���Ż�
	for (int iy = 0; iy < src_height; iy++)
	{
		for (int ix = 0; ix < src_width; ix++)
		{
			int srcX = ix + iy * src_width;
			int sa = ((src[srcX] & 0xff000000) >> 24);
			int sr = ((src[srcX] & 0xff0000) >> 16);
			int sg = ((src[srcX] & 0xff00) >> 8);
			int sb = src[srcX] & 0xff;
			if (x + ix >= 0 && x + ix < dst_width
				&& y + iy >= 0 && y + iy < dst_height)
			{
				int dstX = (x + ix) + (y + iy) * dst_width;
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				dst[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)
					| (sb * sa / 255 + db * (255 - sa) / 255);
			}
		}
	}
}

void printmap() {
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 25; j++)
		{
			if (map[i][j] == 0)//�յ�
				//drawAlpha(&img_wallRound, j * PL, i * PL, &img_wallRound);
				putimage(j * PL, i * PL, &img_wallRound);
			if (map[i][j] == 1)//ǽ��
				//drawAlpha(&img_wallRound, j * PL, i * PL, &img_walls);
				putimage(j * PL, i * PL, &img_walls);
			if (map[i][j] == 2)//����
				//drawAlpha(&img_wallRound, j * PL, i * PL, &img_box);
				putimage(j * PL, i * PL, &img_box);
			if (map[i][j] == 3)//Ŀ�ĵ�
				//drawAlpha(&img_wallRound, j * PL + PL / 6, i * PL + PL / 6, &img_endPoint);
				putimage(j * PL + PL / 6, i * PL + PL / 6, &img_endPoint);
			if (map[i][j] == 4 || map[i][j] == 7)//��  6.19 19:05
				//drawAlpha(&img_wallRound, j * PL + PL / 6, i * PL + PL / 6, &img_human);
				putimage(j * PL + PL / 6, i * PL + PL / 6, &img_human);
			if (map[i][j] == 5)//������Ŀ�ĵ���
				//drawAlpha(&img_wallRound, j * PL, i * PL, &img_boxf);
				putimage(j * PL, i * PL, &img_boxf);
		}
}

void setPlayer(Player& player) {
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 16; j++)
		{
			if (map[i][j] == 4||map[i][j] == 7)//���� 6.19 18:02
			{
				player.findPlayer(i, j, current_level);
			}
		}
			
}

