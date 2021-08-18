//
//  Problem7.cpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/03.
//

#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A() : m_val(0) { // my_val 없애면 undefined behavior
    cout << "What a wonderful world! " << m_val << endl;
    }
    virtual ~A() { cout << "Guess this is goodbye " << endl; }
    virtual void saySomething() = 0;
    virtual int giveMeSomething() = 0;
        
private:
    int m_val;
};

class B : public A {
public:
    B() : m_str("me"), m_val(1) {
        cout << m_str << " has just been birthed." << endl;
    }
    
    B(string str, int val) : m_str(str), m_val(val) {
        cout << "More complex birth " << m_str << endl;
    }
    
    ~B() {
        cout << "Why do I have to leave this world!" << endl;
    }
    
    virtual void saySomething() {
        cout << "================================================\n";
        cout << "Coming in from " << m_str << " with "
        << giveMeSomething() << endl;
    }
    virtual int giveMeSomething() { return m_val*5; }
    
private:
    int m_val;
    string m_str;
};

class C {
public:
    C() : m_val(2) {
        m_b = new B("C", m_val);
        cout << "Hello World!!" << endl;
    }
    
    C(B b, int val) : m_val(val) {
        m_b = new B(b);
        cout << m_b->giveMeSomething() << endl;
    }
        
    ~C() {
        m_b->saySomething();
        delete m_b;
        cout << "Goodbye world!" << endl;
    }
    
private:
    B* m_b;
    int m_val;
};

//int main() {
//    B* b_arr = new B[5];
//    for(int i = 0; i < 5; i++) {
//        b_arr[i].saySomething();
//    }
//    // 여기까지는 value 지정이 안된 상태의 b가 있으므로
//    // using initializer m_str("me"), m_val(1)
//    
//    B b("B", 5);
//    A* a = &b;
//    cout << a->giveMeSomething() << endl;
//
//    C c;
//    C c2(b, b.giveMeSomething());
//    
//    cout << "========================deletion========================" << "\n";
//    delete [] b_arr;
//}
