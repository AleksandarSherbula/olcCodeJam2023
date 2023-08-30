#include "Game.h"

Game::Game()
{
    sAppName = "OLC Code Jam 2023";
}

bool Game::OnUserCreate()
{
    test.Load("img/Test.png");
    level.Load("assets/levels/one.lvl");

    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    player.Update(fElapsedTime);

    Clear(olc::BLACK);

    level.Draw(this);

    player.Draw();

    return !GetKey(olc::ESCAPE).bPressed;
}
