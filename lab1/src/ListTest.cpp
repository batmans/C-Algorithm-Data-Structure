/*
 * ListTest.cpp
 *
 *  Created on: Jan 15, 2017
 *      Author: bahman
 */




#include <iostream>
#include "List.h"

using namespace std;

int main() {

    //instantiate two lists for testing purposes
    List L1;
    List L2;

    //Testing insertFirst() and printList()
    cout << "Should print out an empty line: \n";
    L1.printList(); //Should not print any message to the screen, just an empty line


    L1.insertFirst(0);
    cout << "Should print out 0 and then move to a new line: \n";
    L1.printList();
    for (int i = 1; i <= 10; i++) { //inserting the the values 1-10 into L1
        L1.insertFirst(i);
    }

    cout << "Should print out 10 9 8 7 6 5 4 3 2 1 0 and then move to a new line: \n";
    L1.printList();
    // Add 11 to the end of the list
    L1.insertFirst(11);
    cout<< "Should print 11 10 9 8 7 6 5 4 3 2 1 0 as if add 11 to the beginning of the list:\n";
    L1.printList();
    cout<<"Testing when insertlast when list is not empty , add 12 to the end of L1:\n";
    L1.insertLast(12);
    cout <<"It should print: 11 10 9 8 7 6 5 4 3 2 1 0 12 :\n ";
    L1.printList();
    cout<<"Testing when insertlast when list is  empty , add 15 to the empty list L2:\n";
    cout <<"It should print: 15 :\n ";
    L2.insertLast(15);
    L2.printList();

    return 0;
}
