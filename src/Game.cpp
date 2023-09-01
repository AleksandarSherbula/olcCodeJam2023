#include "Game.h"

Game::Game()
{
    sAppName = "OLC Code Jam 2023";
}

bool Game::OnUserCreate()
{
    chunkOfMemory = '1';

    player = std::make_unique<Player>();
    level = std::make_unique<Level>();

    level->Load("assets/levels/test.lvl");

    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{    
    if (chunkOfMemory != '9')
    {
        if (level->GetTile(player->position) == chunkOfMemory)
        {
            level->SetTile(player->position, 'x');
            player->Init();
            chunkOfMemory++;
        }

        player->Update(fElapsedTime);
    }

    Clear(olc::BLACK);

    level->Draw(this);

    if (chunkOfMemory != '9')
        player->Draw();
    else
        DrawStringDecal(olc::vf2d(224.0f, 160.0f), "WELL DONE!!!", olc::WHITE, { 2.0f, 2.0f });

    return !GetKey(olc::ESCAPE).bPressed;
}

bool Game::cmp(olc::vf2d a, olc::vf2d b, float epsilon)
{
    return (a.x >= b.x && a.x < b.x + epsilon &&
        a.y >= b.y && a.y < b.y + epsilon);
}
