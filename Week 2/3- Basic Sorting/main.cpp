#include <iostream>

using namespace std;

void selectionSort(int arr[], int length);
void insertionSort(int arr[], int length);

void printArray(int arr[], int length);

int main()
{
    int length = 10;
    int nums1[] = {21,84,15,65,32,44,76,94,39,55};
    int nums2[] = {34,60,12,87,58,72,13,77,27,64};

    cout << "Array 1 before sorting: ";
    printArray(nums1, length);
    cout << "Array 2 before sorting: ";
    printArray(nums2, length);
    cout << endl;

    selectionSort(nums1, length);
    insertionSort(nums2, length);

    cout << "Array 1 after selection sort: ";
    printArray(nums1, length);
    cout << "Array 2 after insertion sort: ";
    printArray(nums2, length);
    cout << endl;

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
    int temp = 0;
    for(int i=1; i<length; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(arr[j-1] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

void printArray(int arr[], int length)
{
    for(int i=0; i<length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
