#pragma once
#include"MyHeader.h"
class Mouse
{
public:
	Mouse();
	~Mouse();
	//マウスの情報更新
	void Update();

	//マウスの情報獲得関数
	int GetMousePosX();
	int GetMousePosY();
	double GetWheelSize();

	//マウスの描画
	void DrawMouse();

	bool GetClickActionFlag() { return PushActionFlag; };
private:
	
	int MouseArrowX;//位置X
	int MouseArrowY;//位置Y
	int MouseWheelRot;//ホイールの取得
	double WheelSize;
	int mouse;
	class MyEffect* ef;

	//一度だけ入力を受け付ける
	bool nowPush;//今推されているか
	int pushState;//推されているならば数を増やし続ける
	bool PushActionFlag;

};

