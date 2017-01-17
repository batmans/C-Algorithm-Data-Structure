//============================================================================
// Name        : List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : List.cpp
// Author      :Bahman Sadeghi
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

void List::printList()
{
    Nodeptr temp = first; //create a temporary iterator
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

void List::insertLast(int data)
{
    if (first == NULL) {
        first = new Node(data);
        last = first;
    }
    else {
    	last->next = new Node(data);
    	last = last->next;
    }
    size++;
}

void List::removeFirst()
{
    if (size==0){
        cout << "removeFirst: List is empty. No data to remove." << endl;
    } else if (size == 1) {
        delete first;
        first = last = NULL;
        size = 0;
    } else {
        Nodeptr temp = first; //store pointer to first so we don't lose access to it
        first = first->next; //advance the pointer
        delete temp; //free the memory for the original first node
        size--;
    }
}

void List::removeLast()
{
    if (size == 0){
        cout << "removeLast: List is empty. No data to remove." << endl;
    } else if (size==1) {
    	delete first;
    	first=last=NULL;
    	size=0;
    } else {

        Nodeptr temp = first;

        while (temp->next != last) {

            temp = temp->next; //advance the pointer
        }
        delete last; //free the memory for the original last node

        last = temp;

        last->next = NULL; //so last->next is not pointing at freed memory

        size--;
    }
}

bool List::isEmpty()
{
	return size==0;
}

int List::getSize()
{
    return size;
}

int List::getFirst()
{
    return first->data;

}

int List::getLast()
{
    return last->data;

}

int List::getIterator()
{
	return cursor->data;
}

void List::advanceIterator()
{
	cursor = cursor->next;
}

bool List::offEnd()
{
	return cursor==NULL;
}
