//============================================================================
// Name        : List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : List.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "List.h"
#include <cstddef>
#include <iostream>
using namespace std;

List::List(): first(NULL), last(NULL), cursor(NULL), size(0) {}

List::~List()
{
    cursor = first;
    Nodeptr temp;
    while(cursor != NULL) {
        temp = cursor->next;
        delete cursor;
        cursor = temp;
    }
}

void List::insertFirst(int data)
{
    if (first == NULL) {
        first = new Node(data);
        last = first;
    }
    else {
        Nodeptr N = new Node(data);
        N->next = first;
        first = N;
    }
    size++;
}

void List::printList()
{
    Nodeptr temp = first; //create a temporary iterator
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
