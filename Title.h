#pragma once
#include"MyHeader.h"
class Title:public SceneBase
{
public:
    Title();
    ~Title();
    void Draw();
    SceneBase* Update();
private:
    class Mouse* mouse;
    class Button* B1;
    class MyEffect* ef;

    int title_BG_imgHandle;
};

