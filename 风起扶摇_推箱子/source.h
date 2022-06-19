#pragma once
#ifndef source_H
#define source_H
#include<conio.h>
#include<Windows.h>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

//测试
#include<iostream>
using namespace std;



//全局变量
extern const int PL;           //小人的长以及各种物体的长
extern const int PW;           //小人的宽
extern int step;                //当前所走的步数
extern char input;                  //玩家输入的字符数
extern int map[16][25];        // 存储地图信息，0为空地，1为墙
extern int flag;               //游戏中
extern int music_sign;    //音乐开关
extern int music_mode;
extern const int maps[20][16][25];

extern int current_level;//当前关卡
extern int t; //教程页数

extern IMAGE img_start,
img_set,
img_play,
img_level,
img_wallRound,
img_walls,
img_box,
img_endPoint,
img_human,
img_boxf,
background,
img_tutorial_a,
img_tutorial_b,
img_tutorial_c,
img_tutorial_d,
img_tutorial_e;



//鼠标选择框
extern const short ALREADY_IN;//上一次调用IsInRect函数时鼠标已经在按钮上，目前仍然再按钮上
extern const short ALREADY_OUT;//上一次调用IsInRect函数时鼠标已经在按钮外，目前仍然再按钮外
extern const short JUST_IN;//上一次调用IsInRect函数时鼠标在按钮外，目前在按钮上
extern const short JUST_OUT;//上一次调用IsInRect函数时鼠标在按钮上，目前在按钮外
extern const short UNKNOWN;//鼠标位置未知
extern const short LAST_IN;//鼠标移动前在里面
extern const short LAST_OUT;//鼠标移动前在外面

//加载图片
void loading();

//地图更换
void setmap();

#endif // !source_H

