/**
Binary Search is a quick way to find if a value is held inside a sorted array

For each loop it splits the array in half and checks to see if the value needed
is less than or greater than the value in the middle of the array. If lower it
moves to the lower half the next run, if higher it moves to the next half, and
so on, until the value is found, or no such value is held in the array.
**/

#include <iostream>

using namespace std;

int main()
{
    int length = 10;
    int sortedArray[] = {5,14,19,25,31,33,39,41,57,62};

    int key = 31;
    int pos = -1;

    for(int i=length/2; i>0 && i<=length; )
    {
        if(sortedArray[i] > key)  // move to lower half of array
            i = i/2;
        else if(sortedArray[i] < key) // move to upper half of array
            i += i/2;
        else
        {
            pos = i;
            break;
        }
    }
    cout << pos << endl;

    return 0;
}
