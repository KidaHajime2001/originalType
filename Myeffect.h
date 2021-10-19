#pragma once
#include"MyHeader.h"
class MyEffect
{
public:
	MyEffect();
	~MyEffect();
	void EF_Update();
	void EF_Init();
	void LoadEF(const char* EF_Filename);
	void PlayEF();
	void set_EF_Pos(const float& posX, const float& posY);
	void Set_Expansion(const float Rate) { expansion_rate = Rate; };
	void EndEF();
private:
	int effectResourceHandle;//load���Ă���G�t�F�N�g�n���h��
	int playingEffectHandle;//�Đ����Ă���G�t�F�N�g�n���h��
	bool PlayEF_Flag;
	float EF_POS_X;
	float EF_POS_Y;
	float expansion_rate;
};

