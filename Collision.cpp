#include "Collision.h"

Collision::Collision()
{

}

Collision::~Collision()
{

}

void Collision::Init()
{
    loadCounterX = loadCounterY = 0;
    Collision::LoadCollisionMap("colmap1.txt");
}

void Collision::Update(BITMAP *Buffer, Player &player)
{
    Collision::PlatformCollision(Buffer, player);
}

void Collision::Draw(BITMAP *Buffer)
{

}

void Collision::LoadCollisionMap(const char *filename)
{
    ifstream openfile(filename);
    if(openfile.is_open())
    {
        openfile >> mapSizeX >> mapSizeY;
        while(!openfile.eof())
        {
            openfile >> ColMapFile[loadCounterX][loadCounterY];
            loadCounterX ++;
            if (loadCounterX >= mapSizeX)
            {
                loadCounterX = 0;
                loadCounterY ++;
            }
        }
        loadCounterX = loadCounterY = 0;
    }
    else
    {
        allegro_message("Nie mozna znalezc mapy kolizji");
    }
}

void Collision::PlatformCollision(BITMAP *Buffer, Player &player);
{
    for (int i = 0; i < mapSizeX; i++)
    {
        for (int j = 0; j < mapSizeY; j++)
        {
            if (ColMapFile[i][j] == 1)
            {
                if(player.x > i*BlockSize + BlockSize || y > j*BlockSize + BlockSize || player.x2 < i*BlockSize || y2 < j*BlockSize)
                {
                    // Brak kolizji
                    player.Platform = false;
                }
                else
                {
                    if(vDir == 2 && player.y - player.vely <= j*BlockSize)
                    {
                        player.y = j*BlockSize - 10;
                        player.y2 = y + 10;
                        player.Platform = true;
                        player.Jump = true;
                        player.vely = 0;
                    }
                    else if (player.vDir == 1)
                    {
                        y += speed*2;
                        y2 = y + 10;
                        vely = 0; Platform = false;
                        Jump = false;
                    }
                    if (player.hDir == 1 && Platform == false)
                    {
                        x -= speed;
                        x2 = x + 10;
                    }
                    else if (player.hDir == 2 && Platform == false)
                    {
                        x += speed;
                        x2 = x + 10;
                    }
                }
            }
        }
    }
}
