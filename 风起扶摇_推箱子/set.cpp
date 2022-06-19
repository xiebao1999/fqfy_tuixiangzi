#include"set.h"


void music(int music_sign = 2) {
    if (music_sign == 1) {
        mciSendString("pause BGM", 0, 0, 0);
    }
    else if (music_sign == 0) {
        mciSendString("resume BGM", 0, 0, 0);
    }
    else if (music_sign == 2) {
        mciSendString("close BGM", 0, 0, 0);
        mciSendString("open ./music/音效一.mp3 alias BGM", 0, 0, 0);
        mciSendString("play BGM repeat", 0, 0, 0);
    }
    else if (music_sign == 3) {
        mciSendString("close BGM", 0, 0, 0);
        mciSendString("open ./music/音效二.mp3 alias BGM", 0, 0, 0);
        mciSendString("play BGM repeat", 0, 0, 0);
    }
}

void SetMap() {
    cleardevice();
    setfillcolor(BROWN);
    putimage(0, 0, &img_set);
    int PL = 30;
    int b1 = 5;
    int b11 = 9;
    int b2 = 14;
    int b22 = 18;
    setbkmode(TRANSPARENT);
    settextcolor(GREEN);
    fillrectangle(PL * b1, PL * 5, PL * b11, PL * 6);
    RECT r = { PL * b1, PL * 5, PL * b11, PL * 6 };
    drawtext(_T("音效一"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    fillrectangle(PL * b2, PL * 5, PL * b22, PL * 6);
    r = { PL * b2, PL * 5, PL * b22, PL * 6 };
    drawtext(_T("音效二"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    fillrectangle(PL * b1, PL * 9, PL * b11, PL * 10);
    r = { PL * b1, PL * 9, PL * b11, PL * 10 };
    drawtext(_T("开关音效"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    fillrectangle(PL * b2, PL * 9, PL * b22, PL * 10);
    r = { PL * b2, PL * 9, PL * b22, PL * 10 };
    drawtext(_T("返回菜单"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    FlushBatchDraw();


    ExMessage msg;
    int set_flag=1;
    while (set_flag) {
        if (peekmessage(&msg, EM_MOUSE)) {
            switch (msg.message) {
            case WM_LBUTTONDOWN:
                if (msg.x > PL * b1 &&
                    msg.x < PL * b11 &&
                    msg.y > PL * 5 &&
                    msg.y < PL * 6
                    ) {
                    music_sign = 2;
                    music(music_sign);
                }
                else if (msg.x > PL * b2 &&
                    msg.x < PL * b22 &&
                    msg.y > PL * 5 &&
                    msg.y < PL * 6
                    ) {
                    music_sign = 3;
                    music(music_sign);
                }
                else if (msg.x > PL * b1 &&
                    msg.x < PL * b11 &&
                    msg.y > PL * 9 &&
                    msg.y < PL * 10
                    ) {
                    music_sign ^= 1;
                    music(music_sign);
                }
                //更新返回按钮坐标 6.19-18：15
                else if (msg.x > PL * b2 &&
                    msg.x < PL * b22 &&
                    msg.y > PL * 9 &&
                    msg.y < PL * 10
                    ) {
                    set_flag =0;
                    cout<<set_flag<<" "<<msg.x;
                }
                break;
            default:
                break;
            }
        }
    }
}
