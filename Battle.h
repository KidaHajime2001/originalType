#pragma once
#include"MyHeader.h"
class Battle
{
public:
	Battle();
	~Battle();
	void Draw();
	void Update(int StageLevel);

private:
	class Typeing* type;
	class EnemySub_1* mEnemy;
	int start_Count;
	int now_Count;
	int BG;
};
