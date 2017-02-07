/*
 * QueueTest.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: bahman
 */

#include "Queue.h"
#include <cstdlib>
#include <iostream>
/*
using namespace std;

int main(){

	//create a default Queue with default constructor
    Queue Q1;

    //Testing Is empty for Queue with empty queue
    cout<<"Testing is_empty function when is empty, Should print : Q is empty"<<endl;
    if(Q1.is_empty())
    {
    	cout<<"Q is empty"<<endl;
    }
    else
    {
    	cout<<"Q is not empty"<<endl;
    }
    cout<<"Testing enqueue function when Q1 has no element , First scenario: should add I to the Queue, should print : I "<<endl;
    Q1.enqueue("I");
    Q1.print();

    cout<<"Testing enqueue function when Q1 has one element , Second scenario: should add hate to the Queue, should print : I Hate "<<endl;
    Q1.enqueue("Hate");
    Q1.print();

    cout<<"Testing enqueue function when Q1 has two element , third scenario: should add hate to the Queue, should print : I Hate War"<<endl;
    Q1.enqueue("War");
    Q1.print();

    cout<<"Testing print function: should print : I hate War"<<endl;
    Q1.print();
    Q1.dequeue();
    cout<<"Testing dequeue function when Q1 is not empty: should print : Hate War"<<endl;
    Q1.print();

    cout<<"Testing is_empty function when is not empty, Should print : Q is not empty"<<endl;
        if(Q1.is_empty())
        {
        	cout<<"Q is empty"<<endl;
        }
        else
        {
        	cout<<"Q is not empty"<<endl;
        }

    cout<<"Testing get_size() function , should return 2 :"<<endl<< Q1.get_size()<<endl;
   cout <<"Testing copy constructor create Q2"<<endl;
   Queue Q2(Q1);
   cout<<"printing Q2 , it should print :Hate War"<<endl;
   Q2.print();
   cout <<"Testing == operator to see if Q1 is equal to Q2, it should print Q1 and Q2 are equal"<<endl;
   if(Q1==Q2)
           {
           	cout<<"Q1 and Q2 are equal"<<endl;
           }
           else
           {
           	cout<<"Q1 and Q2 are equal"<<endl;
           }
   cout<<"Testing get_front() function , should return  : Hate"<<endl<< Q2.get_front()<<endl;



   cout <<"Testing == operator to see if Q1 is equal to Q2 , first we use dequeue for Q2 to make them unequal, it should print Q1 and Q2 are not equal"<<endl;
   Q2.dequeue();

   if(Q1==Q2)
              {
              	cout<<"Q1 and Q2 are equal"<<endl;
              }
              else
              {
              	cout<<"Q1 and Q2 are not equal"<<endl;
              }
   cout<<"using default constructor to create an empty Q3"<<endl;
   Queue Q3;
   cout<<"using copy constructor to create an empty Q4 from Q3 to show edge case is working for copy constructor"<<endl;
   cout<<"Should print empty for Q4"<<endl;
   Queue Q4(Q3);
   Q4.print();
   cout<<"finally testing dequeue for empty Q4 to see if assert is working, assert should alert us"<<endl;
   Q4.dequeue();

}



 Test Output :

 Testing is_empty function when is empty, Should print : Q is empty
Q is empty
Testing enqueue function when Q1 has no element , First scenario: should add I to the Queue, should print : I
I
Testing enqueue function when Q1 has one element , Second scenario: should add hate to the Queue, should print : I Hate
I Hate
Testing enqueue function when Q1 has two element , third scenario: should add hate to the Queue, should print : I Hate War
I Hate War
Testing print function: should print : I hate War
I Hate War
Testing dequeue function when Q1 is not empty: should print : Hate War
Hate War
Testing is_empty function when is not empty, Should print : Q is not empty
Q is not empty
Testing get_size() function , should return 2 :
2
Testing copy constructor create Q2
printing Q2 , it should print :Hate War
Hate War
Testing == operator to see if Q1 is equal to Q2, it should print Q1 and Q2 are equal
Q1 and Q2 are equal
Testing get_front() function , should return  : Hate
Hate
Testing == operator to see if Q1 is equal to Q2 , first we use dequeue for Q2 to make them unequal, it should print Q1 and Q2 are not equal
Q1 and Q2 are not equal
using default constructor to create an empty Q3
using copy constructor to create an empty Q4 from Q3 to show edge case is working for copy constructor
Should print empty for Q4

finally testing dequeue for empty Q4 to see if assert is working, assert should alert us
Assertion failed: (front!=NULL), function dequeue, file ../src/Queue.cpp, line 60.


*/

