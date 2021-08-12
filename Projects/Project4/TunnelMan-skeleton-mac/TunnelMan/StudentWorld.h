#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <string>
#include <vector>
#include "Actor.h"

class Actor;
class TunnelMan;
class Earth;
class Gold;
class Direction;

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir);
    ~StudentWorld();

    virtual int init();
    virtual int move();
    virtual void cleanUp();
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // action functions
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool withinRadius(int x1, int y1, int x2, int y2, int radius);
//    bool withinRangeWithDirection(int x, int y, int range, int imageID, Direction direction);
    bool isThereBoulder(int x, int y, int radius=3);
    bool isThereEarth(int x, int y, int radius);
    void digEarth(int x, int y);
    void activateSonar(int x, int y, int radius);
    void dropGold(Gold* gold);
    
private:
    std::vector<Actor*> m_actors;
    std::vector<Gold*> m_droppedGold;
    Earth* m_earth[64][64];
    TunnelMan* m_tunnelMan;
};

#endif // STUDENTWORLD_H_
