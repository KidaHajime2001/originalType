#pragma once

#include"MyHeader.h"
class Game :public SceneBase
{
public:
    Game();
    ~Game();
    void Draw();
    SceneBase* Update();
    class Typeing* type;
};