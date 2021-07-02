//
//  Game.h
//  Project1
//
//  Created by Jene Hojin Choi on 2021/06/29.
//

#ifndef Game_h
#define Game_h

class Arena;

class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nRobots);
    ~Game();

        // Mutators
    void play();

  private:
    Arena* m_arena;
};


#endif /* Game_h */
