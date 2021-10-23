#include"MyHeader.h"

Typeing::Typeing()
	:damegeflag(false)
{
	TextBoxImg=LoadGraph("data/img/Textbox.png");
	mk = new My_Key;
	for (int i = 0; i < 200; i++)
	{
		if (StringConvTable[i].BaseString!=nullptr)
		{
			type_My_Data[i].BaseString = StringConvTable[i].BaseString;
			for (int j = 0; j < 10; j++)
			{

				if (StringConvTable[i].InputChars[j] != nullptr)
				{
					type_My_Data[i].InputChars.push_back(StringConvTable[i].InputChars[j]);
					
				}
			}
		}
		
		
	}
	

	
}

Typeing::~Typeing()
{
	delete mk;
}


void Typeing::Update()
{
	if (damegeflag)
	{
		setDamegeFlag(false);
	}
	CreateRomaJI("とっとこ");
	if (CheckInputRoma(mk->My_putKeyCheck(), TypingData.CompleteIndexNum))
	{
		charstate++;
	}
}

void Typeing::Draw()
{
	printfDx("\n");
	printfDx("%s",ConverterROMA().c_str());
	DrawFormatString(100, 100, GetColor(255, 0, 0), "%s, ", TMP.c_str());
	DrawGraph(0,800,TextBoxImg,true);
	DrawFormatString(100, 150, GetColor(255, 255, 255), "%s, ", InPut.c_str());
	if (damegeflag)
	{
		printfDx("痛い！！！！");
	}
}

void Typeing::CreateRomaJI(string num)
{

	string tmp = {' ','\n',};
	string SUM;
	TypingData.TableIndexNum=0;
	for (int i = 0; i < num.size(); i+=2)
	{
		tmp[0] = num[i];
		tmp[1] = num[i+1];
		for (int j = 0; j < 200; j++)
		{
			if (tmp == type_My_Data[j].BaseString)
			{
				TypingData.TableIndex[TypingData.TableIndexNum] = j;
				TypingData.TableIndexNum++;
				break;
			}
		}
	}
}

bool Typeing::CheckInputRoma(char NowType,int Num)
{
	bool notfound=false;
	for (auto i = 0; i < type_My_Data[TypingData.TableIndex[Num]].InputChars.size(); i++)
	{
		if (type_My_Data[TypingData.TableIndex[Num]].InputChars[i][charstate]!=NULL)
		{
			if (NowType == type_My_Data[TypingData.TableIndex[Num]].InputChars[i][charstate])
			{
				TMP += NowType;
					TypingData.TableIndexPattern[TypingData.nownum] = i;
				TypingData.nownum++;
				if (charstate== type_My_Data[TypingData.TableIndex[Num]].InputChars[i].size()-1)
				{
					charstate = -1;

					InPut+=TMP;
					TMP.clear();
					TypingData.CompleteIndexNum++;
				}
				return true;
			}
		}
		
	}
	if (NowType!=NULL)
	{
		setDamegeFlag(true);
		
	}
	return false;
}

string Typeing::ConverterROMA()
{
	string tmpC;
	for (auto i = 0; i < TypingData.TableIndexNum; i++)
	{
		tmpC += type_My_Data[TypingData.TableIndex[i]].InputChars[TypingData.TableIndexPattern[i*2]];
	}
	return tmpC;
}



