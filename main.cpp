#include"MyHeader.h"
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	// 画面モードのセット
	SetGraphMode(WindowSize_Width,WindowSize_Height, 16);
	// ウィンドウモード表示
	ChangeWindowMode(true);
	// 描画先画面を裏画面にする
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
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}