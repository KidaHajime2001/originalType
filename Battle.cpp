#include "Battle.h"

Battle::Battle()
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
	type->Draw();
	mEnemy->Draw();
}

void Battle::Update(int StageLevel)
{
	///�J�E���g�_�E���p�[�g/////

	/////////////////////////
	type->Update();
	mEnemy->Update();
	if (type->getDamegeFlag())
	{
		mEnemy->EventDamege();
	}
	///main�[���o��
	///�^�C�s���O�N���X���琬��������Q��
	/// �������肪����ΓG�N���X���玀�S�C�x���g
	///���ԓ��ɐ������肪���Ȃ���ΓG�N���X����A�^�b�N�C�x���g


}
