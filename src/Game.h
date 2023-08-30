#pragma once
#include "olcPixelGameEngine.h"
#include "Level.h"


struct Player
{
	olc::vf2d pos = { 32.0f, 16.0f };
	olc::vf2d dir = { 1.0f, 0.0f };
	float speed = 50.0f;
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