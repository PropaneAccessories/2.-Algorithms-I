#include <iostream>

using namespace std;

void selectionSort(int arr[], int length);
void insertionSort(int arr[], int length);

void printArray(int arr[], int length);

int main()
{
    int length = 10;
    int nums[] = {21,84,15,65,32,44,76,94,39,55};
    printArray(nums, length);

    selectionSort(nums, length);
    printArray(nums, length);

    return 0;
}


void selectionSort(int arr[], int length)
{
    int pos = 0;
    int temp;
    bool flag = false;

    for(int i=0; i<length; i++)
    {
        temp = arr[i];
        for(int j=i; j<length; j++)
        {
            if(arr[j] < temp)
            {
                pos = j;
                temp = arr[j];
                flag = true;
            }
        }

        if(flag)
        {
            arr[pos] = arr[i];
            arr[i] = temp;
            flag = false;
        }
    }
}

void insertionSort(int arr[], int length)
{

}

void printArray(int arr[], int length)
{
    for(int i=0; i<length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
