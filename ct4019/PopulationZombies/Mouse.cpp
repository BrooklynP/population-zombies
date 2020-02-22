#include "Mouse.h"
#include "UGFW.h"
#include "UG_Defines.h"
#include "Player.h"
#include "PMathLib.h"
#include <iostream>


Mouse::Mouse()
{
}


Mouse::~Mouse()
{
}

void Mouse::Update() {
	//Update mouse position
	int iX, iY;
	UG::GetMousePos(iX, iY); //stores the current mouse position in the variables
	vPositon.SetX(iX);
	vPositon.SetY(iY);
	Vector2 Right(1, 0);
	Vector2 PosOfMouseRelativeToPlayer = vPositon - player.vPosition;
	float Angle = PedleyMath::FindAngle(Right, PosOfMouseRelativeToPlayer);
	if (vPositon.GetY() < player.vPosition.GetY()) {
		Angle = -Angle;
	}

	//used to determine the distance the bullets should travel in each component.
	YgradientComponent = PedleyMath::FindOppWithHyp(5, Angle);
	XgradientComponent = PedleyMath::FindAdjWithHyp(5, Angle);

	UG::SetSpriteRotation(player.GetSprite(), Angle);
}