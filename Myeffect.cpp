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
	// Effekseer�̍X�V
	UpdateEffekseer2D();
	UpdateEffekseer3D();
	// Effekseer�̕`��
	DrawEffekseer2D();
	DrawEffekseer3D();
	

}

void MyEffect::EF_Init()
{
	// DirectX11���g�p����悤�ɂ���B(DirectX9���A�ꕔ�@�\�s��)
	// Effekseer���g�p����ɂ͕K���ݒ肷��B
	SetUseDirect3DVersion(DX_DIRECT3D_11);

	// Effekseer������������B
	// �����ɂ͉�ʂɕ\������ő�p�[�e�B�N������ݒ肷��B
	if (Effkseer_Init(8000) == -1)
	{
		DxLib_End();
	}
	// �t���X�N���[���E�C���h�E�̐؂�ւ��Ń��\�[�X��������̂�h���B
	// Effekseer���g�p����ꍇ�͕K���ݒ肷��B
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

	// DX���C�u�����̃f�o�C�X���X�g�������̃R�[���o�b�N��ݒ肷��B
	// �E�C���h�E�ƃt���X�N���[���̐؂�ւ�����������ꍇ�͕K�����s����B
	// �������ADirectX11���g�p����ꍇ�͎��s����K�v�͂Ȃ��B
	Effekseer_SetGraphicsDeviceLostCallbackFunctions();
	// Effekseer��2D�`��̐ݒ������B
	Effekseer_Set2DSetting(WindowSize_Width, WindowSize_Height);

	SetUseZBuffer3D(TRUE);                                    // ZBuffer���g�p
	SetWriteZBuffer3D(TRUE);                                  // ZBuffer�ւ̏������݂�����
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
	// �G�t�F�N�g���Đ�����B
	playingEffectHandle = PlayEffekseer2DEffect(effectResourceHandle);
}

void MyEffect::set_EF_Pos(const float& posX, const float& posY)
{
	EF_POS_X = posX;
	EF_POS_Y = posY;
}

void MyEffect::EndEF()
{
	// Effekseer���I������B
	Effkseer_End();
}
