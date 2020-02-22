#include "PlayerBullet.h"

#pragma once
class GameManager
{
public:
	//Game loop functions
	void TakeUserInput(float a_g_fDeltaSum);
	static void Update(float a_g_fDeltaSum);
	static void DrawCurrentScreen();
	void CreateLevel();
	void CreateWeapons();
	void SpawnEnemy();
	void CreateDjikstraMap();
	static void DetectBulletCollision();
private:
	void ConnectDjikstraNodes();
	static void ShiftIndexForBulletArray(int iIndexToShift);
	static void ShiftIndexForEnemyArray(int iIndexToShift);
};
extern GameManager gamemanager;
