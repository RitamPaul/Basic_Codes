//Name : Akashdeep-k
//Date : 15/10/2022

// Binary Search
#include <iostream>
using namespace std;
int binary_search(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    mid = low + (high-low)/2;
    // searching started
    while (low <= high)
    {
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
         mid = low + (high-low)/2;
    }
    // searching ended
    return -2;
}
int main()
{
    int size;
    cout << "Enter the size of array : " << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the array elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    // int size = sizeof(arr)/sizeof(int);
    int element;
    cout << "Enter element you want to search : " << endl;
    cin >> element;
    int pos = binary_search(arr, size, element);
    cout << "Element found at position : " << pos + 1;
    return 0;
}
