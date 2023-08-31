#include "Player.h"
#include "Game.h"

Player::Player()
{
	position = { 2.0f, 1.0f };
	direction = { 1.0f, 0.0f };
	speed = 3.0f;

	newDir = direction;
}

void Player::Update(float fElapsedTime)
{
	if (game->GetKey(olc::LEFT).bPressed)    newDir = { -1,  0 };
	if (game->GetKey(olc::RIGHT).bPressed)   newDir = {  1,  0 };
	if (game->GetKey(olc::UP).bPressed)      newDir = {  0, -1 };
	if (game->GetKey(olc::DOWN).bPressed)    newDir = {  0,  1 };
	
	olc::vf2d newPos = position + direction * speed * fElapsedTime;

	if (direction.x < 0.0f)
	{
		if (game->level->GetTile(olc::vi2d(newPos.x, position.y)) == '#' || game->level->GetTile(olc::vi2d(newPos.x, position.y + 0.9f)) == '#')
		{
			newPos.x = (int)newPos.x + 1;
			direction = { 0, 0 };
		}
	}
	else if (direction.x > 0.0f)
	{
		if (game->level->GetTile(olc::vi2d(newPos.x + 1, position.y)) == '#' || game->level->GetTile(olc::vi2d(newPos.x + 1, position.y + 0.9f)) == '#')
		{
			newPos.x = (int)newPos.x;
			direction = { 0, 0 };
		}
	}
	else if (direction.y < 0.0f)
	{
		if (game->level->GetTile(olc::vi2d(position.x, newPos.y)) == '#' || game->level->GetTile(olc::vi2d(position.x + 0.9f, newPos.y)) == '#')
		{
			newPos.y = (int)newPos.y + 1;
			direction = { 0, 0 };
		}
	}
	else if (direction.y > 0.0f)
	{
		if (game->level->GetTile(olc::vi2d(position.x, newPos.y + 1)) == '#' || game->level->GetTile(olc::vi2d(position.x + 0.9f, newPos.y + 1)) == '#')
		{
			newPos.y = (int)newPos.y;
			direction = { 0, 0 };
		}
	}

	position = newPos;

	if (newDir.x != direction.x || newDir.y != direction.y)
	{
		if (newDir.x < 0.0f)
		{
			if (game->level->GetTile(olc::vi2d(position.x, position.y)) == 'x' &&
				game->level->GetTile(olc::vi2d(position + newDir)) != '#')
				direction.x = newDir.x;
		}
		else if (direction.y < 0.0f)
		{
			if (game->level->GetTile(olc::vi2d(position.x, position.y + 1.0f)) == 'x' &&
				game->level->GetTile(olc::vi2d(position + newDir)) != '#')
				direction = newDir;
		}
		else
		{
			if (game->level->GetTile(olc::vi2d(position)) == 'x' && 
				game->level->GetTile(olc::vi2d(position + newDir)) != '#')
				direction = newDir;
		}
		
	}
}

void Player::Draw()
{
	game->FillRectDecal(position * 16.0f, { 16.0f, 16.0f }, olc::WHITE);
}
