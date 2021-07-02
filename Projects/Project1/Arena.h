//
//  Arena.h
//  Project1
//
//  Created by Jene Hojin Choi on 2021/06/29.
//

#ifndef Arena_h
#define Arena_h

#include "Previous.h"
#include "globals.h"
#include <string>

class Player;
class Robot;

class Arena
{
  public:
        // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();

        // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     robotCount() const;
    int     nRobotsAt(int r, int c) const;
    void    display(std::string msg) const;
    Previous& thePrevious();

        // Mutators
    bool   addRobot(int r, int c);
    bool   addPlayer(int r, int c);
    void   damageRobotAt(int r, int c);
    bool   moveRobots();

  private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Robot*  m_robots[MAXROBOTS];
    int     m_nRobots;
    Previous m_previous; // does not have to be dynamically allocated

};

#endif /* Arena_h */
