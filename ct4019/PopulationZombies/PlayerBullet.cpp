#include "PlayerBullet.h"
#include "UGFW.h"
#include "UG_Defines.h"
#include "GameData.h"
#include<vector>

PlayerBullet::PlayerBullet(float a_fStartingX, float a_fStartingY, float a_fStartingXVel, float a_fStartingYvel)
{
	vPosition = Vector2(a_fStartingX, a_fStartingY);
	vVelocity = Vector2(a_fStartingXVel, a_fStartingYvel);
	iSprite = UG::CreateSprite("./images/Bullet.png", 5, 3, true);
	UG::SetSpritePosition(iSprite, a_fStartingX, a_fStartingY);
	ActiveBullets.push_back(this);//adds bullet to list of active bullets
}


PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Draw() {
	UG::DrawSprite(iSprite);
}
void PlayerBullet::Update() {
	vPosition = vPosition + vVelocity;
	UG::SetSpritePosition(iSprite, vPosition.GetX(), vPosition.GetY());
}