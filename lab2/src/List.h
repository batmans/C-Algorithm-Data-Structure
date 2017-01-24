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
#include <assert.h>
#include <iostream>


//typedef struct Node* Nodeptr;


template <class listdata> //list stores generic listdata, not any specific C++ type
class List
{
    private:
             struct Node
             {
            	listdata data;
                Node* next;
                Node* previous;

                Node(): next(NULL),previous(NULL){}
                Node(listdata data):data(data),next(NULL),previous(NULL){}


             };

             typedef struct Node* Nodeptr;
             Nodeptr first;
             Nodeptr last;
             Nodeptr iterator;
             int size;
    public:

        /**Constructors and Destructors*/

        List();
        //Default constructor; initializes and empty list
        //Postcondition:construct a new linked list object that is empty list.

        ~List();
        //Destructor. Frees memory allocated to the list
        //Postcondition: Free dynamically allocated memory

        List(const List &list);
        //copy Constructor: Initializing list to have the same elements as another list
        //Postcondition: make new list that is a copy of given list.

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

        bool offEnd();
        //Determines if the iterator is off the end of the list (i.e. whether cursor is NULL)

        listdata getIterator();
        //Returns the element pointed to by the iterator, Data not pointer
        //Precondition: cursor is not null.

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

        void startIterator();
        //Moves the iterator to point to the first element in the list
        //If the list is empty, the iterator remains NULL
        //Postcondition: iterator points to first element of list if any
        //or remains NULL otherwise.

        void removeIterator();
        //Removes the element after the element pointed at by the iterator
        //Precondition: if iterator is not null.
        //Postcondition: element after iterator is removed from list.

        void advanceIterator();
        // moves the iterator up by one node
        //Precondition: if iterator is not null.

        void insertIterator(listdata data);
        //Inserts a new element into the list in the position after the iterator
        //Precondition: if iterator is not null.
        //Postcondition: data is inserted after iterator.

        bool operator==(const List& list);
        //Compares two lists for equality.



};



using namespace std;

template <class listdata>
List<listdata>::List(): first(NULL), last(NULL), iterator(NULL), size(0) {}

template <class listdata>
List<listdata>::~List()
{
    iterator = first;
    Nodeptr temp;
    while(iterator != NULL) {
        temp = iterator->next;
        delete iterator;
        iterator = temp;
    }
}

template <class listdata>
List<listdata>::List(const List &list): size(list.size)

{
    if(list.first == NULL) //If the original list is empty, make an empty list for this list
    {
        first = last = iterator = NULL;
    }
    else
    {
        first = new Node(list.first->data); //calling Node constructor
        Nodeptr temp = list.first; //set a temporary node pointer to point at the first of the original list
        iterator = first; //set iterator to point to first node of the new list

        while(temp->next != NULL)
        {

            temp = temp->next; //advance up to the next node in the original list
            iterator->next = new Node(temp->data); //using node constructor to create a new node with copy of data
            iterator = iterator->next; //advance to this new node

        }

        last = iterator; //Why do I need this line of code?
        iterator = NULL;

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
    if (size==0) {
    	Nodeptr N= new Node(data);
        first = last =N;
    }
    else {
        Nodeptr N = new Node(data);
        N->next = first;
        first->previous = N;
        first = N;
    }
    size++;
}

template <class listdata>
void List<listdata>::insertLast(listdata data)
{
    if (first == NULL) {
        Nodeptr N = new Node(data);
        last = first=N;
    }
    else {
        Nodeptr N = new Node(data);
        N->previous = last;
    	last->next = N;
    	last =last->next;
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

//Need to modify to be simple , What about while loop?
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

        Nodeptr temp = last;
        last = last->previous;
        delete temp;
        last->next=NULL;//so last->next is not pointing at freed memory
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
	assert(!isEmpty());
    return first->data;

}

template <class listdata>
listdata List<listdata>::getLast()
{
	assert(!isEmpty());
    return last->data;

}

template <class listdata>
void List<listdata>::startIterator()
{
	assert(!isEmpty());
	iterator =first;
}

template <class listdata>
void List<listdata>::removeIterator()
{
	assert(!isEmpty());
	assert(iterator=NULL);
	if (iterator == last)
	{
		removeLast();
	}
	else if(iterator==first){
		removeFirst();
	}
	else
	{
		iterator->next->previous = iterator->previous;
		iterator->previous->next = iterator->next;
		size--;
	}
	iterator=NULL;


}

template <class listdata>

void List<listdata>::insertIterator(listdata data)
{

	assert(size!=0);
	assert(iterator==NULL);
	if (iterator == last)
	 	 {
			insertLast(data);
	 	 }
	else if(iterator==first){
		insertFirst(data);
	}
		else
		{
			Nodeptr N = new Node(data);
			N->next =iterator->next;
			iterator->next = N;
			N->previous = iterator;
			iterator->next->previous = N;
		}
		size++;
}

template <class listdata>
listdata List<listdata>::getIterator()
{
	assert(!isEmpty());
	return iterator->data;
}

template <class listdata>
void List<listdata>::advanceIterator()
{
	assert(!isEmpty());
	iterator = iterator->next;
}

template <class listdata>
bool List<listdata>::offEnd()
{

	assert(!isEmpty());
	return iterator==NULL;
}

template <class listdata>
bool List<listdata>::operator==(const List& list)
{
    if(size != list.size)
        return false;
    Nodeptr temp1 = first;
    Nodeptr temp2 = list.first;
    while(temp1 != NULL)
    {
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}
/*
pre : size != 0 and pre : iterator != NULL
template <class listdata>
void list<listdata>::insertIterator(listdata data)
{
	assert(size!=0);
	assert(iterator=NULL);
	if (iterator == last){
		insertLast(data);
	}
	else {
		Nodeptr N = new Node(data);
		n ->next =iterator->next;
		interator->next = N;
		size++;
	}

}
*/
#endif /* LIST_H_ */

