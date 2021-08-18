//
//  virtualDestructor.cpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/03.
//

#include <iostream>

class TimeKeeper {
public:
   TimeKeeper() { std::cout << "TimeKeeper constructor" << std::endl; };
   virtual ~TimeKeeper() { std::cout << "TimeKeeper destructor" << std::endl; };
private:
};

class AtomicTimeKeeper : public TimeKeeper {
public:
   AtomicTimeKeeper() { std::cout << "AtomicTimeKeeper constructor" << std::endl; };
   ~AtomicTimeKeeper() { std::cout << "AtomicTimeKeeper destructor" << std::endl; };
private:
};

AtomicTimeKeeper* getTimeKeeper() {
   return new AtomicTimeKeeper();
}
//
//int main() {
//   TimeKeeper *t = getTimeKeeper();
//
//   delete(t);
//}
