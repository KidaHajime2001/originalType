#include "Battle.h"

Battle::Battle()
	:BG(LoadGraph("data/img/haikyo.jpg"))
{
	type = new Typeing;
	mEnemy = new EnemySub_1;
}

Battle::~Battle()
{
	delete type;
	delete mEnemy;
}

void Battle::Draw()
{
	DrawExtendGraph(0, 0, 1920, 1080, BG, true);
	mEnemy->Draw();
	type->Draw();
	
}

void Battle::Update(int StageLevel)
{
	///カウントダウンパート/////

	/////////////////////////
	type->Update();
	mEnemy->Update();
	if (type->getDamegeFlag())
	{
		mEnemy->EventDamege();
	}
	///mainー＞出題
	///タイピングクラスから成功判定を参照
	/// 成功判定が取れれば敵クラスから死亡イベント
	///時間内に成功判定が取れなければ敵クラスからアタックイベント


}
