#pragma once
#include"MyHeader.h"
class Typeing
{
public:
	Typeing();
	~Typeing();
	void Update();
	void Draw();
	string CreateRomaJI(string num);
	bool CheckInputRoma(char NowType,int Num);
	string ConverterROMA();
private:
	struct CONVDATA
	{
		// ���[�}�����ɕϊ�����O�̕�����
		const char* BaseString;

		// ���͂���A���t�@�x�b�g�̕�����
		const char* InputChars[10];
	};
	struct STRINGDATA
	{
		// ���[�}�����ɕϊ�����O�̕�����
		string BaseString;

		// ���͂���A���t�@�x�b�g�̕�����
		vector<string> InputChars;
		 
	};
	STRINGDATA type_My_Data[200];
	CONVDATA StringConvTable[200]=
	{
		{  "��",           { "a"   } },        {"��",  {"i"       }},       {"��",  {"u"      }},       {"��",   {"e"  }},   {"��",   {"o"  } },
		{ "��",           { "ka","ca"  } },        {"��",  {"ki"      }},       {"��",  {"ku" ,"cu"    }},       {"��",   {"ke" }},   {"��",   {"ko","co" }},
		{ "��",           { "sa"  } },        {"��",  {"si","shi","ci"}},       {"��",  {"su"     }},       {"��",   {"se","ce" }},   {"��",   {"so" }},
		{ "��",           { "ta"  } },        {"��",  {"ti","chi"}},       {"��",  {"tu", "tsu"    }},       {"��",   {"te" }},   {"��",   {"to" }},
		{ "��",           { "na"  } },        {"��",  {"ni"      }},       {"��",  {"nu"     }},       {"��",   {"ne" }},   {"��",   {"no" }},
		{ "��",           { "ha"  } },        {"��",  {"hi"      }},       {"��",  {"hu","fu"}},       {"��",   {"he" }},   {"��",   {"ho" }},
		{ "��",           { "ma"  } },        {"��",  {"mi"      }},       {"��",  {"mu"     }},       {"��",   {"me" }},   {"��",   {"mo" }},
		{ "��",           { "ya"  } },        {"��",  {"yu"      }},       {"��",  {"yo"     }},
		{ "��",           { "ra"  } },        {"��",  {"ri"      }},       {"��",  {"ru"     }},       {"��",   {"re" }},   {"��",   {"ro" }},
		{ "��",           { "wa"  } },        {"��",  {"wo"      }},       {"��",  {"nn","xn"     }},

		{ "��",           { "ga"  } },        {"��",  {"gi"      }},       {"��",  {"gu"     }},       {"��",   {"ge" }},   {"��",   {"go" }},
		{ "��",           { "za"  } },        {"��",  {"zi","ji" }},       {"��",  {"zu"     }},       {"��",   {"ze" }},   {"��",   {"zo" }},
		{ "��",           { "da"  } },        {"��",  {"di"      }},       {"��",  {"du"     }},       {"��",   {"de" }},   {"��",   {"do" }},
		{ "��",           { "ba"  } },        {"��",  {"bi"      }},       {"��",  {"bu"     }},       {"��",   {"be" }},   {"��",   {"bo" }},
		{ "��",           { "pa"  } },        {"��",  {"pi"      }},       {"��",  {"pu"     }},       {"��",   {"pe" }},   {"��",   {"po" }},

		{"����",{"kya"}},{"����",{"kyu"}},{"����",{"kyo"}},
		{"����",{"gya"}},{"����",{"gyu"}},{"����",{"gyo"}},
		{"����",{"sya","sha"}},{"����",{"syu","shu"}},{"����",{"syo","sho"}},{"����",{"sye","she"}},
		{"����",{"jya"}},{"����",{"jyu"}},{"����",{"jyo"}},{"����",{"jye"}},
		{"����",{"tya","cha"}},{"����",{"tyu","chu"}},{"����",{"tyo","cho"}},{"����",{"tye","che"}},
		{"����",{"dya"}},{"����",{"dyu"}},{"����",{"dyo"}},
		{"�ɂ�",{"nya"}},{"�ɂ�",{"nyu"}},{"�ɂ�",{"nyo"}},
		{"�Ђ�",{"hya"}},{"�Ђ�",{"hyu"}},{"�Ђ�",{"hyo"}},
		{"�т�",{"bya"}},{"�т�",{"byu"}},{"�т�",{"byo"}},
		{"�҂�",{"pya"}},{"�҂�",{"pyu"}},{"�҂�",{"pyo"}},
		{"�ӂ�",{"fa"}},{"�ӂ�",{"fi"}},{"�ӂ�",{"fe"}},{"�ӂ�",{"fo"}},
		{"�݂�",{"mya"}},{"�݂�",{"myu"}},{"�݂�",{"myo"}},
		{"���",{"rya"}},{"���",{"ryu"}},{"���",{"ryo"}},

		{"��",{"la","xa"}},{"��",{"li","xi"}},{"��",{"lu","xu"}},{"��",{"le","xe"}},{"��",{"lo","xo"}},
		{"��",{"lya","xya"}},{"��",{"lyu","xyu"}},{"��",{"lyo","xyo"}},
		{"��",{"lwa","xwa"}},
		{"����",{"wha"}},{"����",{"wi"}},{"����",{"we"}},{"����",{"who"}},
		{"����",{"va"}},{"����",{"vi"}},{"��",{"vu"}},{"����",{"ve"}},{"����",{"vo"}},
		{"�Ă�",{"thi"}},{"�ł�",{"dhi"}},{"�ł�",{"dhu"}},{"�[",{"-"}},

		{NULL,{NULL}},
	};

	struct TYPINGDATA
	{
		// ���͂��ׂ��������ϊ��e�[�u���̑Ή�����C���f�b�N�X�ɒu������������
		int TableIndex[512];

		// �C���f�b�N�X�̐�
		int TableIndexNum=0;

		// ���͂����������C���f�b�N�X�̐�
		int CompleteIndexNum=0;

		// ���ݓ��͒��̕�����
		char TypingString[20];

		// ���͂���������������
		char CompletionString[512];
		//���̕�����
		int nownum=0;
		//
		int TableIndexPattern[512];
	};
	TYPINGDATA TypingData;
	class My_Key* mk;
	string InPut;
	char Name[31];
	int charstate = 0;
	string TMP;
	struct TMPROMA
	{
		string Roma;
		int chooseNum=0;
	};
	TMPROMA myROMAJI;
};
