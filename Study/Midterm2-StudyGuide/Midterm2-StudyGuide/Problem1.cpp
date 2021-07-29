//
//  Problem1.cpp
//  Midterm2-StudyGuide
//
//  Created by Jene Hojin Choi on 2021/07/29.
//

#include <iostream>
using namespace std;

class Person{
public:
    virtual void eat() {cout << "Yummy" << endl;}
    virtual void speak() {cout << "Hello" << endl;}
    virtual void sleep() {cout << "ZZZZ" << endl;}
    virtual ~Person() {}
};

class Student:public Person {
public:
    void speak() {cout << "I love school" << endl;}
    void study() {cout << "Studying for Midterm test" << endl;}
    void getReadyForTest () {
        study();
        sleep();
    }
    virtual ~Student() {}
};

class UCLAStudent:public Student {
public:
    void speak() {cout << "Go Bruins!" << endl;}
    void sleep()
    {cout << "ZZZ... CS32 ...ZZZZ" << endl;}
    void getReadyForCS32Test() {
        study();
        eat();
        sleep();
    }
    virtual ~UCLAStudent() {}
};

int problem1( )
{
    Person* array[3];
    array[0] = new Person();
    array[1] = new Student();
    array[2] = new UCLAStudent();
    
    for (int i=0; i < 3; i++) {
        array[i]->eat();
        array[i]->speak();
        array[i]->sleep();
    }
    
    Student * sp = new Student();
    UCLAStudent *uclap = new UCLAStudent();
    sp->getReadyForTest();
    uclap->getReadyForCS32Test();
    
    return 0;
}
