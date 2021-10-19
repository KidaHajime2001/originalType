#include"MyHeader.h"
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(WindowSize_Width,WindowSize_Height, 16);
	// �E�B���h�E���[�h�\��
	ChangeWindowMode(true);
	// �`����ʂ𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);
	SceneBase* nowScene;
	MyEffect* ef = new MyEffect;
	ef->EF_Init();
	nowScene = new Title;
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0&&!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen())
	{
		SceneBase* TMPScene;

		TMPScene = nowScene->Update();
		nowScene->Draw();
		
		if (TMPScene != nowScene)
		{
			WaitTimer(200);
			delete nowScene;
			nowScene = TMPScene;

		}
	}
	ef->EndEF();
	delete ef;
	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}