#include "Vector2Lib.h"
#include"Collider.h"
#include <string>

#pragma once
class Enemy
{
public:
	Enemy();
	Enemy(std::string a_sPath, float a_fX, float a_fY, int a_iHealthPoints);
	Enemy(std::string a_sPath, int a_iHealthPoints);
	~Enemy();
	Vector2 m_vPosition;
	Collider m_cBoxCollider;
	DjikstraNode m_dnTargetNode;
	DjikstraNode m_dnCurrentNode;
	void DrawSprite();
	int GetSprite();
	void SetSprite(std::string a_sPath);
	void UpdateRotation();
	void Hit();
	int GetHP();
private:
	int m_iMoveSpeed;
	int m_iHealthPoints;
	int m_iAttackDamage;
	int m_iSprite;
};

