#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int* createArray(int length);
void shuffleArray(int nums[], int length);
void shellsort(int nums[], int length);
void printArray(int nums[], int length);

int main()
{
    int length = 100;
    int* Array = createArray(length);
    shuffleArray(Array, length);
    printArray(Array, length);

    shellsort(Array, length);
    printArray(Array, length);

    return 0;
}

void shellsort(int nums[], int length)
{
    int temp = 0;
    int h = 1;
    while(h < (length/3)) {h = h*3 + 1;}
    while(h >= 1)
    {
        for(int i=h; i<length; i++)
        {
            for(int j=i; j>=h; j -= h)
            {
                if(nums[j-h] > nums[j])
                {
                    temp = nums[j];
                    nums[j] = nums[j-h];
                    nums[j-h] = temp;
                }
            }
        }
        h = h/3;
    }
}

int* createArray(int length)
{
    int* temp = new int[length];
    for(int i=0; i<length; i++)
        temp[i] = i;
    return temp;
}

void shuffleArray(int nums[], int length)
{
    srand(time(NULL));
    int random = 0;
    int temp = 0;
    for(int i=2; i<length; i++)
    {
        random = rand() % i;
        // swapping values...
        temp = nums[i];
        nums[i] = nums[random];
        nums[random] = temp;
    }
}

void printArray(int nums[], int length)
{
    for(int i=0; i<length; i++)
        cout << nums[i] << endl;
    cout << endl;
}
