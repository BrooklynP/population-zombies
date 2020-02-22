#include <vector>	
#include <map>
#include "PlayerBullet.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Vector2Lib.h"

#pragma once
extern std::vector<PlayerBullet*> ActiveBullets;
extern std::vector<GameObject*> ActiveLevelObjects;
extern std::vector<Enemy*> ActiveEnemies;
extern std::map<const std::string, Weapon*> AvailableWeapons;

extern std::vector<DjikstraNode> v_DjikstrasMapOfLevel;

const int gc_iTopOfScreenY = 768;
const int gc_iBottomOfScreenY = 0;
const int gc_iLeftOfScreenX = 0;
const int gc_iRightOfScreenX = 1024;