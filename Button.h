#pragma once
#include"MyHeader.h"
class Button
{
public:
	Button();
	void ButtonInit(const TCHAR* Filename,int ImgSize_X,int ImgSize_Y);
	~Button();
	void Update(class Mouse* mouse);
	void Draw();
	void SetPosX(int Pos) { ButtonPos_X = Pos; };
	void SetPosY(int Pos) { ButtonPos_Y = Pos; };
	bool HitCheckMouse(int MousePos_X,int MousePos_Y);
	bool GetActionFlag() { return ActionFlag; };
private:
	int  Size_X;
	int  Size_Y;
	bool ActionFlag;
	bool HitMouse;
	int  ButtonPos_X;
	int  ButtonPos_Y;
	int ImgHandle;
};
