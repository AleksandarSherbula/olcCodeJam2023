#include "Game.h"

int main()
{
	std::unique_ptr<Game> game = std::make_unique<Game>();
	if (game->Construct(640, 320, 2, 2, false, false))
		game->Start();
	return 0;
}