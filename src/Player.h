#pragma once

#include "olcPixelGameEngine.h"

class Player
{
public:
	olc::vf2d position;
	olc::vf2d direction;
	olc::vi2d newDir;
	float speed;
public:
	Player();
	void Init();
	void Update(float fElapsedTime);
	void Draw();
};