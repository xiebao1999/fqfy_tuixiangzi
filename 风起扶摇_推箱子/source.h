#pragma once
#ifndef source_H
#define source_H
#include<conio.h>
#include<Windows.h>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

//����
#include<iostream>
using namespace std;



//ȫ�ֱ���
extern const int PL;           //С�˵ĳ��Լ���������ĳ�
extern const int PW;           //С�˵Ŀ�
extern int step;                //��ǰ���ߵĲ���
extern char input;                  //���������ַ���
extern int map[16][25];        // �洢��ͼ��Ϣ��0Ϊ�յأ�1Ϊǽ
extern int flag;               //��Ϸ��
extern int music_sign;    //���ֿ���
extern int music_mode;
extern const int maps[20][16][25];

extern int current_level;//��ǰ�ؿ�
extern int t; //�̳�ҳ��

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



//���ѡ���
extern const short ALREADY_IN;//��һ�ε���IsInRect����ʱ����Ѿ��ڰ�ť�ϣ�Ŀǰ��Ȼ�ٰ�ť��
extern const short ALREADY_OUT;//��һ�ε���IsInRect����ʱ����Ѿ��ڰ�ť�⣬Ŀǰ��Ȼ�ٰ�ť��
extern const short JUST_IN;//��һ�ε���IsInRect����ʱ����ڰ�ť�⣬Ŀǰ�ڰ�ť��
extern const short JUST_OUT;//��һ�ε���IsInRect����ʱ����ڰ�ť�ϣ�Ŀǰ�ڰ�ť��
extern const short UNKNOWN;//���λ��δ֪
extern const short LAST_IN;//����ƶ�ǰ������
extern const short LAST_OUT;//����ƶ�ǰ������

//����ͼƬ
void loading();

//��ͼ����
void setmap();

#endif // !source_H

