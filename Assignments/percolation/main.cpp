#include <iostream>
#include "grid.h"

using namespace std;

int main()
{
    Grid g1(20,20);

    while(!g1.percolated())
    {
        g1.openCell();
    }
    g1.printOut();

    return 0;
}
