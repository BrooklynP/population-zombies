#include "Vector2Lib.h"
#include"Collider.h"
#pragma once
class GameObject
{
public:
	Vector2 vPosition;
	Collider cCollider;
	GameObject(const char* SpritePath, float a_fStartingX, float a_fStartingY, float a_fHeight, float a_fWidth);
	~GameObject();
	int GetSprite();
	void Draw();
private:
	int iSprite;
};

