#include "Vector2Lib.h"
#pragma once
class Collider
{
public:
	Collider();
	Collider(float a_fTopY, float a_fBottomY, float a_LeftX, float a_RightX);
	Collider(Vector2 a_vCenter, float a_fWidth, float a_fHeight);
	bool IsCollidingWithC(Collider a_cCollider);	//Collisiion detection between two colliders  (mainly used to stop entities walking through objects)
	bool IsCollidingWithP(Vector2 a_vPosition);		//Collision detection with another point (Bullets are point objects as the complexity to use box bullets is too much for the amount of bullets that will be in play)
	~Collider();
	float GetLeftX();
	float GetRightX();
	float GetTopY();
	float GetBottomY();
	void MoveX(int a_iDisplacement);
	void MoveY(int a_iDisplacement);
private:
	float TopY;
	float BottomY;
	float LeftX;
	float RightX;
};

