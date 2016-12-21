#include "dequeue.h"
#include <iostream>

Dequeue::Dequeue()
{
    mNode.data = -1;
    mNode.forward = NULL;
    mNode.backward = NULL;

    first = &mNode;
    last = &mNode;
}

Dequeue::Dequeue(int num)
{
    mNode.data = num;
    mNode.forward = NULL;
    mNode.backward = NULL;

    first = &mNode;
    last = &mNode;
}

Dequeue::~Dequeue()
{
    while(first != NULL)
    {
        Node* temp = first;
        first = first->backward;
        delete temp;
    }
}

void Dequeue::addFirst(int num)
{
    Node* temp = new Node;
    first->forward = temp;  // the first element in the list now points to the new element
    temp->data = num;
    temp->backward = first; // the back pointer now points to the previous first item.
    temp->forward = NULL;   // it's the first one so nothing is in front.
    first = temp;
}

void Dequeue::addLast(int num)
{
    Node* temp = new Node;
    last->backward = temp;  // the last element in the list now points backwards to the new element
    temp->data = num;
    temp->forward = last;   // forward pointer now points to the element in front
    temp->backward = NULL;  // nothing to point back to as it is now the last element
    last = temp;
}

int Dequeue::removeFirst()
{
    if(first->backward == NULL)
    {
        std::cout << "Error: Empty Dequeue" << std::endl;
        first->data = -1;
        return -1;
    }
    else
    {
        int data = first->data;
        Node* temp = first;
        first = first->backward;
        first->forward = NULL;
        delete temp;
        return data;
    }
}

int Dequeue::removeLast()
{
    if(last->forward == NULL)
    {
        std::cout << "Error: Empty Dequeue" << std::endl;
        last->data = -1;
        return -1;
    }
    else
    {
        int data = last->data;
        Node* temp = last;
        last = last->forward;
        last->backward = NULL;
        delete temp;
        return data;
    }
}

bool Dequeue::isEmpty()
{
    if(first == last && first->data == -1)
        return true;
    else return false;
}

int Dequeue::size()
{
    int size = 0;
    Node* temp = first;
    while(temp != NULL)
    {
        temp = temp->backward;
        size++;
    }
    return size;
}

void Dequeue::printOut()
{
    Node* temp = first;
    while(temp != NULL)
    {
        std::cout << temp->data << std::endl;
        temp = temp->backward;
    }
}
