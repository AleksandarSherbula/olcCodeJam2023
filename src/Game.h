#pragma once
#include "olcPixelGameEngine.h"
#include "Level.h"
#include "Player.h"

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

inline Game* game = new Game();