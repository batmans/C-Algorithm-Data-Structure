/*
 * List.h
 *
 *  Created on: Jan 15, 2017
 *      Author: bahman sadeghi
 */

#ifndef LIST_H_
#define LIST_H_

#include <cstddef> //for NULL
#include <stdio.h>

//typedef struct Node* Nodeptr;

template <class listdata> //list stores generic listdata, not any specific C++ type

class List
{
    private:
             struct Node
             {
            	listdata data;
                Node* next;

                Node(): next(NULL){}
                Node(listdata data): next(NULL), data(data){}

             };

             typedef Node* Nodeptr;
             Nodeptr first;
             Nodeptr last;
             Nodeptr cursor;
             int size;
    public:

        /**Constructors and Destructors*/

        List();
        //Default constructor; initializes and empty list
        //Postcondition:construct a new linked list object that is empty list.

        ~List();
        //Destructor. Frees memory allocated to the list
        //Postcondition: Free dynamically allocated memory


        /**Accessors*/


        listdata getFirst();
        //Returns the first element in the list
        //Precondition: The list should not be NULL


        listdata getLast();
        //Returns the last element in the list
        //Precondition:The list should not be NULL


        bool isEmpty();
        //Determines whether a list is empty.

        int getSize();
        //Returns the size of the list


        /**Manipulation Procedures*/

        void removeLast();
        //Removes the value of the last element in the list
        //Precondition:if last is not null.
        //Postcondition:last element is removed from list.

        void removeFirst();
        //Removes the value of the first element in the list
        //Precondition:if start is not null.
        //Postcondition: start element is removed from list.

        void insertLast(listdata data);
        //Inserts a new element at the end of the list
        //If the list is empty, the new element becomes both first and last
        //Postcondition:data is added to the end of list.


        void insertFirst(listdata data);
        //Inserts a new element at the start of the list
        //If the list is empty, the new element becomes both first and last
        //Postcondition: data is added to beginning of list.

        /**Additional List Operations*/

        void printList();
        //Prints to the console the value of each element in the list sequentially
        //and separated by a blank space
        //Prints nothing if the list is empty

        listdata getIterator();
        void advanceIterator();
        bool offEnd();



};

#endif /* LIST_H_ */

#include <cstddef>
#include <iostream>
#include<stdlib.h>

using namespace std;

template <class listdata>
List<listdata>::List(): first(NULL), last(NULL), cursor(NULL), size(0) {}

template <class listdata>
List<listdata>::~List()
{
    cursor = first;
    Nodeptr temp;
    while(cursor != NULL) {
        temp = cursor->next;
        delete cursor;
        cursor = temp;
    }
}

template <class listdata>
void List<listdata>::printList()
{
    Nodeptr temp = first; //create a temporary iterator
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <class listdata>
void List<listdata>::insertFirst(listdata data)
{
    if (first == NULL) {
        first = new Node(list.first->data);
        last = first;
    }
    else {
        Nodeptr N = new Node(data);
        N->next = first;
        first = N;
    }
    size++;
}

template <class listdata>
void List<listdata>::insertLast(listdata data)
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
template <class listdata>
void List<listdata>::removeFirst()
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


template <class listdata>
void List<listdata>::removeLast()
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

template <class listdata>
bool List<listdata>::isEmpty()
{
	return size==0;
}

template <class listdata>
int List<listdata>::getSize()
{
    return size;
}

template <class listdata>
listdata List<listdata>::getFirst()
{
    return first->data;

}

template <class listdata>
listdata List<listdata>::getLast()
{
    return last->data;

}

template <class listdata>
listdata List<listdata>::getIterator()
{
	return cursor->data;
}

template <class listdata>
void List<listdata>::advanceIterator()
{
	cursor = cursor->next;
}

template <class listdata>
bool List<listdata>::offEnd()
{
	return cursor==NULL;
}



