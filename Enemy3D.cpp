#include"MyHeader.h"

enemy::enemy()
	:model_Handle(0)
{
	int myEnemyImg[20] = {0};
	model_Handle = MV1LoadModel("data/3d/enemy1/enemy1/");
	AnimHandle[EnemyState::idle]= MV1LoadModel("data/3d/enemy1/enemy1/");
	AnimHandle[EnemyState::walk] = MV1LoadModel("data/3d/enemy1/enemy1/");
	AnimHandle[EnemyState::jump] = MV1LoadModel("data/3d/enemy1/enemy1/");
	AnimHandle[EnemyState::attack1] = MV1LoadModel("data/3d/enemy1/enemy1/");
	AnimHandle[EnemyState::attack2] = MV1LoadModel("data/3d/enemy1/enemy1/");
	AnimHandle[EnemyState::death] = MV1LoadModel("data/3d/enemy1/enemy1/");
}

enemy::~enemy()
{
}

void enemy::Update()
{
}

void enemy::draw()
{
}
