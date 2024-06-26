#include <allegro.h>
#include "Global.h"
#include <fstream>
using namespace std;

class Map
{
public:
    Map();
    ~Map();

    void Init();
    void Update();
    void Draw(BITMAP *Buffer);
    void MapFile();

    void LoadMap(const char*filename);
private:
    int loadCounterX, loadCounterY;
    int mapSizeX, mapSizeY;
};
