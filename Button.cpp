#include"MyHeader.h"

Button::Button()
	:Size_X(0)
,Size_Y(0)
,ActionFlag(false)
,HitMouse(false)
,ButtonPos_X(0)
,ButtonPos_Y(0)
{

}

void Button::ButtonInit(const TCHAR* Filename, int ImgSize_X, int ImgSize_Y)
{
	ImgHandle = LoadGraph(Filename);
	Size_X = ImgSize_X;
	Size_Y = ImgSize_Y;
}

Button::~Button()
{
	DeleteGraph(ImgHandle);
}

void Button::Update(class Mouse* mouse)
{
	HitMouse = false;
	if (HitCheckMouse(mouse->GetMousePosX(),mouse->GetMousePosY()))
	{
		HitMouse = true;
		if (mouse->GetClickActionFlag())
		{
			ActionFlag = true;
		}
	}

}

void Button::Draw()
{
	
	DrawGraph(ButtonPos_X, ButtonPos_Y, ImgHandle, true);
	if (HitMouse)
	{
		SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
		DrawGraph(ButtonPos_X, ButtonPos_Y, ImgHandle, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
}

bool Button::HitCheckMouse(int MousePos_X, int MousePos_Y)
{
	if (ButtonPos_X <= MousePos_X &&
		ButtonPos_Y <= MousePos_Y&&
		ButtonPos_X + Size_X >= MousePos_X &&
		ButtonPos_Y + Size_Y >= MousePos_Y)
	{
		return true;
	}
	return false;
}
