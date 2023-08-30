#pragma once
#include "olcPixelGameEngine.h"
#include "Level.h"


struct Player
{
	olc::vf2d pos = { 2.0f, 1.0f };
	olc::vf2d dir = { 1.0f, 0.0f };
	float speed = 3.0f;
};

class Game : public olc::PixelGameEngine
{
public:
	Game();

	olc::Renderable test;
	Level level;
	Player player;
public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
};