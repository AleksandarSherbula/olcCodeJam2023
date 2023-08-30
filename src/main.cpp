#include "Game.h"

int main()
{	
	if (game->Construct(640, 320, 2, 2, false, true))
		game->Start();
	delete game;
	return 0;
}