#ifndef DEQUEUE_H
#define DEQUEUE_H

class Dequeue
{
public:
    Dequeue();              /**/
    Dequeue(int num);       /**/
    ~Dequeue();             /**/
    bool isEmpty();         /** In my implementation there is always at least one node **/
    int size();             /**/
    void addFirst(int num); /**/
    void addLast(int num);  /**/
    int removeFirst();      /**/
    int removeLast();       /**/
    void printOut();        /**/

private:
    struct Node
    {
        int data;
        Node* forward;
        Node* backward;
    };

    Node mNode;
    Node* first;
    Node* last;
};


#endif // DEQUEUE_H
