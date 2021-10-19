#include "Myeffect.h"

MyEffect::MyEffect()
	:PlayEF_Flag(false)
	,playingEffectHandle(0)
	,effectResourceHandle(0)
	,EF_POS_X(-100)
	,EF_POS_Y(-100)
	,expansion_rate(1.0f)
{

	
}

MyEffect::~MyEffect()
{
	

	
}

void MyEffect::EF_Update()
{
	
	if (PlayEF_Flag)
	{
		SetPosPlayingEffekseer2DEffect(playingEffectHandle, EF_POS_X, EF_POS_Y, 0);
	}
	if (!IsEffekseer2DEffectPlaying(playingEffectHandle))
	{
		PlayEF_Flag = false;
	}
	// Effekseerの更新
	UpdateEffekseer2D();
	UpdateEffekseer3D();
	// Effekseerの描画
	DrawEffekseer2D();
	DrawEffekseer3D();
	

}

void MyEffect::EF_Init()
{
	// DirectX11を使用するようにする。(DirectX9も可、一部機能不可)
	// Effekseerを使用するには必ず設定する。
	SetUseDirect3DVersion(DX_DIRECT3D_11);

	// Effekseerを初期化する。
	// 引数には画面に表示する最大パーティクル数を設定する。
	if (Effkseer_Init(8000) == -1)
	{
		DxLib_End();
	}
	// フルスクリーンウインドウの切り替えでリソースが消えるのを防ぐ。
	// Effekseerを使用する場合は必ず設定する。
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

	// DXライブラリのデバイスロストした時のコールバックを設定する。
	// ウインドウとフルスクリーンの切り替えが発生する場合は必ず実行する。
	// ただし、DirectX11を使用する場合は実行する必要はない。
	Effekseer_SetGraphicsDeviceLostCallbackFunctions();
	// Effekseerに2D描画の設定をする。
	Effekseer_Set2DSetting(WindowSize_Width, WindowSize_Height);

	SetUseZBuffer3D(TRUE);                                    // ZBufferを使用
	SetWriteZBuffer3D(TRUE);                                  // ZBufferへの書き込みを許可
}

void MyEffect::LoadEF(const char* EF_Filename)
{
	effectResourceHandle = LoadEffekseerEffect(EF_Filename, expansion_rate);
}

void MyEffect::PlayEF()
{
	if (!PlayEF_Flag)
	{
		PlayEF_Flag = true;
	}
	// エフェクトを再生する。
	playingEffectHandle = PlayEffekseer2DEffect(effectResourceHandle);
}

void MyEffect::set_EF_Pos(const float& posX, const float& posY)
{
	EF_POS_X = posX;
	EF_POS_Y = posY;
}

void MyEffect::EndEF()
{
	// Effekseerを終了する。
	Effkseer_End();
}
