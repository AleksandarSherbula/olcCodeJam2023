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

	char chunkOfMemory;
public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

	bool cmp(olc::vf2d a, olc::vf2d b, float epsilon = 0.1f);
};

inline Game* game = new Game();