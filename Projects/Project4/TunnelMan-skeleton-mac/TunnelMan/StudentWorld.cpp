#include "StudentWorld.h"
#include "GraphObject.h"
#include "Actor.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

StudentWorld::StudentWorld(string assetDir): GameWorld(assetDir) {}

StudentWorld::~StudentWorld()
{
    cleanUp();
}

void StudentWorld::cleanUp()
{
    for (int x = 0; x < 64; x++) {
        for (int y = 0; y < 60; y++) {
            delete m_earth[x][y];
        }
    }
    vector<Actor*>::iterator it;
    for (it = m_actors.begin(); it != m_actors.end(); it++) {
        delete *it;
    }
    m_actors.clear();
    delete m_tunnelMan;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////
// init
////////////////////////////////////////////////////////////////////////////////////////////////////////

int StudentWorld::init()
{
    //
    return GWSTATUS_CONTINUE_GAME;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Action functions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool StudentWorld::withinRadius(int x1, int y1, int x2, int y2, int radius)
{
    if ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= radius*radius)
        return true;
    else return false;
}

bool StudentWorld::isThereBoulder(int x, int y, int radius)
{
    vector<Actor*>::iterator it;
    for (it = m_actors.begin(); it != m_actors.end(); it++) {
        if ((*it)->getID() == TID_BOULDER && withinRadius(x, y, (*it)->getX(), (*it)->getY(), radius))
            return true;
    }
    return false;
}

// isThereEarth
// withinRadius....
// withinRange....

void StudentWorld::digEarth(int x, int y)
{
    for (int i = x; i < x+4; i++) {
        for (int j = y; j < y+4; j++) {
            if (m_earth[i][j] != nullptr) {
                delete m_earth[i][j];
                m_earth[i][j] = nullptr;
            }
        }
    }
    playSound(SOUND_DIG);
}

void StudentWorld::activateSonar(int x, int y, int radius)
{
    int a, b;
    vector<Actor*>::iterator it;
    for (it = m_actors.begin(); it != m_actors.end(); it++)
    {
        if ((*it)->getID() == TID_BARREL || (*it)->getID() == TID_GOLD)
        {
            a = (*it)->getX();
            b = (*it)->getY();
            if (withinRadius(x, y, a, b, radius))
                (*it)->setVisible(true);
        }
    }
}

void StudentWorld::dropGold(Gold* gold)
{
    m_droppedGold.push_back(gold);
}
