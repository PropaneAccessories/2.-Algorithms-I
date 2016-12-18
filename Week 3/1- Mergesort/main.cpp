#include <iostream>
#include <stdlib.h>
#include <time.h>

/**
My Mergesort implementation. Not very useful as you can't pass any information
that needs to be sorted to it. But it works on its own self generated array of
random integers.
**/

class Mergesort
{
public:
    Mergesort(int length);
    void printArray();
    void startSorting();
    ~Mergesort();

private:
    int* createArray();
    void shuffleArray();
    void sort(int low, int high);
    void merge(int low, int mid, int high);

    int* nums;
    int* aux;
    int length;
};


int main()
{
    Mergesort m(100);
    //m.printArray();
    m.startSorting();
    m.printArray();

    return 0;
}

Mergesort::Mergesort(int len)
{
    length = len;
    nums = createArray();
    aux = createArray();
    shuffleArray();
}

void Mergesort::startSorting()
{
    sort(0, length-1);
}

void Mergesort::sort(int low, int high)
{
    if(high <= low) return;
    int mid = low + (high - low)/2;
    sort(low, mid);       // sort the left half
    sort(mid+1, high);    // sort the right half
    merge(low, mid, high);// merge results
}

void Mergesort::merge(int low, int mid, int high)
{
    int i = low;
    int j = mid+1;

    for(int k=low; k<=high; k++)
        aux[k] = nums[k];

    for(int k=low; k<=high; k++)
    {
        if(i > mid)                 nums[k] = aux[j++];
        else if(j > high)           nums[k] = aux[i++];
        else if(aux[j] < aux[i])    nums[k] = aux[j++];
        else                        nums[k] = aux[i++];
    }
}

int* Mergesort::createArray()
{
    int* temp = new int[length];
    for(int i=0; i<length; i++)
        temp[i] = i;
    return temp;
}

void Mergesort::shuffleArray()
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

void Mergesort::printArray()
{
    for(int i=0; i<length; i++)
        std::cout << nums[i] << std::endl;
    std::cout << std::endl;
}

Mergesort::~Mergesort()
{
    delete[] nums;
    delete[] aux;
}
