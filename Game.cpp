#include"MyHeader.h"

Game::Game()
{
	//���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(1.0f, 2000.0f);
	SetCameraPositionAndTarget_UpVecY(VGet(0, 80, -200), VGet(0.0f, 80.0f, 0.0f));
	m_bt = new Battle;

}

Game::~Game()
{
	delete m_bt;
}

void Game::Draw()
{
	clsDx();
	printfDx("GAME");
	m_bt->Draw();
}

SceneBase* Game::Update()
{
	m_bt->Update(1);

	//�J��
	if (CheckHitKey(KEY_INPUT_F1))
	{
		return new Title;
	}
	return this;
}

