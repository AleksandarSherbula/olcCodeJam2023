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

	if ((direction.x == -1 && newDir.x == 1) ||
		(direction.x == 1 && newDir.x == -1))
		direction.x *= -1;

	if ((direction.y == -1 && newDir.y == 1) ||
		(direction.y == 1 && newDir.y == -1))
		direction.y *= -1;

	//Did the Player change the direction and the axis
	for (olc::vf2d crossPos : game->level->interesctPos)
	{
		//From Left or Right to Up or Down and the other way around
		if (game->cmp(newPos, crossPos))
		{
			if (newDir.y == -1 && game->level->GetTile(olc::vi2d(crossPos.x, crossPos.y - 1)) != '#' ||
				newDir.y == 1 && game->level->GetTile(olc::vi2d(crossPos.x, crossPos.y + 1)) != '#')
				newPos.x = (int)crossPos.x;

			if (newDir.x == -1 && game->level->GetTile(olc::vi2d(crossPos.x - 1, crossPos.y)) != '#' ||
				newDir.x == 1 && game->level->GetTile(olc::vi2d(crossPos.x + 1, crossPos.y)) != '#')
				newPos.y = (int)crossPos.y;

			direction = newDir;
		}
	}

	position = newPos;
}

void Player::Draw()
{
	game->FillRectDecal(position * 16.0f, { 16.0f, 16.0f }, olc::WHITE);
}
