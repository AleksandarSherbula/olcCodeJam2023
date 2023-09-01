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

bool Game::cmp(olc::vf2d a, olc::vf2d b, float epsilon)
{
    return (a.x >= b.x && a.x < b.x + epsilon &&
        a.y >= b.y && a.y < b.y + epsilon);
}
