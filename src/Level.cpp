#include "Level.h"

#include <sstream>
#include <fstream>
#include <string>

void Level::ReadFile(const std::string& filepath)
{
	std::ifstream stream(filepath);
	std::string line;
	std::stringstream ss;

	int lineCount = 0;
	while (getline(stream, line))
	{
		Width = line.size();
		ss << line;
		++lineCount;
	}

	Height = lineCount;

	map = ss.str();
}

void Level::Draw(olc::PixelGameEngine* pge)
{
	for (int x = 0; x < Width; x++)
		for (int y = 0; y < Height; y++)
		{
			if (map[y * Width + x] == '#')
				pge->FillRectDecal(olc::vf2d(x, y) * 16.0f, { 16.0f, 16.0f }, olc::GREEN);
		}

}

char Level::GetTile(const olc::vi2d& id)
{
	if (id.x >= 0 && id.x < Width && id.y >= 0 && id.y < Height)
		return map[id.y * Width + id.x];
	else
		return ' ';
}

void Level::SetTile(const olc::vi2d& id, char c)
{
	if (id.x >= 0 && id.x < Width && id.y >= 0 && id.y < Height)
		map[id.y * Width + id.x] = c;
}
