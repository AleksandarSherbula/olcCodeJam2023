#include "Game.h"

Game::Game()
{
    sAppName = "OLC Code Jam 2023";
}

bool Game::OnUserCreate()
{
    player = std::make_unique<Player>();
    level = std::make_unique<Level>();

    level->Load("assets/levels/test2.lvl");

    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    player->Update(fElapsedTime);

    Clear(olc::BLACK);

    level->Draw(this);
    player->Draw();

    return !GetKey(olc::ESCAPE).bPressed;
}
