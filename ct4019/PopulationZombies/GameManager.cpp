#include "GameManager.h"
#include "UGFW.h"
#include "UG_Defines.h"
#include "Player.h"
#include <iostream>
#include "PMathLib.h"
#include "PlayerBullet.h"
#include "Mouse.h"
#include "GameObject.h"
#include "GameData.h"
#include "Weapon.h"
#include <vector>
#include<cstdlib>

Mouse mouse;
PedleyMath math;
std::vector<GameObject*> ActiveLevelObjects;
std::vector<PlayerBullet*> ActiveBullets;
std::map<const std::string, Weapon*> AvailableWeapons;
std::vector<DjikstraNode> v_DjikstrasMapOfLevel;
std::vector<Enemy*> v_AliveEnemies;

const int c_iMaxNumberOfEnemies = 10;
int PlayerScore = 0;

void GameManager::TakeUserInput(float a_g_fDeltaSum)
{
	if (UG::IsKeyDown(UG::KEY_W)) {
		player.MoveY(1);
		for (std::vector<GameObject*>::size_type i = 0; i != ActiveLevelObjects.size(); i++) {
			if (player.BoxCollider.IsCollidingWithC(ActiveLevelObjects[i]->cCollider)) {
				player.MoveY(-1);
			}
		}
		if (player.BoxCollider.GetTopY() > gc_iTopOfScreenY) {
			player.MoveY(-1);
		}
	}
	else if (UG::IsKeyDown(UG::KEY_S)) {
		player.MoveY(-1);
		for (std::vector<GameObject*>::size_type i = 0; i != ActiveLevelObjects.size(); i++) {
			if (player.BoxCollider.IsCollidingWithC(ActiveLevelObjects[i]->cCollider)) {
				player.MoveY(1);
			}
		}
		if (player.BoxCollider.GetBottomY() < gc_iBottomOfScreenY) {
			player.MoveY(1);
		}
	}
	if (UG::IsKeyDown(UG::KEY_A)) {
		player.MoveX(-1);
		for (std::vector<GameObject*>::size_type i = 0; i != ActiveLevelObjects.size(); i++) {
			if (player.BoxCollider.IsCollidingWithC(ActiveLevelObjects[i]->cCollider)) {
				player.MoveX(1);
			}
		}
		if (player.BoxCollider.GetLeftX() < gc_iLeftOfScreenX) {
			player.MoveX(1);
		}
	}
	else if (UG::IsKeyDown(UG::KEY_D)) {
		player.MoveX(1);
		for (std::vector<GameObject*>::size_type i = 0; i != ActiveLevelObjects.size(); i++) {
			if (player.BoxCollider.IsCollidingWithC(ActiveLevelObjects[i]->cCollider)) {
				player.MoveX(-1);
			}
		}
		if (player.BoxCollider.GetRightX() > gc_iRightOfScreenX) {
			player.MoveX(-1);
		}
	}
	if (UG::IsMouseButtonDown(0)) { //left mouse click
		player.wCurrentWeapon.Shoot(a_g_fDeltaSum);
	}
	if (UG::IsKeyDown(UG::KEY_ESCAPE))
		UG::Close();
}

void GameManager::Update(float a_g_fDeltaSum)
{
	mouse.Update();
	for (std::vector<PlayerBullet*>::size_type i = 0; i != ActiveBullets.size(); i++) {
		ActiveBullets[i]->Update();
	}
	if (v_AliveEnemies.size() < c_iMaxNumberOfEnemies) {
		if (rand() % 100 == 50) {
			v_AliveEnemies.push_back(new Enemy("./images/Zombie.png", 10));
		}
	}
	for (std::vector<Enemy*>::size_type i = 0; i != v_AliveEnemies.size(); i++) {
		v_AliveEnemies[i]->UpdateRotation();

		if (v_AliveEnemies[i]->m_dnTargetNode == DjikstraNode(0, 0)) {//Hasn't started pathfinding
			for
		}
	}
	DetectBulletCollision();
}

void GameManager::DrawCurrentScreen()
{
	UG::ClearScreen();
	player.DrawSprite();

	for (std::vector<PlayerBullet*>::size_type i = 0; i != ActiveBullets.size(); i++) {
		ActiveBullets[i]->Draw();
	}
	for (std::vector<GameObject*>::size_type i = 0; i != ActiveLevelObjects.size(); i++) {
		ActiveLevelObjects[i]->Draw();
	}
	for (std::vector<Enemy*>::size_type i = 0; i != v_AliveEnemies.size(); i++) {
		v_AliveEnemies[i]->DrawSprite();
	}
	std::string ScoreText = "Score: " + std::to_string(PlayerScore);
	UG::DrawString(ScoreText.c_str(), 64,730,1, UG::SColour(0x00, 0x00, 0x00, 0xFF));
}

void GameManager::CreateLevel() {
	GameObject* Crate1 = new GameObject("./images/Crate.png", 320, 384, 64, 64);
	ActiveLevelObjects.push_back(Crate1);
	GameObject* Wall1 = new GameObject("./images/Wall.png", 48 , 64, 32, 64);
	ActiveLevelObjects.push_back(Wall1);
	GameObject* Tank = new GameObject("./images/Tank.png", 704, 480, 256, 128);
	ActiveLevelObjects.push_back(Tank);
	CreateDjikstraMap();
}

