#include "Player.h"
#include "UGFW.h"
#include "UG_Defines.h"
#include <string>

Player::Player()
{
	iSprite = -1;
	//UG::CreateSprite("./images/ArmyMan.png", 49.0f, 33.0f, true);
	vPosition = Vector2(512, 384);
	BoxCollider = Collider(vPosition, 49.0f, 33.0f);
}

Player::~Player()
{
}

void Player::DrawSprite() {
	UG::DrawSprite(iSprite);
	//float x;
	//float y;
	//UG::GetSpritePosition(iSprite,x,y);
}
int Player::GetSprite() {
	return  iSprite;
}
void Player::SetSprite(std::string a_sPath) {
	if (iSprite != -1) {
		UG::DestroySprite(iSprite);//destorys sprite previously used, to save RAM
	}
	iSprite = UG::CreateSprite(a_sPath.c_str(), 49.0f, 33.0f, true);
}
void Player::MoveX(float a_iDisplacement) {
	a_iDisplacement *= c_fMovementSpeed;
	vPosition.SetX(vPosition.GetX() + a_iDisplacement);
	UG::SetSpritePosition(iSprite, vPosition.GetX(), vPosition.GetY());
	BoxCollider.MoveX(a_iDisplacement);
}
void Player::MoveY(float a_iDisplacement) {
	a_iDisplacement *= c_fMovementSpeed;
	vPosition.SetY(vPosition.GetY() + a_iDisplacement);
	UG::SetSpritePosition(iSprite, vPosition.GetX(), vPosition.GetY());
	BoxCollider.MoveY(a_iDisplacement);
}