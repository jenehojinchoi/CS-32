//
//  Magician.cpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/03.
//

//#include "Magician.hpp"
#include <iostream>

class Magician {
public:
     Magician() { /* Implementation not shown */ }
     void learn() { /* Implementation not shown */ }
 
     // make cast() a virtual function
    virtual void cast()=0;
};
 
class Hufflepuff : public Magician {
public:
    Hufflepuff() { /* Implementation not shown */ }
    void cast(){std::cout << "cast!!" << std::endl;}
};

void castASpell(Magician &m)
{
    m.cast();
}

//
//int main()
//{
////    Magician* sc[2];
////    sc[0] = new Hufflepuff();
////    sc[1] = new Magician();
////
////    for (int i = 0; i < 2; i++)
////    {
////        sc[i]->cast();
////        sc[i]->learn();
////    }
//
//    Hufflepuff h;
//    castASpell(h);
//    
////    Magician m;
////    castASpell(m);
//
//    return 0;
//}