void GameManager::ConnectDjikstraNodes() {
	int iIndex = 0;
	for (int y = 0; y <= 24; y++) {
		for (int x = 0; x <= 32; x++) {
			if (!v_DjikstrasMapOfLevel[iIndex].GetX() >= 1024) {
				v_DjikstrasMapOfLevel[iIndex].vConnectedNodes.push_back(&v_DjikstrasMapOfLevel[iIndex + 1]);
			}
			else if (v_DjikstrasMapOfLevel[iIndex].GetX() != 0) {
				v_DjikstrasMapOfLevel[iIndex].vConnectedNodes.push_back(&v_DjikstrasMapOfLevel[iIndex - 1]);
			}
			if (!v_DjikstrasMapOfLevel[iIndex].GetY() >= 748) {
				v_DjikstrasMapOfLevel[iIndex].vConnectedNodes.push_back(&v_DjikstrasMapOfLevel[iIndex + 23]);
			}
			else if (v_DjikstrasMapOfLevel[iIndex].GetY() != 0) {
				v_DjikstrasMapOfLevel[iIndex].vConnectedNodes.push_back(&v_DjikstrasMapOfLevel[iIndex - 23]);
			}
			iIndex++;
		}
	}
}

void GameManager::CreateDjikstraMap() {
	for (int y = 0; y <= 24; y++) {
		for (int x = 0; x <= 32; x++) {
			for (int a = 0; a < ActiveLevelObjects.size(); a++) {
				if (ActiveLevelObjects[a]->vPosition.GetX() != x && ActiveLevelObjects[a]->vPosition.GetY() != y) {
					v_DjikstrasMapOfLevel.push_back(DjikstraNode(x * 32, y * 32));
				}
			}
		}
	}
	ConnectDjikstraNodes();
}

void GameManager::CreateWeapons() {
	AvailableWeapons.insert({ "BasicRifle", new Weapon() });
}

void GameManager::SpawnEnemy() {

}
void GameManager::DetectBulletCollision() {
	//the following deletes bullets which leave the field of play. stopping there being an infinitely growing list of bullets to check.
	for (std::vector<PlayerBullet*>::size_type i = 0; i < ActiveBullets.size(); i++) {
		if (ActiveBullets[i]->vPosition.GetY() < gc_iBottomOfScreenY) {
			//if (ActiveBullets[i] != nullptr) {
				//delete ActiveBullets[i]; //Deletes the class but does not delete memory so cannot be used for deleting an index in the array as it will just become junk data 
			//}
			ShiftIndexForBulletArray(i);
		}
	}
	for (std::vector<PlayerBullet*>::size_type i = 0; i < ActiveBullets.size(); i++) {
		if (ActiveBullets[i]->vPosition.GetY() > gc_iTopOfScreenY) {
			ShiftIndexForBulletArray(i);
		}
	}
	for (std::vector<PlayerBullet*>::size_type i = 0; i < ActiveBullets.size(); i++) {
		if (ActiveBullets[i]->vPosition.GetX() < gc_iLeftOfScreenX) {
			ShiftIndexForBulletArray(i);
		}
	}
	for (std::vector<PlayerBullet*>::size_type i = 0; i < ActiveBullets.size(); i++) {
		if (ActiveBullets[i]->vPosition.GetX() > gc_iRightOfScreenX) {
			ShiftIndexForBulletArray(i);
		}
	}

	//The following detects bullest which come into contact with enemies.
	if (ActiveBullets.size() > 0) {
		for (std::vector<PlayerBullet*>::size_type j = 0; j != ActiveBullets.size(); j++) {
			for (std::vector<Enemy*>::size_type i = 0; i != v_AliveEnemies.size(); i++) {
				if (v_AliveEnemies[i]->m_cBoxCollider.IsCollidingWithP(ActiveBullets[j]->vPosition)) {
					ShiftIndexForBulletArray(j);
					v_AliveEnemies[i]->Hit();
					if (v_AliveEnemies[i]->GetHP() <= 0) {//If Enemy has less than 0 health after its hit it must be dead
						ShiftIndexForEnemyArray(i);
						PlayerScore += 10;
					}
					return;
				}
			}
		}
	}
}

void GameManager::ShiftIndexForBulletArray(int iIndexToShift){
	for (std::vector<PlayerBullet*>::size_type i = iIndexToShift; i != ActiveBullets.size() - 1; i++) {
		ActiveBullets[i] = ActiveBullets[i + 1];
	}
	ActiveBullets.pop_back();
}
void GameManager::ShiftIndexForEnemyArray(int iIndexToShift) {
	for (std::vector<Enemy*>::size_type i = iIndexToShift; i != v_AliveEnemies.size() - 1; i++) {
		v_AliveEnemies[i] = v_AliveEnemies[i + 1];
	}
	v_AliveEnemies.pop_back();
}