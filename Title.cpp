#include"MyHeader.h"
Title::Title()
{
	
	ef = new MyEffect;
	mouse = new Mouse;
	B1 = new Button();
	B1->ButtonInit("data/img/Button1.png",500,500);
	B1->SetPosX(0);
	B1->SetPosY(300);
	title_BG_imgHandle = LoadGraph("data/img/Title_BG.jpg");
}

Title::~Title()
{
	delete mouse;
	delete B1;
	DeleteGraph(title_BG_imgHandle);
}

void Title::Draw()
{
	DrawExtendGraph(0, 0,WindowSize_Width,WindowSize_Height, title_BG_imgHandle, false);
	
	clsDx();
	printfDx("Title");
	B1->Draw();
	mouse->DrawMouse();
	
}

SceneBase* Title::Update()
{
	mouse->Update();
	B1->Update(mouse);
	if (B1->GetActionFlag())
	{
		return new Game;
	}
	return this;
}
