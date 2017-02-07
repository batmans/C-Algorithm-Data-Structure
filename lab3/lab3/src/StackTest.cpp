/*
 * StackTest.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: bahman
 */


#include "Stack.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
/*
int main()
{
		//create a default Stack with default constructor
		Stack S1;
	    //Testing Is empty for Queue with empty queue
	    cout<<"Testing is_empty function when is empty, Should print : S is empty"<<endl;
	    if(S1.is_empty())
	    {
	    	cout<<"Stack is empty"<<endl;
	    }
	    else
	    {
	    	cout<<"Stack is not empty"<<endl;
	    }

	       cout<<"Testing Stack function when S1 has no element , First scenario: should add I to the Stack, should print : I "<<endl;
	       S1.push("I");
	       S1.print();

	       cout<<"Testing Stack function when S1 has one element , Second scenario: should add learn to the Stack, should print : learn I "<<endl;
	       S1.push("learn");
	       S1.print();

	       S1.pop();
	       cout<<"Testing pop function when S1 is not empty: should print : I"<<endl;
	       S1.print();

	       cout<<"Testing is_empty function when is not empty, Should print : Stack is not empty"<<endl;
	              if(S1.is_empty())
	              {
	              	cout<<"Stack is empty"<<endl;
	              }
	              else
	              {
	              	cout<<"Stack is not empty"<<endl;
	              }

	       cout<<"Testing get_size() function , should return 1 :"<<endl<< S1.get_size()<<endl;

	       cout <<"Testing copy constructor create S2"<<endl;
	       Stack S2(S1);
	       cout<<"printing S2 , it should print :I"<<endl;
	       S2.print();

	       cout <<"Testing == operator to see if S1 is equal to S2, it should print S1 and S2 are equal"<<endl;
	         if(S1==S2)
	                 {
	                 	cout<<"S1 and S2 are equal"<<endl;
	                 }
	                 else
	                 {
	                 	cout<<"S1 and S2 are not equal"<<endl;
	                 }
	         cout<<"adding a 2 more elements to S1 using push function"<<endl;
	         S1.push("learn");
	         S1.push("code");
	         cout<<"printing S1"<<endl;
	         S1.print();

	         cout<<"Testing peek() function , should return  : I"<<endl<< S2.peek()<<endl;

	         cout <<"Testing == operator to see if S1 is equal to S2, it should print S1 and S2 are not equal"<<endl;
	         if(S1==S2)
	         {
	        	 cout<<"S1 and S2 are equal"<<endl;
	         }
	         else
	         {
	        	 cout<<"S1 and S2 are not equal"<<endl;
	         }
	         cout<<"using pop to make S2 empty"<<endl;
	         S2.pop();
	        S2.print();
	        cout<<"Test pop and peek for S2 which activate assert"<<endl;
	        S2.pop();
	        S2.peek();


}

Testing output
Testing is_empty function when is empty, Should print : S is empty
Stack is empty
Testing Stack function when S1 has no element , First scenario: should add I to the Stack, should print : I
I
Testing Stack function when S1 has one element , Second scenario: should add learn to the Stack, should print : learn I
learn I
Testing pop function when S1 is not empty: should print : I
I
Testing is_empty function when is not empty, Should print : Stack is not empty
Stack is not empty
Testing get_size() function , should return 1 :
1
Testing copy constructor create S2
printing S2 , it should print :I
I
Testing == operator to see if S1 is equal to S2, it should print S1 and S2 are equal
S1 and S2 are equal
adding a 2 more elements to S1 using push function
printing S1
code learn I
Testing peek() function , should return  : I
I
Testing == operator to see if S1 is equal to S2, it should print S1 and S2 are not equal
S1 and S2 are not equal
using pop to make S2 empty

Test pop and peek for S2 which activate assert
Assertion failed: (top!=NULL), function peek, file ../src/Stack.cpp, line 73.

*/
