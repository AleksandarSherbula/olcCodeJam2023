#pragma once
#include "olcPixelGameEngine.h"

class Level
{
private:
	int Width;
	int Height;
	std::string map;
public:
	void ReadFile(const std::string& filepath);
	void Draw(olc::PixelGameEngine* pge);

	char GetTile(const olc::vi2d& id);
	void SetTile(const olc::vi2d& id, char c);
};