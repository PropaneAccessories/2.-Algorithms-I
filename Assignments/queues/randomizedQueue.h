#ifndef RANDOMIZEDQUEUE_H
#define RANDOMIZEDQUEUE_H

class RandomizedQueue
{
public:
    RandomizedQueue();          /**/
    ~RandomizedQueue();         /**/
    bool isEmpty();             /**/
    int size();                 /**/
    void enqueue(int num);      /**/
    int dequeue();              /**/
    int sample();               /**/
    void printOut();            /**/

private:
    struct Node
    {
        Node* next;
        int data;
    };

    Node mNode;
    Node* first;
};

#endif // RANDOMIZEDQUEUE_H
