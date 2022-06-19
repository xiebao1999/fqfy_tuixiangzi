#ifndef player_H
#define player_H
#include"source.h"

//��С�˷�װ��Ϊһ����
class Player {

public:
    int level;                        //��ǰС���ڵڼ���      ����ڴ˴������޸�
    int x, y;                         //С�˵�ͼ��x,y����
    int nx, ny;                       //С��Ҫ�ߵ���һ��x,y����
    int nnx, nny;                     //С��Ҫ�ߵķ��������һ��x,y����
    int actualx, actuay;              //С��ʵ���ڵ�ͼ�е�����

    Player();                         //Ĭ�Ϲ��캯��
    Player(int x1, int y1, int le);   //���캯��
    void findPlayer(int x1, int y1, int le);
    void moveup();                    //�෽���������ƶ�
    void movedown();                  //�෽���������ƶ�
    void moveleft();                  //�෽���������ƶ�
    void moveright();                 //�෽���������ƶ�

};

void setmap();

void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg);

void printmap();

void setPlayer(Player& player);
#endif // !player_H


