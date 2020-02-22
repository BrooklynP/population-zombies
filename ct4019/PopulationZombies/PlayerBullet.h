#include "Vector2Lib.h"
#pragma once
class PlayerBullet
{
public:
	PlayerBullet(float a_fStartingX, float a_fStartingY, float a_fStartingXVel, float a_fStartingYvel);
	~PlayerBullet();
	Vector2 vPosition;
	Vector2 vVelocity;
	void Draw();
	void Update();
private:
	int iSprite;
};

