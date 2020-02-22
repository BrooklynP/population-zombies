#include "Vector2Lib.h"
#include "Collider.h"
#include "Weapon.h"
#include <string>

#pragma once
class Player
{
public:
	Player();
	~Player();
	Vector2 vPosition;
	Collider BoxCollider;
	Weapon wCurrentWeapon;
	void DrawSprite();
	int GetSprite();
	void SetSprite(std::string a_sPath);
	void MoveX(float a_iDisplacement);
	void MoveY(float a_iDisplacement);
private:
	int iSprite;
	const float c_fMovementSpeed = 3;
	int m_iHealthPoints;
};
extern Player player;