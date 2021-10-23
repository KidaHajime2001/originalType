
#include "EnemySub_1.h"
#include"AssetManager.h"
EnemySub_1::EnemySub_1()
	:State(idle)
	,pos(VGet(0,0,0))
	,animTime(0.0f)
	,P_change(true)
	,Rate(0.0f)
{
	model_Handle = ASSET.GetMesh("data/3d/enemy1/enemy1/mesh_E_!.mv1");
	AnimHandle[EnemyState::idle]	 = ASSET.GetMesh("data/3d/enemy1/enemy1/idle.mv1");
	AnimHandle[EnemyState::walk]	= ASSET.GetMesh("data/3d/enemy1/enemy1/Walking.mv1");
	AnimHandle[EnemyState::jump]	= ASSET.GetMesh("data/3d/enemy1/enemy1/jump.mv1");
	AnimHandle[EnemyState::attack1] = ASSET.GetMesh("data/3d/enemy1/enemy1/at1.mv1");
	AnimHandle[EnemyState::attack2] = ASSET.GetMesh("data/3d/enemy1/enemy1/at2.mv1");
	AnimHandle[EnemyState::death]	= ASSET.GetMesh("data/3d/enemy1/enemy1/damege.mv1");

	animFrames[EnemyState::idle]	= MV1GetAnimTotalTime(AnimHandle[EnemyState::idle]	,1);
	animFrames[EnemyState::walk]	= MV1GetAnimTotalTime(AnimHandle[EnemyState::walk]	, 1);
	animFrames[EnemyState::jump]	= MV1GetAnimTotalTime(AnimHandle[EnemyState::jump], 1);
	animFrames[EnemyState::attack1]	= MV1GetAnimTotalTime(AnimHandle[EnemyState::attack1], 1);
	animFrames[EnemyState::attack2]	= MV1GetAnimTotalTime(AnimHandle[EnemyState::attack2], 1);
	animFrames[EnemyState::death]	= MV1GetAnimTotalTime(AnimHandle[EnemyState::death], 1);

	AttachIndex = MV1AttachAnim(model_Handle, 1, AnimHandle[idle]);
}

EnemySub_1::~EnemySub_1()
{
	ASSET.RemoveMesh(model_Handle);
	ASSET.RemoveMesh(AnimHandle[EnemyState::idle]	);
	ASSET.RemoveMesh(AnimHandle[EnemyState::walk]	);
	ASSET.RemoveMesh(AnimHandle[EnemyState::jump]	);
	ASSET.RemoveMesh(AnimHandle[EnemyState::attack1]);
	ASSET.RemoveMesh(AnimHandle[EnemyState::attack2]);
	ASSET.RemoveMesh(AnimHandle[EnemyState::death]	);
}
/// <summary>
/// マイフレーム読みだす描画用
/// </summary>
void EnemySub_1::Draw()
{
	if (!P_change)
	{
		MyAnimBlend();
		
	}
		// 再生時間をセットする
		MV1SetAttachAnimTime(model_Handle, AttachIndex, animTime);

	
	// ３Ｄモデルの描画
	MV1DrawModel(model_Handle);
}
/// <summary>
/// アップデートマイフレーム読む
/// </summary>
void EnemySub_1::Update()
{
	if (P_change&&State!=idle&&now_animend)
	{
		ChangeAnim(idle);
	}

	animTime+=0.3f;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (animTime>= animFrames[State])
	{
		animTime = 0.0f;
		now_animend = true;
	}

	// ３Dモデルのポジション設定
	MV1SetPosition(model_Handle, pos);
	

}
/// <summary>
/// アニメーションのインデックスを変化させる
/// 変化中flagをオンにする
/// </summary>
/// <param name="index">
/// 新しいアニメーション指定用のインデックス
/// </param>
void EnemySub_1::ChangeAnim(EnemyState index)
{
	if (index==State||!P_change)
	{
		return;
	}
	State = index;

	beforeIndex = MV1AttachAnim(model_Handle, 1, AnimHandle[index]);
	//State = index;
	animTime = 0;
	P_change = false;
	Rate = 0.0f;
	now_animend = false;
}
/// <summary>
/// アニメーションのブレンド
/// ブレンド中のflagを終了時に建てる
/// インデックスを最新にする
/// 状態を最新にする
/// </summary>
void EnemySub_1::MyAnimBlend()
{
	if (Rate<1.0f)
	{
		// 立っているアニメーションのブレンド率をセット
		MV1SetAttachAnimBlendRate(model_Handle, AttachIndex, 1.0f - Rate);

		// 手を前に出しているアニメーションのブレンド率をセット
		MV1SetAttachAnimBlendRate(model_Handle, beforeIndex, Rate);
		Rate+=0.1f;
	}
	else
	{
		P_change = true;
		MV1DetachAnim(model_Handle, AttachIndex);
		AttachIndex = beforeIndex;
	}

}

void EnemySub_1::EventDamege()
{
	ChangeAnim(attack1);
}
