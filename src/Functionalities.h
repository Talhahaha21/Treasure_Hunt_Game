#ifndef FUNCTIONALITIES_F
#define FUNCTIONALITIES_F
#include "Player.h"
#include "Level.h"
#include "ScoreInfo.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;

//Check Content of a Patch
char PatchCheck(Patch* zone, char mode);

//Prints Title
void Title();

//Prints Player States
void PlayerStatus(Player user);

//Prints The Map
void Map(Level lvl, char mode);

//Prints Player Scores
void PlayerScore(Player user);

//Displays Comtrol Menu
void Controls();

//How To Play Menu
void HowTo();

//Display MainMenu
void MainMenu();

//Display Play Options
void PlayMenu();

//Display Type of Edits
void EditMenu();

//Show Difficulty Options
void DifficultyMenu();

//Show Settings
void SettingMenu(bool flag);

//Display Scores
void ScoreBoard(ScoreInfo& list);

//Switch Tester Mode
void TesterMode(bool& tester);

//To Make Console Full Screen by Auto Calling (ALT + Tab)
void AltEnter();

#endif // !FUNCTIONALITIES_F

