#include "Actor.h"
#include "StudentWorld.h"
#include "GraphObject.h"
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Actor::Actor(StudentWorld* world, int imageID, int startX, int startY, Direction dir, double size, unsigned int depth): GraphObject(imageID, startX, startY, dir, size, depth), m_world(world)
{
    setVisible(true);
}

StudentWorld* Actor::getWorld()
{
    return m_world;
}

void Actor::moveTo(int x, int y)
{
    if (x < 0) x = 0;
    if (x > 60) x = 60;
    if (y < 0) y = 0;
    if (y > 60)  y = 60;
    GraphObject::moveTo(x, y);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TunnelMan
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TunnelMan::TunnelMan() : Actor(TID_PLAYER, 30, 60, right, 1.0, 0)
{
    setVisible(true);
}

int TunnelMan::getHitPoint()
{
    return m_hitPoint;
}

int TunnelMan::getWater()
{
    return m_water;
}

int TunnelMan::getSonar()
{
    return m_sonar;
}

int TunnelMan::getGold()
{
    return m_gold;
}


//void TunnelMan::decreaseHitPoint()
//{
//    m_hitPoint--;
//}


void TunnelMan::doSomething()
{
    if (getHitPoint() <= 0)
        // dead
        return;
    
    int input;
    
    // if where player stands is Earth
    // dig
    
    if (getWorld()->getKey(input)) {
        switch(input) {
            case KEY_PRESS_ESCAPE:
                // dead
                break;
            case KEY_PRESS_LEFT: moveInDirection(left); break;
            case KEY_PRESS_RIGHT: moveInDirection(right); break;
            case KEY_PRESS_UP:   moveInDirection(up); break;
            case KEY_PRESS_DOWN: moveInDirection(down); break;
            case KEY_PRESS_SPACE:
                // shoot()
                break;
            case 'z':
            case 'Z':
                if (m_sonar > 0) {
                    m_sonar--;
                    getWorld()->activateSonar(getX(), getY(), 12);
                    getWorld()->playSound(SOUND_SONAR);
                }
                break;
            case KEY_PRESS_TAB:
                if (m_gold > 0) {
                    m_gold--;
                    getWorld()->dropGold(new Gold(getWorld(), getX(), getY(), true, true));
                }
                break;
        }
    }
}

void TunnelMan::isAnnoyed()
{
    m_hitPoint--;
    if (m_hitPoint <= 0)
    {
        // dead
        getWorld()->playSound(SOUND_PLAYER_GIVE_UP);
    }
}

//void TunnelMan::shoot()
//{
//  getDirection
//  if Earth and Boulder do not get in the way
//     add Squirt to new Squirt vector
//}

// direction comes from GraphObject
void TunnelMan::moveInDirection(Direction direction)
{
    switch(direction) {
        case left:
            if (getDirection() == left) {
                if (! getWorld()->isThereBoulder(getX()-1, getY())) {
                    moveTo(getX()-1, getY());
                }
            }
            // set new Direction function
            break;
        case right:
            if (getDirection() == right) {
                if (! getWorld()->isThereBoulder(getX()+1, getY())) {
                    moveTo(getX()+1, getY());
                }
            }
            // set new Direction function
            break;
        case up:
            if (getDirection() == up) {
                if (! getWorld()->isThereBoulder(getX(), getY()+1)) {
                    moveTo(getX(), getY()+1);
                }
            }
            // set new Direction function
            break;
        case down:
            if (getDirection() == down) {
                if (! getWorld()->isThereBoulder(getX(), getY()-1)) {
                    moveTo(getX(), getY()-1);
                }
            }
            // set new Direction function
            break;
        case none: return;
    }
    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Earth
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Earth::Earth(StudentWorld* world, int startX, int startY) : Actor(world, TID_EARTH, startX, startY, right, 0.25, 3) {}

void Earth::doSomething() {}  // dont do anything
