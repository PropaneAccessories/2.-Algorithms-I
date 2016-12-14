#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "grid.h"

using namespace std;

Grid::Grid(int row, int column)
{
    this->row = row;
    this->column = column;
    area = row*column;
    threshold = 0;
    counter = 0;

    createIDarray();
    createSizeArray();
    createDisplayArray();
    createSeedArray();

    srand (time(NULL));
}

Grid::~Grid()
{
    delete[] id;
    delete[] sz;
    delete[] display;
    delete[] seedArray;
}

void Grid::createIDarray()
{
    id = new int[area+2];
    for(int i=0; i<area+2; i++)
        id[i] = i;
}

void Grid::createSizeArray()
{
    sz = new int[area+2];
    for(int i=0; i<area+2; i++)
        sz[i] = 1;
}

void Grid::createDisplayArray()
{
    display = new char[area+2];
    for(int i=0; i<area+2; i++)
    {
        if(i == 0) display[i] = 'O';
        else if(i == area+1) display[i] = 'O';
        else display[i] = 'X';
    }
}

void Grid::createSeedArray()
{
    srand(time(NULL));
    int random = 0;
    int temp = 0;

    seedArray = new int[area];
    for(int i=0; i<area; i++)
        seedArray[i] = i+1;
    // not the ideal shuffling algorithm
    for(int i=0; i<area; i++)
    {
        random = rand() % area;

        temp = seedArray[i];
        seedArray[i] = seedArray[random];
        seedArray[random] = temp;
    }
}

void Grid::printOut()
{
    for(int i=1; i<=area; i++)
    {
        if(i%column == 1) cout << endl;
        cout << display[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "The Threshold *p is: " << threshold << endl;
}

void Grid::openCell()
{
    display[seedArray[counter]] = 'O';
    connect(seedArray[counter]);
    counter++;
}

int Grid::findRoot(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void Grid::connect(int num)
{
    // if the number is in the top row, connect with 0
    int i = findRoot(num);
    if(num <= column)
    {
        int j = findRoot(0);
        if(sz[i] < sz[j])   { id[i] = j; sz[j] += sz[i]; }
        else                { id[j] = i; sz[i] += sz[j]; }
    }
    // if number is in the bottom row, connect with last number in the grid
    i = findRoot(num);
    if(num > (area-column))
    {
        int j = findRoot(area+1);
        if(sz[i] < sz[j])   { id[i] = j; sz[j] += sz[i]; }
        else                { id[j] = i; sz[i] += sz[j]; }
    }
    // Check if square to the left is open, and num is not on the left edge
    i = findRoot(num);
    if(display[num-1] == 'O' && num % column != 1)
    {
        int j = findRoot(num-1);
        if(sz[i] < sz[j])   { id[i] = j; sz[j] += sz[i]; }
        else                { id[j] = i; sz[i] += sz[j]; }
    }
    // Check if the square to the right is open, and num is not on the right edge.
    i = findRoot(num);
    if(display[num+1] == 'O' && num % column != 0)
    {
        int j = findRoot(num+1);
        if(sz[i] < sz[j])   { id[i] = j; sz[j] += sz[i]; }
        else                { id[j] = i; sz[i] += sz[j]; }
    }
    // Check if the square above is open, and num is not in the top row
    i = findRoot(num);
    if(num > column && display[num-column] == 'O')
    {
        int j = findRoot(num-column);
        if(sz[i] < sz[j])   { id[i] = j; sz[j] += sz[i]; }
        else                { id[j] = i; sz[i] += sz[j]; }
    }
    // Check if the square below is open, and num is not in the bottom row
    i = findRoot(num);
    if(num < (area-column) && display[num+column] == 'O')
    {
        int j = findRoot(num+column);
        if(sz[i] < sz[j])   { id[i] = j; sz[j] += sz[i]; }
        else                { id[j] = i; sz[i] += sz[j]; }
    }
}

void Grid::findThreshold()
{
    double open = 0;
    for(int i=0; i<area; i++)
    {
        if(display[i] == 'O') open++;
    }
    threshold = open/area;
}

bool Grid::percolated()
{
    if(findRoot(0) == findRoot(area+1))
    {
        findThreshold();
        return true;
    }
    else
        return false;
}
