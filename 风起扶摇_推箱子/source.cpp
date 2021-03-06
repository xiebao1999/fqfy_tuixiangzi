#include"source.h"
#include"playergame.h"
#include"player.h"

const int PL = 30;           //小人的长以及各种物体的长
const int PW = 20;           //小人的宽
int step = 0;                //当前所走的步数
char input;                  //玩家输入的字符数
int map[16][25] = { 0 };// 存储地图信息，0为空地，1为墙
int flag = 0; //游戏中
int music_sign = 0;   //音乐开关
int music_mode = 2;
int current_level = 0;
int t = 1;

IMAGE img_start,
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

const int maps[20][16][25] =
{
	//1-5
		{
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,3,1,1,1,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,0,1,1,1,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,2,0,2,3,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,3,0,2,4,1,1,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,1,2,1,1,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,1,3,1,1,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
		},
		{
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,4,0,0,1,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,0,2,2,1,0,1,1,1,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,0,2,0,1,0,1,3,1,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,0,1,1,1,3,1,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,1,0,0,0,0,3,1,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,0,0,0,1,0,0,1,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,0,0,0,1,1,1,1,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
		},
		{
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,0,0,0,0,0,1,1,1,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,1,1,2,1,1,1,0,0,0,1,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,1,0,4,0,2,0,0,2,0,1,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,1,0,3,3,1,0,2,0,1,1,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,1,1,3,3,1,0,0,0,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}
		},
		{
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,1,0,0,1,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,4,2,0,1,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,1,2,0,1,1,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,1,0,2,0,1,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,3,2,0,0,1,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,3,3,0,3,1,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}
		},
		{
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,4,0,1,1,1,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,1,0,2,0,0,1,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,0,1,0,1,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,3,1,0,1,0,0,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,3,2,0,0,1,0,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,3,0,0,0,2,0,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
			{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}
		},

	//6-10
	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,1,1,9,9,1,1,1,1,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,1,1,0,0,1,9,9,1,0,0,0,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,1,0,2,0,1,1,1,1,2,0,0,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,1,0,0,2,3,3,3,3,0,2,0,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,1,1,0,0,0,0,1,0,4,0,1,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,0,0,4,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,2,3,0,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,3,2,3,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,0,5,2,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,1,0,0,0,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,1,3,3,1,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,1,0,3,1,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,0,0,2,3,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,0,2,0,0,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,1,2,2,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,4,0,0,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,1,0,0,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,2,3,3,2,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,4,2,3,5,0,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,4,3,3,2,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,1,0,0,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,0,0,0,0,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,2,0,2,2,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,3,3,3,3,3,3,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,2,2,0,2,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,0,4,1,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	// 11-15
	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,1,0,3,3,3,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,1,1,3,3,3,3,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,0,1,1,1,2,0,1,1,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,2,0,2,0,0,2,2,0,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,4,0,2,0,2,0,0,0,0,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,0,0,1,1,1,0,0,0,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,1,1,1,9,1,1,1,1,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,0,0,0,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,1,2,2,0,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,3,3,3,1,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,3,3,3,2,0,1,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,0,1,1,0,2,0,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,2,0,0,2,0,0,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,0,0,1,0,0,4,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,1,0,0,0,1,1,1,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,0,0,2,0,2,0,0,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,2,0,0,0,2,0,4,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,1,2,2,1,1,1,1,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,0,0,3,3,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,3,3,3,3,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,1,1,1,1,1,1,9,9,9,1,1,1,1,1,9,9,9,9,9,9,
		9,9,9,9,9,1,0,0,0,0,1,1,1,9,1,0,0,3,1,9,9,9,9,9,9,
		9,9,9,9,9,1,0,0,2,0,2,0,1,9,1,3,3,3,1,9,9,9,9,9,9,
		9,9,9,9,9,1,0,1,0,0,2,0,1,1,1,0,0,3,1,9,9,9,9,9,9,
		9,9,9,9,9,1,0,0,2,2,2,0,0,0,2,0,4,3,1,9,9,9,9,9,9,
		9,9,9,9,9,1,1,1,0,0,2,0,0,2,1,0,0,3,1,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,0,2,1,2,0,1,3,3,3,1,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,0,0,0,0,0,1,0,0,3,1,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,1,1,1,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,1,1,1,1,1,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,1,1,3,0,0,0,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,1,3,3,1,1,0,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,2,3,3,0,0,0,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,1,0,3,1,0,1,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,1,0,1,1,2,1,0,0,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,2,0,0,0,0,2,2,0,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,1,2,1,0,0,1,0,0,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,4,0,0,1,1,1,1,1,1,1,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	//16-20
	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,1,1,1,1,1,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,1,3,0,0,4,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,2,2,2,0,0,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,3,1,1,3,1,1,3,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,0,2,0,0,0,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,2,3,1,0,1,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,1,0,0,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,1,1,1,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,3,0,3,3,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,3,0,2,3,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,0,0,2,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,2,0,0,2,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,1,2,1,1,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,0,0,0,4,0,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,1,0,0,0,0,1,1,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,0,0,1,2,0,0,0,1,1,1,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,0,0,2,0,0,0,2,2,0,1,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,2,2,0,1,2,0,0,0,0,1,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,0,0,0,2,0,0,0,2,0,1,9,9,9,9,9,9,
		9,9,9,9,9,1,1,1,1,1,1,0,1,2,1,1,1,1,1,9,9,9,9,9,9,
		9,9,9,9,9,1,3,3,4,0,1,2,0,0,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,1,3,1,3,3,0,0,2,1,1,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,1,3,3,3,3,2,1,0,1,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,1,3,3,3,3,0,0,0,1,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,1,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9,9,9,9,
		9,9,9,9,9,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,9,9,9,9,9,
		9,9,9,9,9,1,0,2,0,1,2,0,1,0,2,1,1,2,0,1,9,9,9,9,9,
		9,9,9,9,9,1,0,1,0,0,2,0,1,0,0,0,0,0,0,1,9,9,9,9,9,
		9,9,9,9,9,1,0,0,0,1,1,2,1,2,1,1,2,2,0,1,9,9,9,9,9,
		9,9,9,9,9,1,0,1,0,1,0,3,3,3,0,1,0,0,0,1,9,9,9,9,9,
		9,9,9,9,9,1,0,2,0,0,3,0,1,0,3,2,0,1,0,1,9,9,9,9,9,
		9,9,9,9,9,1,0,2,1,4,2,3,3,3,0,0,1,0,0,1,9,9,9,9,9,
		9,9,9,9,9,1,0,0,0,0,3,0,1,0,3,0,0,2,0,1,9,9,9,9,9,
		9,9,9,9,9,1,0,1,1,3,2,1,1,1,2,3,0,1,0,1,9,9,9,9,9,
		9,9,9,9,9,1,0,1,0,2,3,3,3,3,3,0,1,1,0,1,9,9,9,9,9,
		9,9,9,9,9,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9,9,9,9,9,
		9,9,9,9,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	},

	{
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,0,0,1,1,0,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,1,0,2,0,2,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,0,5,3,1,0,0,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,0,1,3,4,3,1,1,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,2,1,1,1,5,1,1,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,0,0,0,0,0,0,0,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,0,0,0,1,1,0,1,0,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,1,1,1,1,1,1,0,0,0,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,1,1,1,1,1,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	}
};

