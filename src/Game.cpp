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
    if (GetKey(olc::LEFT).bPressed)    player.dir = { -1.0f, 0.0f };
    if (GetKey(olc::RIGHT).bPressed)   player.dir = { 1.0f, 0.0f };
    if (GetKey(olc::UP).bPressed)      player.dir = { 0.0f, -1.0f };
    if (GetKey(olc::DOWN).bPressed)    player.dir = { 0.0f,  1.0f };

	player.pos += player.dir * player.speed * fElapsedTime;
	olc::vf2d newPos = player.pos;
	
	if (level.GetTile(olc::vi2d(player.pos.x, player.pos.y)) == '#' || level.GetTile(olc::vi2d(player.pos.x, player.pos.y + 0.9f)) == '#' ||
		level.GetTile(olc::vi2d(player.pos.x + 1, player.pos.y)) == '#' || level.GetTile(olc::vi2d(player.pos.x + 1.0f, player.pos.y + 0.9f)) == '#')
	{
		player.dir.x *= -1;
	}	
	
	if (level.GetTile(olc::vi2d(player.pos.x, player.pos.y)) == '#' || level.GetTile(olc::vi2d(player.pos.x + 0.9f, player.pos.y)) == '#' ||
		level.GetTile(olc::vi2d(player.pos.x, newPos.y + 1)) == '#' || level.GetTile(olc::vi2d(player.pos.x + 0.9f, newPos.y + 1.0f)) == '#')
	{			
		player.dir.y *= -1;
	}
	
	
    player.pos = newPos;

    Clear(olc::BLACK);

    level.Draw(this);
    FillRectDecal(player.pos * 16.0f, { 16.0f, 16.0f }, olc::WHITE);

    return !GetKey(olc::ESCAPE).bPressed;
}
