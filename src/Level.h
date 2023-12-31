#pragma once
#include "olcPixelGameEngine.h"

#include <vector>

class Level
{
private:
	int Width;
	int Height;
	std::string map;
public:
	std::vector<olc::vf2d> interesctPos;
public:
	Level();
	void Load(const std::string& filepath);
	void Draw(olc::PixelGameEngine* pge);

	char GetTile(const olc::vi2d& id);
	void SetTile(const olc::vi2d& id, char c);
private:
	void ReadFile(const std::string& filepath);
};