#include"MyHeader.h"

Mouse::Mouse()
	:MouseArrowX(WindowSize_Width / 2)
	, MouseArrowY(WindowSize_Height / 2)
	, WheelSize(0)
	, mouse(0)
	,MouseWheelRot(0)
	,pushState(0)
	,nowPush(false)
	,PushActionFlag(false)
{
	ef = new MyEffect;
	ef->EF_Init();
	ef->Set_Expansion(10.0f);
	ef->LoadEF("data/efk/click.efkefc");
	WheelSize = 0;
	
}

Mouse::~Mouse()
{
	delete ef;
}

void Mouse::Update()
{
	
	mouse = GetMouseInput();
	MouseWheelRot = GetMouseWheelRotVol();
	GetMousePoint(&MouseArrowX, &MouseArrowY);                //�}�E�X�̍��W�擾

	if (mouse & MOUSE_INPUT_LEFT) { //�}�E�X�̍��{�^����������Ă�����
		nowPush = true;

	}
	else
	{
		nowPush = false;
		pushState = 0;
	}
	if (nowPush)
	{
		pushState++;
	}
	if (pushState==1)
	{
		PushActionFlag = true;
	}
	else
	{
		PushActionFlag = false;
	}
	if (MouseWheelRot > 0) {        //�z�C�[����+�����ɉ�]���Ă�����
		WheelSize += 0.1;
	}
	if (MouseWheelRot < 0) {        //�z�C�[�����|�����ɉ�]���Ă�����
		WheelSize -= 0.1;
	}
	ef->set_EF_Pos((float)MouseArrowX,(float)MouseArrowY);
	
}

int Mouse::GetMousePosX()
{
	return MouseArrowX;
}

int Mouse::GetMousePosY()
{
	return MouseArrowY;
}

double Mouse::GetWheelSize()
{
	return WheelSize;
}



void Mouse::DrawMouse()
{
	
	printfDx("\nmouseX:%d\n",MouseArrowX);
	printfDx("mouseY%d\n", MouseArrowY);
	printfDx("mouseW%lf\n", WheelSize);

	if (PushActionFlag)
	{

		ef->PlayEF();
	}
	ef->EF_Update();
}
