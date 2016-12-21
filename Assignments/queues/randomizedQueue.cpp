#include <iostream>
#include "randomizedQueue.h"
#include <stdlib.h>
#include <time.h>

RandomizedQueue::RandomizedQueue()
{
    mNode.data = -1;
    mNode.next = NULL;

    first = &mNode;
    srand(time(NULL));
}

RandomizedQueue::~RandomizedQueue()
{
    while(first != NULL)
    {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}

bool RandomizedQueue::isEmpty()
{
    if(first->next == NULL && first->data == -1)
        return true;
    else return false;
}

int RandomizedQueue::size()
{
    Node* temp = first;
    int size = 0;
    while(temp != NULL && temp->data != -1)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

void RandomizedQueue::enqueue(int num)
{
    Node* temp = new Node;
    temp->data = num;
    temp->next = first;
    first = temp;
}

int RandomizedQueue::dequeue()
{
    int random = rand() % this->size();

    if(first->next == NULL && first->data == -1)
    {
        std::cout << "Error: This Stack Is Empty" << std::endl;
        return -1;
    }
    else
    {
        int data = -1;
        Node* temp = first;
        Node* previous = first;
        for(int i=0; i<random; i++)
        {
            previous = temp;
            temp = temp->next;
        }

        data = temp->data;
        if(temp != NULL)
        {
            previous->next = temp->next;
            delete temp;
        }

        return data;
    }
}

int RandomizedQueue::sample()
{
    int random = rand() % this->size();

    if(first->next == NULL && first->data == -1)
    {
        std::cout << "Error: This Stack Is Empty" << std::endl;
        return -1;
    }
    else
    {
        Node* temp = first;
        for(int i=0; i<random; i++)
            temp = temp->next;
        return temp->data;
    }
}

void RandomizedQueue::printOut()
{
    Node* temp = first;
    while(temp != NULL && temp->data != -1)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}
