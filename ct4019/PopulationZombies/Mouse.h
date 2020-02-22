#include "Vector2Lib.h"
#pragma once
class Mouse
{
public:
	Mouse();
	~Mouse();
	Vector2 vPositon;
	void Update();
	float AngleFromPlayer;
	float YgradientComponent;
	float XgradientComponent;
};
extern Mouse mouse;
