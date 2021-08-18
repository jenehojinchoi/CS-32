//
//  Magician.hpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/03.
//

#ifndef Magician_hpp
#define Magician_hpp

#include <iostream>

class Magician {
public:
    Magician();
    void learn ();
     // make cast() a virtual function
    virtual void cast();
 
 
};
 
class Hufflepuff {
public:
    Hufflepuff();
    void cast(){/*Implementation not shown*/}
};

#endif /* Magician_hpp */
