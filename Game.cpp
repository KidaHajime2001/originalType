#include"MyHeader.h"

Game::Game()
{
	type = new Typeing;
}

Game::~Game()
{
	delete type;
}

void Game::Draw()
{
	clsDx();
	printfDx("GAME");
	type->Draw();
}

SceneBase* Game::Update()
{
	type->Update();
	//‘JˆÚ
	if (CheckHitKey(KEY_INPUT_F1))
	{
		return new Title;
	}
	return this;
}

