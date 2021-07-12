//
//  main.cpp
//  PointerQuiz
//
//  Created by Jene Hojin Choi on 2021/07/11.
//

#include <iostream>
#include "Problem1a.hpp"
#include "Problem1b.hpp"
#include "Problem1c.hpp"
#include "Problem1d.hpp"
#include "Problem1e.hpp"
#include "Problem2.hpp"
#include "Problem3a.hpp"
#include "Problem3b.hpp"
#include "Problem4.hpp"
#include "Problem5.hpp"
using namespace std;

int main() {
    int a;
    cout << "Enter problem number: ";
    cin >> a;
    
    switch(a){
        case(1):
            char s1;
            cout << "Enter problem letter: ";
            cin >> s1;
            switch(s1){
                case 'a':
                    Problem1a();
                    break;
                case 'b':
                    Problem1b();
                    break;
                case 'c':
                    Problem1c();
                    break;
                case 'd':
                    Problem1d();
                    break;
                case 'e':
                    Problem1e();
                    break;
            }
            
        case(2):
            Problem2();
            break;
        
        case(3):
            char s3;
            cout << "Enter problem letter: ";
            cin >> s3;
            switch(s3){
                case 'a':
                    Problem3a();
                    break;
                case 'b':
                    Problem3b();
                    break;
            }
        
        case(4):
            Problem4();
            break;
        
        case(5):
            Problem5();
            break;
    }    
    return 0;
}
