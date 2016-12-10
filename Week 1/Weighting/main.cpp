/**
Improvements to the Algorithm

Quick-Union can be modified to avoid tall trees by keeping track of the
size of trees and linking small trees below the larger one.

The code is almost identical, just another array is needed to keep track of
the number of elements in a tree.
**/

#include <iostream>

using namespace std;

int* createArray(int length)
{
    int *arr = new int[length];
    for(int i = 0; i<length; i++)
    {
        arr[i] = i;
    }
    return arr;
}

int* createSizeArray(int length)
{
    int *arr = new int[length];
    for(int i = 0; i<length; i++)
    {
        arr[i] = 1;
    }
    return arr;
}

void deleteArray(int arr[])
{
    delete[] arr;
}

void printArray(int arr[], int length)
{
    for(int i = 0; i<length; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

int getRoot(int id[], int x)
{
    while(id[x] != x)
    {
        x = id[x];
    }
    return x;
}

bool QUfind(int id[], int p, int q)
{
    return getRoot(id, p) == getRoot(id, q);
}

void QuickUnion(int id[], int sz[], int p, int q) // set the root of 'p' equal to the root of 'q'
{
    int i = getRoot(id, p);
    int j = getRoot(id, q);
    if(i == j) return;
    if(sz[i] < sz[j])   { id[i] = j; sz[j] += sz[i]; }
    else                { id[j] = i; sz[i] += sz[j]; }
}


int main()
{
    int length = 10;
    int* id = createArray(length);
    int* sz = createSizeArray(length);

    QuickUnion(id, sz, 3,4);
    QuickUnion(id, sz, 4,9);
    QuickUnion(id, sz, 8,0);
    QuickUnion(id, sz, 2,3);
    QuickUnion(id, sz, 5,6);

    printArray(id, length);
    printArray(sz, length);

    return 0;
}
