#pragma once
#include"Enemy3D.h"

class EnemySub_1 :public enemy
{
public:
	EnemySub_1();
	~EnemySub_1();
	void Draw();
	void Update();
	void ChangeAnim(EnemyState index);
	void MyAnimBlend();
	void EventDamege();
	//void EventAttack();
	//void EventDeath();
	//void EventWalk();
private:
	int model_Handle;
	int AnimHandle[STATE_SIZE];

	float animFrames[STATE_SIZE];
	int AttachIndex;
	int beforeIndex;
	float animTime;
	EnemyState State;
	EnemyState beforeState;
	VECTOR pos;
	float Rate;
	bool P_change;
	bool now_animend;
};

