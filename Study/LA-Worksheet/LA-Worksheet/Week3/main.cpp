//
//  main.cpp
//  LA-Worksheet/Week3
//
//  Created by Jene Hojin Choi on 2021/07/12.
//

#include <iostream>
#include "Problem1.hpp"

int main() {
    LinkedList ls;
    ls.insertToFront(1);
    ls.insertToFront(0);
    ls.printList();
    ls.insertNItems(2, 2, "rear");
    ls.printList();
    return 0;
}


//void updateInventory( double limit ) {
//    int i;
//    for(i=0; i<MAXNUMCARS; i++) {
//        Car car=*(m_cars[i]);
//        double amountEarnedOnCar = car.getAmountEarnedOnCar();
//        if ( amountEarnedOnCar < limit ) {
//            swapCars( i, -1);
//        }
//    }
//}
//
//Dealership (const Dealership &rhs) {
//    m_cars = new Car[MAXNUMCARS];
//    m_numCars = rhs.m_numCars;
//}

