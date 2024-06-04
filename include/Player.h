#include <allegro.h>
#include "Player.h"

class Player
{
public:
    Player();
    ~Player();

    void Init();
    void Update();
    void Draw(BITMAP *Buffer);
    void Controls();
    void SetPosition();

    void Controls();

    int x;
    int y;
    int x2;
    int y2;
    int width;
    int height;
    int hDir;
    int vDir;
    int velx;
    int vely;
    int gravity;
    int speed;
    int jumpspeed;
    bool Jump, Platform;
};
