#pragma once
#include"MyHeader.h"
class Mouse
{
public:
	Mouse();
	~Mouse();
	//�}�E�X�̏��X�V
	void Update();

	//�}�E�X�̏��l���֐�
	int GetMousePosX();
	int GetMousePosY();
	double GetWheelSize();

	//�}�E�X�̕`��
	void DrawMouse();

	bool GetClickActionFlag() { return PushActionFlag; };
private:
	
	int MouseArrowX;//�ʒuX
	int MouseArrowY;//�ʒuY
	int MouseWheelRot;//�z�C�[���̎擾
	double WheelSize;
	int mouse;
	class MyEffect* ef;

	//��x�������͂��󂯕t����
	bool nowPush;//��������Ă��邩
	int pushState;//������Ă���Ȃ�ΐ��𑝂₵������
	bool PushActionFlag;

};

