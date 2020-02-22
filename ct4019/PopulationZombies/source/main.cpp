//\===========================================================================================================================================
//\ Filename: main.cpp
//\ Author  : Brooklyn Pedley
//\ Date    : 02/02/2018
//\ Brief   : Programming and maths assignemnt 2
//\===========================================================================================================================================

#include "UGFW.h"
#include "UG_Defines.h"
#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"

GameManager gamemanager;
Player player;

float deltatime;//Time taken between processes

int main(int argv, char* argc[])
{
	if (!UG::Create(1024, 768, false, "Sample", 100, 100)) { 
		return 1; 
	}
	UG::SetBackgroundColor(UG::SColour(0xC2, 0xB2, 0x80, 0xFF)); //Teal
	player.SetSprite("./images/ArmyMan.png");
	UG::SetSpritePosition(player.GetSprite(), 512,  384);

	const int iFont = UG::AddFont("./fonts/Exquisite Corpse.ttf", 32);
	UG::SetFont(iFont);

	gamemanager.CreateLevel();
	do 
	{
		deltatime = UG::GetDeltaTime();
		gamemanager.TakeUserInput(deltatime);
		gamemanager.Update(deltatime);
		gamemanager.DrawCurrentScreen();
	} while (UG::Process());

	UG::Dispose();
	return 0;
}