void loading() {
	loadimage(&img_start, "image\\start.jpg", 1200, 768);//开始界面背景
	loadimage(&img_set, "image\\set.jpg", 1200, 768);//设置界面背景
	loadimage(&img_play, "image\\play.jpg", 1200, 768);//游戏界面背景
	loadimage(&img_level, "image\\set.jpg", 1200, 768);//游戏关卡界面背景
	loadimage(&img_wallRound, "image\\Ground_Dirt.png", 1200, 768);//空地
	loadimage(&img_walls, "image\\Wall_Brown.png", PL, PL);//墙壁
	loadimage(&img_box, "image\\Crate_Yellow.png", PL, PL);//箱子
	loadimage(&img_endPoint, "image\\EndPoint_Red.png", int(PL / 1.5), int(PL / 1.5));//目的地
	loadimage(&img_human, "image\\human.png", int(PL / 1.5), int(PL / 1.5));//小人
	loadimage(&img_boxf, "image\\Crate_Red.png", PL, PL);//箱子在目的地上
	loadimage(&background, _T("image\\start.jpg"));// 游戏结束背景
	loadimage(&img_tutorial_a, "image\\jca.png", 180, 180);
	loadimage(&img_tutorial_b, "image\\jcb.png", 180, 180);
	loadimage(&img_tutorial_c, "image\\jcc.png", 180, 180);
	loadimage(&img_tutorial_d, "image\\jcd.png", 180, 180);
	loadimage(&img_tutorial_e, "image\\jce.png", 180, 180);
}

//鼠标选择框
const short ALREADY_IN = 1;//上一次调用IsInRect函数时鼠标已经在按钮上，目前仍然再按钮上
const short ALREADY_OUT = 2;//上一次调用IsInRect函数时鼠标已经在按钮外，目前仍然再按钮外
const short JUST_IN = 3;//上一次调用IsInRect函数时鼠标在按钮外，目前在按钮上
const short JUST_OUT = 4;//上一次调用IsInRect函数时鼠标在按钮上，目前在按钮外
const short UNKNOWN = 5;//鼠标位置未知
const short LAST_IN = 6;//鼠标移动前在里面
const short LAST_OUT = 7;//鼠标移动前在外面

void setmap() {
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 25; j++)
		{
			map[i][j] = maps[current_level][i][j];
		}
}