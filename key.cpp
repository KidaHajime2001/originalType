#include"MyHeader.h"

My_Key::My_Key()
{
}

My_Key::~My_Key()
{
}

char My_Key::My_putKeyCheck()
{
	if (CheckHitKeyAll()==0)
	{
		// 押されていない
		if (ALL > 0)
		{
			ALL = -1;		// ESCキーが離れた瞬間
		}
		else
		{
			ALL = 0;		// ESCキーが離れている状態
		}
			
	}
	else
	{
		// 押されている
		ALL++;				// ESCキーが押されている間は値を増やし続ける
	}
	if (ALL==1)
	{
		if (CheckHitKey(KEY_INPUT_A)) { return'a'; }
		else if (CheckHitKey(KEY_INPUT_B)) { return'b'; }
		else if (CheckHitKey(KEY_INPUT_C)) { return'c'; }
		else if (CheckHitKey(KEY_INPUT_D)) { return'd'; }
		else if (CheckHitKey(KEY_INPUT_E)) { return'e'; }
		else if (CheckHitKey(KEY_INPUT_F)) { return'f'; }
		else if (CheckHitKey(KEY_INPUT_G)) { return'g'; }
		else if (CheckHitKey(KEY_INPUT_H)) { return'h'; }
		else if (CheckHitKey(KEY_INPUT_I)) { return'i'; }
		else if (CheckHitKey(KEY_INPUT_J)) { return'j'; }
		else if (CheckHitKey(KEY_INPUT_K)) { return'k'; }
		else if (CheckHitKey(KEY_INPUT_L)) { return'l'; }
		else if (CheckHitKey(KEY_INPUT_M)) { return'm'; }
		else if (CheckHitKey(KEY_INPUT_N)) { return'n'; }
		else if (CheckHitKey(KEY_INPUT_O)) { return'o'; }
		else if (CheckHitKey(KEY_INPUT_P)) { return'p'; }
		else if (CheckHitKey(KEY_INPUT_Q)) { return'q'; }
		else if (CheckHitKey(KEY_INPUT_R)) { return'r'; }
		else if (CheckHitKey(KEY_INPUT_S)) { return's'; }
		else if (CheckHitKey(KEY_INPUT_T)) { return't'; }
		else if (CheckHitKey(KEY_INPUT_U)) { return'u'; }
		else if (CheckHitKey(KEY_INPUT_V)) { return'v'; }
		else if (CheckHitKey(KEY_INPUT_W)) { return'w'; }
		else if (CheckHitKey(KEY_INPUT_X)) { return'x'; }
		else if (CheckHitKey(KEY_INPUT_Y)) { return'y'; }
		else if (CheckHitKey(KEY_INPUT_Z)) { return'z'; }
		else if (CheckHitKey(KEY_INPUT_MINUS)) { return'-'; }
		else { return NULL; };
	}
	
	return NULL;
}
