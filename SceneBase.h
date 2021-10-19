#pragma once
#include"MyHeader.h"
class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();
	virtual void Draw();
	virtual SceneBase* Update();
private:

};
