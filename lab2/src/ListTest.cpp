//============================================================================
// Name        : ListTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * ListTest.cpp
 *
 *  Created on: Jan 15, 2017
 *      Author: bahman Sadeghi
 */




#include <iostream>
#include "List.h"

using namespace std;

int main() {

    //instantiate two lists for testing purposes
    List<int> L1;
    List<string> L2;

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
    L2.insertLast("hi");
    L2.printList();
    cout<<"Testing when list is not empty and has only one element so we remove first element of L2:\n";
    L2.removeFirst();
    cout <<"It should print nothing and remove 15 from the list L2 :\n ";
    L2.printList();
    cout<<"Testing when list is empty L2:\n";
    cout <<"It should print :removeFirst: List is empty. No data to remove.:\n ";
    L2.removeFirst();
    cout<<"Testing removeFirst when list L1 has more than one element:\n";
    cout <<"It will shows 10 9 8 7 6 5 4 3 2 1 0 12 and remove the 11 from the list :\n";
    L1.removeFirst();
    L1.printList();

    cout <<"It test a list more than one element for removeLast :\n ";
    cout<<"So remove the last Element of L1:\n";
    cout<<"This return 11 10 9 8 7 6 5 4 3 2 1 0 and remove L1 from the list:\n";
    L1.removeLast();
    L1.printList();
    cout <<"It test a list is empty :\n ";
    cout<<"So it should tell us list L2 is already empty:\n";
    L2.removeLast();

    cout<<"Add 125 as an element to the L2 so it would shows that list L2 has one element:\n";
    L2.insertFirst(125);
    L2.printList();
    cout<<"Now delete last element from the list only has one element and it shows that list will be empty:\n";
    L2.removeLast();
    L2.printList();
    cout<< "Testing access function Empty for two case:\n";
    cout<<"First list L1 is not empty should return 1 :\n";
    L1.isEmpty();
    cout<<"Second list L2 is empty should return 0 :\n";
    L2.isEmpty();
    cout<<"Return the size of list L1:\n";
    L1.getSize();
    cout<<"Return the size of list L2:\n";
    L2.getSize();

    cout<<"Return the first element of list L1:\n";
    L1.getFirst();
    cout<<"Return the last element of list L1:\n";
    L1.getLast();
    cout<<"Return the first element of list L2:\n";
    L2.getFirst();
    cout<<"Return the last element of list L2:\n";
    L2.getLast();
    return 0;
}
