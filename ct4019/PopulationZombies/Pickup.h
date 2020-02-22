#include "Vector2Lib.h"
#include"Weapon.h"
#pragma once
class Pickup
{
public:
	Pickup();
	virtual ~Pickup();
	Vector2 m_vPosition;
	virtual void PickupAction() = 0;
private:
	int m_iSprite;
};

class HealthPickup : Pickup {
public:
	HealthPickup() : Pickup() {};
	~HealthPickup() {};
	void PickupAction();
};

class WeaponPickup : Pickup {
public:
	WeaponPickup() : Pickup() {};
	~WeaponPickup() {};
	void PickupAction();
	Weapon* Weapon;
};