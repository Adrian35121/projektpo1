#include "Player.h"


Player::Player()
{

}

Player::~Player()
{

}

void Player::Init()
{
    width = 10;
    height = 10;
    x = (ScreenWidth - width) / 2;
    y = (ScreenHeight - height) / 2;
    x2 = x + width;
    y2 = y + height;
    velx = vely = 0;
    speed = 2;
    jumpspeed = -15;
    gravity = 1;
    Jump = Platform = false;
    hDir = 0;
    vDir = 2;
}

void Player::Update()
{
    Player::Controls();
}

void Player::Draw(BITMAP *Buffer)
{
    rectfill (Buffer, x, y, x+10, y + 10, makecol (255, 0, 0));
}

void Player::Controls()
{
    if (key[KEY_RIGHT])
    {
        velx = speed;
        hDir = 1;
    }
    else if (key[KEY_LEFT])
    {
        velx = -speed;
        hDir = 2;
    }
        else
        {
            velx = 0;
            hDir = 0;
        }
        if (key[KEY_UP] && Jump == true)
        {
            vely = jumpspeed;
            Platform = false;
            Jump = false;
            vDir = 1;
        }
}

void Player::SetPosition()
{
    if (vely >= 0)
    {
        vDir = 2;
    }
    if (Platform == false)
    {
        vely += gravity;
    }
    else
    {
        vely = 0;
    }
    x += velx;
    y += vely;
    x2 = x+width;
    y2 = y+height;
}
