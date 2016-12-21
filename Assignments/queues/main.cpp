#include <iostream>
#include "dequeue.h"
#include "randomizedQueue.h"

int main()
{
    int i = 0;
    std::cout << "Dequeue Testing..." << std::endl;
    Dequeue d(1);
    d.addFirst(2);
    d.addFirst(3);
    d.addLast(10);
    d.addLast(9);
    d.addLast(8);
    i = d.removeLast();
    d.printOut();
    std::cout << std::endl << std::endl;

    std::cout << "Randomized Queue Testing..." << std::endl;
    RandomizedQueue r;
    r.enqueue(6);
    r.enqueue(5);
    r.enqueue(10);
    r.enqueue(2);
    r.printOut();

    std::cout << std::endl;
    std::cout << "Removing Item " << r.dequeue() << " From the queue" << std::endl;
    std::cout << std::endl;

    r.printOut();

    return 0;
}
