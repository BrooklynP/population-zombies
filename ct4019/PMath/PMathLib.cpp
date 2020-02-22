#include "stdafx.h"
#include <stdexcept>
#include "PMathLib.h"
#include "Vector2Lib.h"
#include<iomanip>
#include<cmath>
#include <iostream>


static const double pi = 3.14159265359;

PedleyMath::PedleyMath()
{
};


PedleyMath::~PedleyMath()
{
};


float PedleyMath::DegreeToRadians(float a_fDegrees) {
#pragma warning(suppress: 4244)//returned answer does not to be as accurate as a double but pi should be
	float Radians = a_fDegrees * (pi / 180);
	return Radians;
};
float PedleyMath::RadiansToDegrees(float a_fRadians) {
#pragma warning(suppress: 4244)//returned answer does not to be as accurate as a double but pi should be
	float Degrees = a_fRadians * (180 / pi);
	return Degrees;
};
float PedleyMath::Sin(float a_fAngle) {
	a_fAngle = DegreeToRadians(a_fAngle);
	float answer = a_fAngle
		- ((a_fAngle * a_fAngle * a_fAngle) / (1 * 2 * 3))
		+ ((a_fAngle * a_fAngle * a_fAngle *a_fAngle * a_fAngle) / (1 * 2 * 3 * 4 * 5))
		- ((a_fAngle * a_fAngle * a_fAngle * a_fAngle * a_fAngle * a_fAngle * a_fAngle) / (1 * 2 * 3 * 4 * 5 * 6 * 7));
	return answer;
};
float PedleyMath::Cos(float a_fAngle) {
	a_fAngle = DegreeToRadians(a_fAngle);
	float answer = 1
		- ((a_fAngle * a_fAngle) / (1 * 2))
		+ ((a_fAngle * a_fAngle * a_fAngle *a_fAngle) / (1 * 2 * 3 * 4))
		- ((a_fAngle * a_fAngle * a_fAngle * a_fAngle * a_fAngle * a_fAngle) / (1 * 2 * 3 * 4 * 5 * 6));
	return answer;
};
float PedleyMath::DotProduct(Vector2 a_vVector1, Vector2 a_vVector2) {
	float fX = a_vVector1.GetX() * a_vVector2.GetX();
	float fy = a_vVector1.GetY() * a_vVector2.GetY();
	float DotProduct = fX + fy;
	return DotProduct;
};
float PedleyMath::FindAngle(Vector2 a_vVector1, Vector2 a_vVector2) {
	float fDotProduct = DotProduct(a_vVector1, a_vVector2);
	float fMagnitude1 = a_vVector1.GetMagnitude();
	float fMagnitude2 = a_vVector2.GetMagnitude();
	float fCosOfAngle = fDotProduct / (fMagnitude1 * fMagnitude2);
	float Angle = acos(fCosOfAngle);
	Angle = RadiansToDegrees(Angle);
	return Angle;
};

float PedleyMath::FindOppWithHyp(float a_vHyp, float a_fAngle) {
	float AngleInRadians = DegreeToRadians(a_fAngle);
	float fOpp = a_vHyp * sin(AngleInRadians);

	return fOpp;
};
float PedleyMath::FindAdjWithHyp(float a_vHyp, float a_fAngle) {
	float AngleInRadians = DegreeToRadians(a_fAngle);
	float fAdj = a_vHyp * cos(AngleInRadians);
	return fAdj;
};
float PedleyMath::FindGradient(Vector2 a_vVector1, Vector2 a_vVector2) {
	float DeltaY = a_vVector1.GetY() - a_vVector2.GetY();
	float DeltaX = a_vVector1.GetX() - a_vVector2.GetX();
	float Gradient = DeltaY / DeltaX;
	return Gradient;
};
int PedleyMath::RandomNumInRange(int a_iMin, int a_iMax) {
	return rand() % (a_iMax - a_iMin) + a_iMin;
}
int PedleyMath::RoundNumberUpToMultiple(int a_iNumberToRound, int a_iMultiple) {
	if (a_iMultiple == 0){	//rounding up the the nearest 0 is just itself.
		return a_iNumberToRound;
	}

	int iRemainder = a_iNumberToRound % a_iMultiple;	//if already a multiple, no need to round.
	if (iRemainder == 0) {
		return a_iNumberToRound;
	}

	int iAnswer = a_iNumberToRound + a_iMultiple - iRemainder;
	return iAnswer;
}