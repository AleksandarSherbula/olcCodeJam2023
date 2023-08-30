#include "Game.h"

Game::Game()
{
    sAppName = "OLC Code Jam 2023";
}

bool Game::OnUserCreate()
{
    test.Load("img/Test.png");
    level.ReadFile("assets/levels/one.lvl");

    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    if (GetKey(olc::LEFT).bHeld)    player.dir = { -1.0f, 0.0f };
    if (GetKey(olc::RIGHT).bHeld)   player.dir = { 1.0f, 0.0f };
    if (GetKey(olc::UP).bHeld)      player.dir = { 0.0f, -1.0f };
    if (GetKey(olc::DOWN).bHeld)    player.dir = { 0.0f, -1.0f };

	if (player.dir.x < 0.0f)
	{
		if (level->WallCheck(olc::vi2d(newPos.x, position.y)) || level->WallCheck(olc::vi2d(newPos.x, position.y + 0.9f)))
		{
			newPos.x = (int)newPos.x + 1;
			player.dir.x = 0.0f;
		}
	}
	else
	{
		if (level->WallCheck(olc::vi2d(newPos.x + 1, position.y)) || level->WallCheck(olc::vi2d(newPos.x + 1.0f, position.y + 0.9f)))
		{
			newPos.x = (int)newPos.x;
			player.dir.x = 0.0f;
		}
	}

	if (player.dir.y < 0.0f)
	{
		if (level->WallCheck(olc::vi2d(position.x, newPos.y)) || level->WallCheck(olc::vi2d(position.x + 0.9f, newPos.y)))
		{
			newPos.y = (int)newPos.y + 1;
			player.dir.y = 0.0f;
		}
	}
	else
	{
		if (level->WallCheck(olc::vi2d(position.x, newPos.y + 1)) || level->WallCheck(olc::vi2d(position.x + 0.9f, newPos.y + 1.0f)))
		{
			newPos.y = (int)newPos.y;
			player.dir.y = 0.0f;
		}
	}


    player.pos += player.dir * player.speed * fElapsedTime;

    Clear(olc::BLACK);

    level.Draw(this);
    FillRectDecal(player.pos, { 16.0f, 16.0f }, olc::WHITE);

    return !GetKey(olc::ESCAPE).bPressed;
}
