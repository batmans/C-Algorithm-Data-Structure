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


class List
{
    private:
             struct Node
             {
                int data;
                Node* next;

                Node(int data): data(data), next(NULL){}
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


        int getFirst();
        //Returns the first element in the list
        //Precondition: The list should not be NULL


        int getLast();
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

        void insertLast(int data);
        //Inserts a new element at the end of the list
        //If the list is empty, the new element becomes both first and last
        //Postcondition:data is added to the end of list.


        void insertFirst(int data);
        //Inserts a new element at the start of the list
        //If the list is empty, the new element becomes both first and last
        //Postcondition: data is added to beginning of list.

        /**Additional List Operations*/

        void printList();
        //Prints to the console the value of each element in the list sequentially
        //and separated by a blank space
        //Prints nothing if the list is empty

        int getIterator();
        void advanceIterator();
        bool offEnd();



};

#endif /* LIST_H_ */
