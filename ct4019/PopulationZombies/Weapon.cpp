#include "Weapon.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Mouse.h"



Weapon::Weapon()
	: m_iAttackDamage(1)
	, m_fFireRate(0.03f)
	, m_fFireRateTimer(0.0f)
{
}

Weapon::~Weapon()
{
}

void Weapon::Shoot(float a_g_fDeltaSum) {
	if (m_fFireRateTimer < m_fFireRate) {
		m_fFireRateTimer += a_g_fDeltaSum;
	}
	else if (m_fFireRateTimer >= m_fFireRate) {
		m_fFireRateTimer = 0.0f;
		new PlayerBullet(player.vPosition.GetX(), player.vPosition.GetY(), mouse.XgradientComponent, mouse.YgradientComponent);
	}
}