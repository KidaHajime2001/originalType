#pragma once
#include"MyHeader.h"
#define STATE_SIZE 6
class enemy
{

public:
	enemy();
	~enemy();
	void Update();
	void draw();
	enum EnemyState
	{
		idle,
		walk,
		jump,
		attack1,
		attack2,
		death,
	};
private:
	
	

};

