//Name : Akashdeep-k
//Date : 16/10/2022

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//                                           Binary Search	 					    //
	//                                           /////////////	                     			    //
	//                                                                                                          //
	//	Binary Search is a searching algorithm which is performed on sorted list of elements	            //
	//	It is based on repeated application of Intermediate value theorem (IVT)				    //
	//										            		    //
	//     	Approach : At first, the key (telement to be searched) element is firstly compaired with the 	    //
	//		middle element of the array. There will be two cases :					    //
	//		 										            //
	//		Case 1 : Key element is less than middle element 	   				    //
	//			As the array is sorted thus the key lies in the left part of the middle element.    //
	//		Case 2 : Key element is greater than middle element					    //
	//			Thus key will be in the right part of the middle element.			    //
	//								               				    //
	//     This process is repeted till we get middle element equal to key element.			            //
	//													    //
	//     Time Complexity : O(logn) -- worst case (when element is present at an extreme end)		    //
	//     Space Complexity : O(1)										    //
	//													    //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Coding the algorithm
#include <iostream>
using namespace std;
int binary_search(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;                            //start of the array
    high = size - 1;                    //end of the array
    mid = low + (high-low)/2;//mid of the array
                                       // searching started
    while (low <= high)                //whether we are in the bound of array or not
    {
        if (arr[mid] == element)      //middle element = key element
        {
            return mid;               //index of key element = index of middle element
        }
        if (arr[mid] < element)       //key element > middle element
        {
            low = mid + 1;            //thus searching in the right part to the middle of the array
        }
        else                          //when key elment < middle element
        {
            high = mid - 1;           //thus searching in the left part to the middle of the array
        }
         mid = low + (high-low)/2;    //after updation of start or end variables --> updating mid variable according to 
		                      //new values
    }
                                      // searching ended
    return -2;                        //when element is not present in the array
}
int main()
{
    int size;
    cout << "Enter the size of array : " << endl;              //array size input
    cin >> size;
    int arr[size];
    cout << "Enter the array elements : " << endl;           //array elements input
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    // int size = sizeof(arr)/sizeof(int);
    int element;
    cout << "Enter element you want to search : " << endl;   //key input
    cin >> element;
    int pos = binary_search(arr, size, element);
    cout << "Element found at position : " << pos + 1;       //as position of element = index of element + 1
    return 0;
}
