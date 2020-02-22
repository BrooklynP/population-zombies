#include "Enemy.h"
#include "UGFW.h"
#include "UG_Defines.h"
#include "PMathLib.h"
#include "Player.h"



Enemy::Enemy()
{
}
Enemy::Enemy(std::string a_sPath, float a_fX, float a_fY, int a_iHealthPoints) {
	m_iSprite = UG::CreateSprite(a_sPath.c_str(), 64.0f, 32.0f, true);
	UG::SetSpritePosition(m_iSprite, a_fX, a_fY);
	m_vPosition = Vector2(a_fX, a_fY);
	m_cBoxCollider = Collider(m_vPosition, 64.0f, 32.0f);
	m_iHealthPoints = a_iHealthPoints;
	m_dnTargetNode = DjikstraNode(0, 0);
}
Enemy::Enemy(std::string a_sPath, int a_iHealthPoints) {
	Vector2 RandomVector;
	RandomVector = RandomVector.RandomVector();
	m_iSprite = UG::CreateSprite(a_sPath.c_str(), 64.0f, 32.0f, true);
	UG::SetSpritePosition(m_iSprite, RandomVector.GetX(), RandomVector.GetY());
	m_vPosition = Vector2(RandomVector.GetX(), RandomVector.GetY());
	m_cBoxCollider = Collider(m_vPosition, 64.0f, 32.0f);
	m_iHealthPoints = a_iHealthPoints;
	m_dnTargetNode = DjikstraNode(0, 0);
}

Enemy::~Enemy()
{
}

void Enemy::SetSprite(std::string a_sPath) {
	if (m_iSprite > 0) {
		UG::DestroySprite(m_iSprite);//destorys sprite previously used, to save RAM
	}
	m_iSprite = UG::CreateSprite(a_sPath.c_str(), 64.0f, 32.0f, true);
}

int Enemy::GetSprite() {
	return  m_iSprite;
}
void Enemy::DrawSprite() {
	UG::DrawSprite(m_iSprite);
}

void Enemy::UpdateRotation() {
	int iX, iY;

	Vector2 Right(1, 0);
	Vector2 PosOfPlayerRelativeToZombie = player.vPosition - m_vPosition;
	float Angle = PedleyMath::FindAngle(Right, PosOfPlayerRelativeToZombie);
	if (player.vPosition.GetY() < m_vPosition.GetY()) {
		Angle = -Angle;
	}
	UG::SetSpriteRotation(m_iSprite, Angle);
}

void Enemy::Hit() {
	m_iHealthPoints -= player.wCurrentWeapon.m_iAttackDamage;
}

int Enemy::GetHP() {
	return m_iHealthPoints;
}