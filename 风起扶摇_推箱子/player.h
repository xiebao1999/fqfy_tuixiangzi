#ifndef player_H
#define player_H
#include"source.h"

//将小人封装成为一个类
class Player {

public:
    int level;                        //当前小人在第几关      杨浩在此处进行修改
    int x, y;                         //小人地图的x,y坐标
    int nx, ny;                       //小人要走的下一个x,y坐标
    int nnx, nny;                     //小人要走的方向的下下一个x,y坐标
    int actualx, actuay;              //小人实际在地图中的坐标

    Player();                         //默认构造函数
    Player(int x1, int y1, int le);   //构造函数
    void findPlayer(int x1, int y1, int le);
    void moveup();                    //类方法：向上移动
    void movedown();                  //类方法：向下移动
    void moveleft();                  //类方法：向左移动
    void moveright();                 //类方法：向右移动

};

void setmap();

void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg);

void printmap();

void setPlayer(Player& player);
#endif // !player_H


