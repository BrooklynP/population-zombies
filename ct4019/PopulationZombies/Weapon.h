#pragma once
class Weapon
{
public:
	Weapon();
	~Weapon();
	virtual void Shoot(float a_g_fDeltaSum);
	int m_iAttackDamage;
private:
	float m_fFireRate;
	float m_fFireRateTimer;
};