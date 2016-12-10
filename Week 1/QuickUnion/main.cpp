/**
Quick-Union: The Lazy Approach

The data structure is the same, an array of integers. However now, id[i] is the parent of 'i'.
The root of 'i' is the ID of each parent until the ID does not change.

To find: check if two numbers have the same root.
To unite: Set the root of 'p' equal to the root of 'q'

The benefit with this approach is that only one value in the array needs to be changed, instead
of running through the entire array each time.

Drawbacks: Trees can get large, worst case they can be as large as N. Finding roots can be expensive
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

void QuickUnion(int id[], int p, int q) // set the root of 'p' equal to the root of 'q'
{
    int i = getRoot(id, p);
    int j = getRoot(id, q);
    id[i] = j;
}


int main()
{
    int length = 10;
    int* id = createArray(length);

    printArray(id, length);

    QuickUnion(id, 3,4);
    QuickUnion(id, 4,9);
    QuickUnion(id, 8,0);
    QuickUnion(id, 2,3);
    QuickUnion(id, 5,6);

    printArray(id, length);

    return 0;
}
