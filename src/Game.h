#pragma once
#include "olcPixelGameEngine.h"
#include "Level.h"
#include "Player.h"

class Game : public olc::PixelGameEngine
{
public:
	Game();

	std::unique_ptr<Level> level;
	std::unique_ptr<Player> player;
public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
};

inline Game* game = new Game();