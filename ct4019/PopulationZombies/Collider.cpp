#include "Collider.h"
#include "Vector2Lib.h"



Collider::Collider()
{
	TopY = 0;
	BottomY = 0;
	LeftX = 0;
	RightX = 0;
}
Collider::Collider(float a_fTopY, float a_fBottomY, float a_LeftX, float a_RightX) {
	TopY = a_fTopY;
	BottomY = a_fBottomY;
	LeftX = a_LeftX;
	RightX = a_RightX;
}
Collider::Collider(Vector2 a_vCenter, float a_fWidth, float a_fHeight) {
	TopY = a_vCenter.GetY() + a_fHeight / 2;
	BottomY = a_vCenter.GetY() - a_fHeight / 2;
	LeftX = a_vCenter.GetX() - a_fWidth / 2;
	RightX = a_vCenter.GetX() + a_fWidth / 2;
}

Collider::~Collider()
{
}

bool Collider::IsCollidingWithC(Collider a_cCollider) {
	return (LeftX < a_cCollider.RightX &&
		RightX > a_cCollider.LeftX &&
		BottomY < a_cCollider.TopY &&
		TopY > a_cCollider.BottomY);
}
bool Collider::IsCollidingWithP(Vector2 a_vPosition) {
	return (LeftX < a_vPosition.GetX() &&
		RightX > a_vPosition.GetX() &&
		BottomY < a_vPosition.GetY() &&
		TopY > a_vPosition.GetY());
}

float Collider::GetLeftX() {
	return LeftX;
}
float Collider::GetRightX() {
	return RightX;
}
float Collider::GetTopY() {
	return TopY;
}
float Collider::GetBottomY() {
	return BottomY;
}
void Collider::MoveX(int a_iDisplacement) {
	LeftX += a_iDisplacement;
	RightX += a_iDisplacement;
}
void Collider::MoveY(int a_iDisplacement) {
	TopY += a_iDisplacement;
	BottomY += a_iDisplacement;
}
