#include "ScoreInfo.h"
#include <string>
#include <windows.h>

Info::Info()
{
	Score = NULL;
	Name = " ";
}

//Constructor for Loading Scores and Name from Database to the Program
ScoreInfo::ScoreInfo()
{
	ScoreFile.open("ScoreFile.txt", ios::in);

	if (ScoreFile.is_open())
	{
		while (getline(ScoreFile, PlayerName, '-') && getline(ScoreFile, PlayerScore))
		{
			ScoreList[index].Name = PlayerName;
			ScoreList[index].Score = stoi(PlayerScore);
			index++;
		}
		ScoreFile.close();
	}
}

//Adding Scores and Name in an Array
void ScoreInfo::AddScore(string name, int score)
{
	if (index != 11)
	{
		ScoreList[index].Name = name;
		ScoreList[index].Score = score;
		index++;
	}
	else
	{
		ScoreList[10].Name = name;
		ScoreList[10].Score = score;
	}
	Sort();

}

//Sort Scores in Descending Order
void ScoreInfo::Sort()
{
	for (int outLoop = 0; outLoop < index; outLoop++)
	{
		int inLoop = outLoop;
		while (inLoop > 0 && ScoreList[inLoop].Score > ScoreList[inLoop - 1].Score)
		{
			swap(ScoreList[inLoop], ScoreList[inLoop - 1]);
			inLoop--;
		}
	}
}

//Displaying Scores and Names
void ScoreInfo::Display()
{
	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
	if (index == 11)
	{
		index--;
	}
	for (int loop = 0; loop < index; loop++)
	{
		cout << "\t\t\t\t\t    |  " << loop + 1 << ".  ";
		switch (loop)
		{
		case 0:
			SetConsoleTextAttribute(colour, 6);
			break;
		case 1:
			SetConsoleTextAttribute(colour, 7);
			break;
		case 2:
			SetConsoleTextAttribute(colour, 14);
			break;
		default:
			SetConsoleTextAttribute(colour, 8);
			break;
		}
		cout << ScoreList[loop].Name << "\t\t   ";
		cout << ScoreList[loop].Score;
		SetConsoleTextAttribute(colour, 14);
		cout << "  |." << endl;
	}
}

//Destructor For Storing Scores and Names in Database 
ScoreInfo::~ScoreInfo()
{
	ScoreFile.open("ScoreFile.txt", ios::out);

	if (ScoreFile.is_open())
	{
		for (int loop = 0; loop < index; loop++)
		{
			ScoreFile << ScoreList[loop].Name << '-' << ScoreList[loop].Score << endl;
		}
		ScoreFile.close();
	}
}
