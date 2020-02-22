#include "stdafx.h"
#include <stdexcept>
#include "Vector2Lib.h"
#include <cmath>

bool Vector2::operator==(const Vector2& a_vParam) {
	if (this->m_fX == a_vParam.m_fX && this->m_fY == a_vParam.m_fY) {
		return true;
	}
	else {
		return false;
	}
}
Vector2& Vector2::operator=(const float a_afParam[2]) {
	this->m_fX = a_afParam[0];
	this->m_fY = a_afParam[1];
	return *this;
};
Vector2 Vector2::operator*(const Vector2& a_avParam) {
	Vector2 NewVector(0, 0);
	NewVector.m_fX = this->m_fX * a_avParam.m_fX;
	NewVector.m_fY = this->m_fY * a_avParam.m_fY;
	return NewVector;
};
Vector2 Vector2::operator*(const float a_afParam) const {
	Vector2 NewVector(0, 0);
	NewVector.m_fX = this->m_fX * a_afParam;
	NewVector.m_fY = this->m_fY * a_afParam;
	 return NewVector;
};
Vector2 Vector2::operator+(const Vector2& a_avParam) {
	Vector2 NewVector(0, 0);
	NewVector.m_fX = this->m_fX + a_avParam.m_fX;
	NewVector.m_fY = this->m_fY + a_avParam.m_fY;
	return NewVector;
};
Vector2 Vector2::operator-(const Vector2& a_avParam) {
	Vector2 NewVector(0, 0);
	NewVector.m_fX = this->m_fX - a_avParam.m_fX;
	NewVector.m_fY = this->m_fY - a_avParam.m_fY;
	return NewVector;
};
float Vector2::GetMagnitude()const {
	float Xsqr = m_fX * m_fX;
	float Ysqr = m_fY * m_fY;
	float SquaredDistance = Xsqr + Ysqr;
	float distance = sqrt(SquaredDistance);
	return distance;
};
void Vector2::NormaliseSelf() {
	float Magnitude = GetMagnitude();
	m_fY = m_fY / Magnitude;
	m_fX = m_fX / Magnitude;
	m_bIsNormalised = true;
};
Vector2 Vector2::Normalise() {
	float Magnitude = GetMagnitude();
	Vector2 NewVector;
	//y/magnitude
	NewVector.m_fY = m_fY / Magnitude;
	//x/magnitude
	NewVector.m_fX = m_fX / Magnitude;
	NewVector.m_bIsNormalised = true;
	return NewVector;
};

Vector2 Vector2::RandomVector() {
	int iNumOfGridPointsX = 1024 / 32;
	int iNumOfGridPointsY = 768 / 32;
	float fX;
	float fY;
	fX = (rand() % iNumOfGridPointsX) * 32;
	fY = (rand() % iNumOfGridPointsY) * 32;
	return Vector2(fX, fY);
};