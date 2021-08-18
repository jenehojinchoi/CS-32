//
//  main.cpp
//  MT1
//
//  Created by Jene Hojin Choi on 2021/07/13.
//

#include <iostream>

#include<iostream>
using namespace std;
 
class Circle
{
    // private data member
    private:
    double radius =3;
      
    // public member function
    public:
        double getRadius()
        {   // member function can access private
            // data member radius
            cout << radius << "\n";
            return radius;
        }
     
};
 
// main function
int main()
{
    // creating object of the class
    Circle obj;
    // trying to access private data member
    // directly outside the class
    obj.getRadius();
     
     
    return 0;
}


void List::insertNItems(int n, ItemType item, std::string str) {
    if (str == "front") {
        curr 
    }
}

