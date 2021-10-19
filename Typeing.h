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
		// ローマ仮名に変換する前の文字列
		const char* BaseString;

		// 入力するアルファベットの文字列
		const char* InputChars[10];
	};
	struct STRINGDATA
	{
		// ローマ仮名に変換する前の文字列
		string BaseString;

		// 入力するアルファベットの文字列
		vector<string> InputChars;
		 
	};
	STRINGDATA type_My_Data[200];
	CONVDATA StringConvTable[200]=
	{
		{  "あ",           { "a"   } },        {"い",  {"i"       }},       {"う",  {"u"      }},       {"え",   {"e"  }},   {"お",   {"o"  } },
		{ "か",           { "ka","ca"  } },        {"き",  {"ki"      }},       {"く",  {"ku" ,"cu"    }},       {"け",   {"ke" }},   {"こ",   {"ko","co" }},
		{ "さ",           { "sa"  } },        {"し",  {"si","shi","ci"}},       {"す",  {"su"     }},       {"せ",   {"se","ce" }},   {"そ",   {"so" }},
		{ "た",           { "ta"  } },        {"ち",  {"ti","chi"}},       {"つ",  {"tu", "tsu"    }},       {"て",   {"te" }},   {"と",   {"to" }},
		{ "な",           { "na"  } },        {"に",  {"ni"      }},       {"ぬ",  {"nu"     }},       {"ね",   {"ne" }},   {"の",   {"no" }},
		{ "は",           { "ha"  } },        {"ひ",  {"hi"      }},       {"ふ",  {"hu","fu"}},       {"へ",   {"he" }},   {"ほ",   {"ho" }},
		{ "ま",           { "ma"  } },        {"み",  {"mi"      }},       {"む",  {"mu"     }},       {"め",   {"me" }},   {"も",   {"mo" }},
		{ "や",           { "ya"  } },        {"ゆ",  {"yu"      }},       {"よ",  {"yo"     }},
		{ "ら",           { "ra"  } },        {"り",  {"ri"      }},       {"る",  {"ru"     }},       {"れ",   {"re" }},   {"ろ",   {"ro" }},
		{ "わ",           { "wa"  } },        {"を",  {"wo"      }},       {"ん",  {"nn","xn"     }},

		{ "が",           { "ga"  } },        {"ぎ",  {"gi"      }},       {"ぐ",  {"gu"     }},       {"げ",   {"ge" }},   {"ご",   {"go" }},
		{ "ざ",           { "za"  } },        {"じ",  {"zi","ji" }},       {"ず",  {"zu"     }},       {"ぜ",   {"ze" }},   {"ぞ",   {"zo" }},
		{ "だ",           { "da"  } },        {"ぢ",  {"di"      }},       {"づ",  {"du"     }},       {"で",   {"de" }},   {"ど",   {"do" }},
		{ "ば",           { "ba"  } },        {"び",  {"bi"      }},       {"ぶ",  {"bu"     }},       {"べ",   {"be" }},   {"ぼ",   {"bo" }},
		{ "ぱ",           { "pa"  } },        {"ぴ",  {"pi"      }},       {"ぷ",  {"pu"     }},       {"ぺ",   {"pe" }},   {"ぽ",   {"po" }},

		{"きゃ",{"kya"}},{"きゅ",{"kyu"}},{"きょ",{"kyo"}},
		{"ぎゃ",{"gya"}},{"ぎゅ",{"gyu"}},{"ぎょ",{"gyo"}},
		{"しゃ",{"sya","sha"}},{"しゅ",{"syu","shu"}},{"しょ",{"syo","sho"}},{"しぇ",{"sye","she"}},
		{"じゃ",{"jya"}},{"じゅ",{"jyu"}},{"じょ",{"jyo"}},{"じぇ",{"jye"}},
		{"ちゃ",{"tya","cha"}},{"ちゅ",{"tyu","chu"}},{"ちょ",{"tyo","cho"}},{"ちぇ",{"tye","che"}},
		{"ぢゃ",{"dya"}},{"ぢゅ",{"dyu"}},{"ぢょ",{"dyo"}},
		{"にゃ",{"nya"}},{"にゅ",{"nyu"}},{"にょ",{"nyo"}},
		{"ひゃ",{"hya"}},{"ひゅ",{"hyu"}},{"ひょ",{"hyo"}},
		{"びゃ",{"bya"}},{"びゅ",{"byu"}},{"びょ",{"byo"}},
		{"ぴゃ",{"pya"}},{"ぴゅ",{"pyu"}},{"ぴょ",{"pyo"}},
		{"ふぁ",{"fa"}},{"ふぃ",{"fi"}},{"ふぇ",{"fe"}},{"ふぉ",{"fo"}},
		{"みゃ",{"mya"}},{"みゅ",{"myu"}},{"みょ",{"myo"}},
		{"りゃ",{"rya"}},{"りゅ",{"ryu"}},{"りょ",{"ryo"}},

		{"ぁ",{"la","xa"}},{"ぃ",{"li","xi"}},{"ぅ",{"lu","xu"}},{"ぇ",{"le","xe"}},{"ぉ",{"lo","xo"}},
		{"ゃ",{"lya","xya"}},{"ゅ",{"lyu","xyu"}},{"ょ",{"lyo","xyo"}},
		{"ゎ",{"lwa","xwa"}},
		{"うぁ",{"wha"}},{"うぃ",{"wi"}},{"うぇ",{"we"}},{"うぉ",{"who"}},
		{"ヴぁ",{"va"}},{"ヴぃ",{"vi"}},{"ヴ",{"vu"}},{"ヴぇ",{"ve"}},{"ヴぉ",{"vo"}},
		{"てぃ",{"thi"}},{"でぃ",{"dhi"}},{"でゅ",{"dhu"}},{"ー",{"-"}},

		{NULL,{NULL}},
	};

	struct TYPINGDATA
	{
		// 入力すべき文字列を変換テーブルの対応するインデックスに置き換えたもの
		int TableIndex[512];

		// インデックスの数
		int TableIndexNum=0;

		// 入力が完了したインデックスの数
		int CompleteIndexNum=0;

		// 現在入力中の文字列
		char TypingString[20];

		// 入力が完了した文字列
		char CompletionString[512];
		//今の文字数
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
