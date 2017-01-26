#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue(){}

Queue::Queue(const Queue &queue):size(queue.size)
{

        if(queue.front == NULL)
        {
            end = front = NULL;
        }
       else
        {
            front = new Node;
            front->data = queue.front->data;
            NodePtr temp;
            temp = queue.front;
            NodePtr qtemp = front; //create temporary iterator

            while(temp->next != NULL)
            {

                qtemp->next = new Node;
                qtemp = qtemp->next;
                temp = temp->next;
                qtemp->data = temp->data;

            }

            end = qtemp;
        }

}

Queue::~Queue()
{
    NodePtr temp = front;
    NodePtr temp2 = front;
    while (temp != NULL)
    {
        temp = temp->next;
        delete temp2;
        temp2 = temp;
    }
}

void Queue::dequeue(){}

void Queue::enqueue(string data){}

bool Queue::operator==(const Queue &queue){return 1 ;}

string Queue::get_front() {return "a";}

int Queue::get_size(){return 2;}

void Queue::print()
{
    NodePtr temp;
    temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
