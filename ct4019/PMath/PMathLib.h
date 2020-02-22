#pragma once

#include "Vector2Lib.h"

	class PedleyMath {
		public:
			PedleyMath();
			~PedleyMath();
			static float DegreeToRadians(float a_fDegrees);
			static float RadiansToDegrees(float a_fRadians);
			static float Sin(float a_fAngle);
			static float Cos(float a_fAngle);
			static float FindAngle(Vector2 a_vVector1, Vector2 a_vVector2);
			static float FindOppWithHyp(float a_vHyp, float a_fAngle);
			static float FindAdjWithHyp(float a_vAdj, float a_fAngle);
			static float DotProduct(Vector2 a_vVector1, Vector2 a_vVector2);
			static float FindGradient(Vector2 a_vVector1, Vector2 a_vVector2);
			static int RandomNumInRange(int a_iMin, int a_iMax);
			static int RoundNumberUpToMultiple(int a_iNumberToRound, int a_iMultiple);
	};