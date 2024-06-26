#include <iostream>
#include <allegro.h>
#include "Global.h"

#include "Player.h"
#include "Camera.h"
#include "Map.h"
#include "Collision.h"

volatile long counter = 0;
void Increment()
{
    counter ++;
}

int main()
{
    allegro_init();
    install_keyboard();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, "A");
    set_color_depth(32);
    set_gfx_mode (GFX_AUTODETECT_WINDOWED, ScreenWidth, ScreenHeight, 0, 0);

    LOCK_VARIABLE (counter);
    LOCK_FUNCTION (Increment);
    install_int_ex (Increment, BPS_TO_TIMER(50));

    BITMAP *Buffer = create_bitmap (6000, 600);
    bool done = false;

    Player player;
    Camera camera;
    Map map;
    Collision collision;

    player.Init();
    camera.Init();
    map.Init();
    collision.Init();

    while (!done)
    {
        while (counter > 0)
        {
            // Input
            if (key[KEY_ESC])
                done = true;
            // Update
            map.Update();
            player.Update();
            collision.Update(Buffer, player);
            camera.Update(player.x, player.y);
            counter --;
        }
        // Draw
        map.Update();
        map.Draw(Buffer);
        player.Draw(Buffer);
        camera.Draw(Buffer);
        clear_bitmap(Buffer);

    return 0;
}
END_OF_MAIN()
