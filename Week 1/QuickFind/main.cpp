/**
The Quick Find algorithm. Slow for large N. Time to complete grows quadratically as the number
of elements increases.
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

void Union(int arr[], int length, int p, int q)     // add a connection between p and q
{
    int pid = arr[p];
    int qID = arr[q];
    for(int i = 0; i < length; i++)
    {
        if(arr[i] == pid) arr[i] = qID;
    }
}

bool connected(const int arr[], int p, int q)    // return true if p and q are part of the same component
{
    if(arr[p] == arr[q]) return true;
    else return false;
}

int main()
{
    int length = 6;
    int* NumArray = createArray(length);

    printArray(NumArray, length);

    Union(NumArray, length, 1,2);
    printArray(NumArray, length);

    Union(NumArray, length, 2,5);
    printArray(NumArray, length);

    Union(NumArray, length, 3,4);
    printArray(NumArray, length);

    Union(NumArray, length, 0,3);
    printArray(NumArray, length);

    deleteArray(NumArray);
    NumArray = NULL;

    return 0;
}
