#include"source.h"
#include"playergame.h"
#include"player.h"
/*
   负责人:杨浩
   功能：默认构造函数，将数据成员初始化
   参数：无
   返回值：没有返回值
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
   负责人：杨浩
   功能：构造函数，将数据成员初始化
   参数；int x1, int y1;
   返回值：没有返回值
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
   负责人：杨浩
   功能：
		1.判断小人在地图中的那个位置
		2.找到位置后，向上移动
			 可能遇到：
				 1.如果前面是空地，直接进行移动（地图上相应坐标发生变化）
				 2.如果前面是箱子，就要考虑这个箱子是否在目的地上：
					   a.如果下下一个位置是空地或者目的地，那么可以进行移动（地图上坐标就会发生变化）
					   b.如果不是空地或者目的地，那么就是墙壁，不能移动（不用写）
   参数：无
   返回值：无
*/
/*
空地 0
墙 1
箱子 2
目的地 3
人 4
目的地+箱子 5
人+目的地 7



*/
void Player::moveup() {
	//站在空地，前方是空地的情况
	if (map[this->x][this->y] == 4 && map[this->x - 1][this->y] == 0) {
		map[this->x - 1][this->y] = 4;
		map[this->x][this->y] = 0;
	}
	//站在空地上,前方是目的地
	else if (map[this->x][this->y] == 4 && map[this->x - 1][this->y] == 3) {
		map[this->x - 1][this->y] = 7;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子(箱子不在目的地)，前前方是空地
	else if (map[this->x][this->y] == 4 && map[this->x - 1][this->y] == 2 && map[this->x - 2][this->y] == 0) {
		map[this->x - 2][this->y] = 2;
		map[this->x - 1][this->y] = 4;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子（箱子在目的地），前前方是空地
	else if (map[this->x][this->y] == 4 && map[this->x - 1][this->y] == 5 && map[this->x - 2][this->y] == 0) {
		map[this->x - 2][this->y] = 2;
		map[this->x - 1][this->y] = 7;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子（不在目的地），前前方是目的地
	else if (map[this->x][this->y] == 4 && map[this->x - 1][this->y] == 2 && map[this->x - 2][this->y] == 3) {
		map[this->x - 2][this->y] = 5;
		map[this->x - 1][this->y] = 4;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子（在目的地），前前方是目的地
	else if (map[this->x][this->y] == 4 && map[this->x - 1][this->y] == 5 && map[this->x - 2][this->y] == 3) {
		map[this->x - 2][this->y] = 5;
		map[this->x - 1][this->y] = 7;
		map[this->x][this->y] = 0;
	}
	//站在目的地，前方是空地
	else if (map[this->x][this->y] == 7 && map[this->x - 1][this->y] == 0) {
		map[this->x - 1][this->y] = 4;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是目的地
	else if (map[this->x][this->y] == 7 && map[this->x - 1][this->y] == 3) {
		map[this->x - 1][this->y] = 7;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（不在目的地），前前方是空地
	else if (map[this->x][this->y] == 7 && map[this->x - 1][this->y] == 2 && map[this->x - 2][this->y] == 0) {
		map[this->x - 2][this->y] = 2;
		map[this->x - 1][this->y] = 4;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（在目的地），前前方是空地
	else if (map[this->x][this->y] == 7 && map[this->x - 1][this->y] == 5 && map[this->x - 2][this->y] == 0) {
		map[this->x - 2][this->y] = 2;
		map[this->x - 1][this->y] = 7;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（不在目的地），前前方是目的地
	else if (map[this->x][this->y] == 7 && map[this->x - 1][this->y] == 2 && map[this->x - 2][this->y] == 3) {
		map[this->x - 2][this->y] = 5;
		map[this->x - 1][this->y] = 4;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（在目的地），前前方是目的地
	else if (map[this->x][this->y] == 7 && map[this->x - 1][this->y] == 5 && map[this->x - 2][this->y] == 3) {
		map[this->x - 2][this->y] = 5;
		map[this->x - 1][this->y] = 7;
		map[this->x][this->y] = 3;
	}
}

/*
   负责人：杨浩
   功能：
		1.判断小人在地图中的那个位置
		2.找到位置后，向下移动
			 可能遇到：
				 1.如果前面是空地，直接进行移动（地图上相应坐标发生变化）
				 2.如果前面是箱子，就要考虑这个箱子是否在目的地上：
					   a.如果下下一个位置是空地或者目的地，那么可以进行移动（地图上坐标就会发生变化）
					   b.如果不是空地或者目的地，那么就是墙壁，不能移动（不用写）
   参数：无
   返回值：无
*/
void Player::movedown() {
	//站在空地，前方是空地的情况
	if (map[this->x][this->y] == 4 && map[this->x + 1][this->y] == 0) {
		map[this->x + 1][this->y] = 4;
		map[this->x][this->y] = 0;
	}
	//站在空地上,前方是目的地
	else if (map[this->x][this->y] == 4 && map[this->x + 1][this->y] == 3) {
		map[this->x + 1][this->y] = 7;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子(箱子不在目的地)，前前方是空地
	else if (map[this->x][this->y] == 4 && map[this->x + 1][this->y] == 2 && map[this->x + 2][this->y] == 0) {
		map[this->x + 2][this->y] = 2;
		map[this->x + 1][this->y] = 4;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子（箱子在目的地），前前方是空地
	else if (map[this->x][this->y] == 4 && map[this->x + 1][this->y] == 5 && map[this->x + 2][this->y] == 0) {
		map[this->x + 2][this->y] = 2;
		map[this->x + 1][this->y] = 7;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子（不在目的地），前前方是目的地
	else if (map[this->x][this->y] == 4 && map[this->x + 1][this->y] == 2 && map[this->x + 2][this->y] == 3) {
		map[this->x + 2][this->y] = 5;
		map[this->x + 1][this->y] = 4;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子（在目的地），前前方是目的地
	else if (map[this->x][this->y] == 4 && map[this->x + 1][this->y] == 5 && map[this->x + 2][this->y] == 3) {
		map[this->x + 2][this->y] = 5;
		map[this->x + 1][this->y] = 7;
		map[this->x][this->y] = 0;
	}
	//站在目的地，前方是空地
	else if (map[this->x][this->y] == 7 && map[this->x + 1][this->y] == 0) {
		map[this->x + 1][this->y] = 4;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是目的地
	else if (map[this->x][this->y] == 7 && map[this->x + 1][this->y] == 3) {
		map[this->x + 1][this->y] = 7;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（不在目的地），前前方是空地
	else if (map[this->x][this->y] == 7 && map[this->x + 1][this->y] == 2 && map[this->x + 2][this->y] == 0) {
		map[this->x + 2][this->y] = 2;
		map[this->x + 1][this->y] = 4;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（在目的地），前前方是空地
	else if (map[this->x][this->y] == 7 && map[this->x + 1][this->y] == 5 && map[this->x + 2][this->y] == 0) {
		map[this->x + 2][this->y] = 2;
		map[this->x + 1][this->y] = 7;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（不在目的地），前前方是目的地
	else if (map[this->x][this->y] == 7 && map[this->x + 1][this->y] == 2 && map[this->x + 2][this->y] == 3) {
		map[this->x + 2][this->y] = 5;
		map[this->x + 1][this->y] = 4;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（在目的地），前前方是目的地
	else if (map[this->x][this->y] == 7 && map[this->x + 1][this->y] == 5 && map[this->x + 2][this->y] == 3) {
		map[this->x + 2][this->y] = 5;
		map[this->x + 1][this->y] = 7;
		map[this->x][this->y] = 3;
	}
}

/*
   负责人：杨浩
   功能：
		1.判断小人在地图中的那个位置
		2.找到位置后，向左移动
			 可能遇到：
				 1.如果前面是空地，直接进行移动（地图上相应坐标发生变化）
				 2.如果前面是箱子，就要考虑这个箱子是否在目的地上：
					   a.如果下下一个位置是空地或者目的地，那么可以进行移动（地图上坐标就会发生变化）
					   b.如果不是空地或者目的地，那么就是墙壁，不能移动（不用写）
   参数：无
   返回值：无
*/
void Player::moveleft() {
	//站在空地，前方是空地的情况
	if (map[this->x][this->y] == 4 && map[this->x][this->y - 1] == 0) {
		map[this->x][this->y - 1] = 4;
		map[this->x][this->y] = 0;
	}
	//站在空地上,前方是目的地
	else if (map[this->x][this->y] == 4 && map[this->x][this->y - 1] == 3) {
		map[this->x][this->y - 1] = 7;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子(箱子不在目的地)，前前方是空地
	else if (map[this->x][this->y] == 4 && map[this->x][this->y - 1] == 2 && map[this->x][this->y - 2] == 0) {
		map[this->x][this->y - 2] = 2;
		map[this->x][this->y - 1] = 4;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子（箱子在目的地），前前方是空地
	else if (map[this->x][this->y] == 4 && map[this->x][this->y - 1] == 5 && map[this->x][this->y - 2] == 0) {
		map[this->x][this->y - 2] = 2;
		map[this->x][this->y - 1] = 7;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子（不在目的地），前前方是目的地
	else if (map[this->x][this->y] == 4 && map[this->x][this->y - 1] == 2 && map[this->x][this->y - 2] == 3) {
		map[this->x][this->y - 2] = 5;
		map[this->x][this->y - 1] = 4;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子（在目的地），前前方是目的地
	else if (map[this->x][this->y] == 4 && map[this->x][this->y - 1] == 5 && map[this->x][this->y - 2] == 3) {
		map[this->x][this->y - 2] = 5;
		map[this->x][this->y - 1] = 7;
		map[this->x][this->y] = 0;
	}
	//站在目的地，前方是空地
	else if (map[this->x][this->y] == 7 && map[this->x][this->y - 1] == 0) {
		map[this->x][this->y - 1] = 4;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是目的地
	else if (map[this->x][this->y] == 7 && map[this->x][this->y - 1] == 3) {
		map[this->x][this->y - 1] = 7;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（不在目的地），前前方是空地
	else if (map[this->x][this->y] == 7 && map[this->x][this->y - 1] == 2 && map[this->x][this->y - 2] == 0) {
		map[this->x][this->y - 2] = 2;
		map[this->x][this->y - 1] = 4;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（在目的地），前前方是空地
	else if (map[this->x][this->y] == 7 && map[this->x][this->y - 1] == 5 && map[this->x][this->y - 2] == 0) {
		map[this->x][this->y - 2] = 2;
		map[this->x][this->y - 1] = 7;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（不在目的地），前前方是目的地
	else if (map[this->x][this->y] == 7 && map[this->x][this->y - 1] == 2 && map[this->x][this->y - 2] == 3) {
		map[this->x][this->y - 2] = 5;
		map[this->x][this->y - 1] = 4;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（在目的地），前前方是目的地
	else if (map[this->x][this->y] == 7 && map[this->x][this->y - 1] == 5 && map[this->x][this->y - 2] == 3) {
		map[this->x][this->y - 2] = 5;
		map[this->x][this->y - 2] = 7;
		map[this->x][this->y] = 3;
	}
}

/*
   负责人：杨浩
   功能：
		1.判断小人在地图中的那个位置
		2.找到位置后，向右移动
			 可能遇到：
				 1.如果前面是空地，直接进行移动（地图上相应坐标发生变化）
				 2.如果前面是箱子，就要考虑这个箱子是否在目的地上：
					   a.如果下下一个位置是空地或者目的地，那么可以进行移动（地图上坐标就会发生变化）
					   b.如果不是空地或者目的地，那么就是墙壁，不能移动（不用写）
   参数：无
   返回值：无
*/
void Player::moveright() {
	//站在空地，前方是空地的情况
	if (map[this->x][this->y] == 4 && map[this->x][this->y + 1] == 0) {
		map[this->x][this->y + 1] = 4;
		map[this->x][this->y] = 0;
	}
	//站在空地上,前方是目的地
	else if (map[this->x][this->y] == 4 && map[this->x][this->y + 1] == 3) {
		map[this->x][this->y + 1] = 7;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子(箱子不在目的地)，前前方是空地   //////
	else if (map[this->x][this->y] == 4 && map[this->x][this->y + 1] == 2 && map[this->x][this->y + 2] == 0) {
		map[this->x][this->y + 2] = 2;
		map[this->x][this->y + 1] = 4;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子（箱子在目的地），前前方是空地
	else if (map[this->x][this->y] == 4 && map[this->x][this->y + 1] == 5 && map[this->x][this->y + 2] == 0) {
		map[this->x][this->y + 2] = 2;
		map[this->x][this->y + 1] = 7;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子（不在目的地），前前方是目的地
	else if (map[this->x][this->y] == 4 && map[this->x][this->y + 1] == 2 && map[this->x][this->y + 2] == 3) {
		map[this->x][this->y + 2] = 5;
		map[this->x][this->y + 1] = 4;
		map[this->x][this->y] = 0;
	}
	//站在空地，前方是箱子（在目的地），前前方是目的地
	else if (map[this->x][this->y] == 4 && map[this->x][this->y + 1] == 5 && map[this->x][this->y + 2] == 3) {
		map[this->x][this->y + 2] = 5;
		map[this->x][this->y + 1] = 7;
		map[this->x][this->y] = 0;
	}
	//站在目的地，前方是空地
	else if (map[this->x][this->y] == 7 && map[this->x][this->y + 1] == 0) {
		map[this->x][this->y + 1] = 4;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是目的地
	else if (map[this->x][this->y] == 7 && map[this->x][this->y + 1] == 3) {
		map[this->x][this->y + 1] = 7;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（不在目的地），前前方是空地
	else if (map[this->x][this->y] == 7 && map[this->x][this->y + 1] == 2 && map[this->x][this->y + 2] == 0) {
		map[this->x][this->y + 2] = 2;
		map[this->x][this->y + 1] = 4;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（在目的地），前前方是空地
	else if (map[this->x][this->y] == 7 && map[this->x][this->y + 1] == 5 && map[this->x][this->y + 2] == 0) {
		map[this->x][this->y + 2] = 2;
		map[this->x][this->y + 1] = 7;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（不在目的地），前前方是目的地
	else if (map[this->x][this->y] == 7 && map[this->x][this->y + 1] == 2 && map[this->x][this->y + 2] == 3) {
		map[this->x][this->y + 2] = 5;
		map[this->x][this->y + 1] = 4;
		map[this->x][this->y] = 3;
	}
	//站在目的地，前方是箱子（在目的地），前前方是目的地
	else if (map[this->x][this->y] == 7 && map[this->x][this->y + 1] == 5 && map[this->x][this->y + 2] == 3) {
		map[this->x][this->y + 2] = 5;
		map[this->x][this->y + 2] = 7;
		map[this->x][this->y] = 3;
	}
}


//美化
void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	if (dstimg == NULL)
	{
		return;
	}
	// 变量初始化
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = dstimg->getwidth();
	int dst_height = dstimg->getheight();
	// 实现透明贴图 可优化
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
			if (map[i][j] == 0)//空地
				//drawAlpha(&img_wallRound, j * PL, i * PL, &img_wallRound);
				putimage(j * PL, i * PL, &img_wallRound);
			if (map[i][j] == 1)//墙壁
				//drawAlpha(&img_wallRound, j * PL, i * PL, &img_walls);
				putimage(j * PL, i * PL, &img_walls);
			if (map[i][j] == 2)//箱子
				//drawAlpha(&img_wallRound, j * PL, i * PL, &img_box);
				putimage(j * PL, i * PL, &img_box);
			if (map[i][j] == 3)//目的地
				//drawAlpha(&img_wallRound, j * PL + PL / 6, i * PL + PL / 6, &img_endPoint);
				putimage(j * PL + PL / 6, i * PL + PL / 6, &img_endPoint);
			if (map[i][j] == 4 || map[i][j] == 7)//人  6.19 19:05
				//drawAlpha(&img_wallRound, j * PL + PL / 6, i * PL + PL / 6, &img_human);
				putimage(j * PL + PL / 6, i * PL + PL / 6, &img_human);
			if (map[i][j] == 5)//箱子在目的地上
				//drawAlpha(&img_wallRound, j * PL, i * PL, &img_boxf);
				putimage(j * PL, i * PL, &img_boxf);
		}
}

void setPlayer(Player& player) {
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 16; j++)
		{
			if (map[i][j] == 4||map[i][j] == 7)//找人 6.19 18:02
			{
				player.findPlayer(i, j, current_level);
			}
		}
			
}

