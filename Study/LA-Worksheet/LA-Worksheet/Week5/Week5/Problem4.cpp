//
//  Problem4.cpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/03.
//

#include <iostream>
using namespace std;

class Pet {
public:
    Pet() { cout << "Pet Constructor" << endl; }
    virtual ~Pet() { cout << "Pet Destructor" << endl; }
};

// This is an unusual class that derives from Pet but also
// contains a Pet as a data member.
class Dog : public Pet {
public:
    Dog() { cout << "Dog constructor" << endl; }
    ~Dog() { cout << "Dog Destructor" << endl; }
private:
    Pet buddy;
};
    
//int main() {
//    Pet* milo = new Dog;
//    delete milo;
//}
