/*
 * Stack.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: bahman
 */
#include "Stack.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include<assert.h>

using namespace std;

Stack::Stack():top(NULL),size(0){}

Stack::Stack(const Stack &stack):size(stack.size){
    if(stack.top == NULL){
        top = NULL;
    }
    else{
        top = new Node;
        top->data = stack.top->data;
        NodePtr temp = stack.top; //Original stack temporary iterator
        NodePtr stemp = top; //Copy stack temporary iterator

        while(temp->next != NULL){
            stemp->next = new Node;
            stemp= stemp->next;
            temp = temp->next;
            stemp->data = temp->data;
        }
    }
}

Stack::~Stack(){
    NodePtr temp = top;
    NodePtr temp2 = top;

    while(temp != NULL){
        temp = temp->next;
        delete temp2;
        temp2 = temp;
    }
}

void Stack::pop()
{
    assert(top!=NULL);
    NodePtr temp = top->next;
    delete top;
    top = temp;
    size--;
}

void Stack::push(string data){
    if(size == 0){
        top = new Node(data);
    }
    else{
    NodePtr temp = new Node(data);
    temp->next = top;
    top = temp;
    }
    size++;
}

int Stack::get_size(){
    return size;
}

string Stack::peek(){
    assert(top!=NULL);
    return top->data;
}

void Stack::print(){
    NodePtr temp = top;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool Stack::operator==(const Stack &stack){
    if(size != stack.size)
        return false;

    NodePtr cursor = top;
    NodePtr cursor2 = stack.top;

    while(cursor != NULL && cursor2 != NULL){
        if(cursor->data != cursor2->data)
            return false;
        cursor = cursor->next;
        cursor2 = cursor2->next;
    }
    return true;
}

bool Stack::is_empty(){
    return size == 0;
}


