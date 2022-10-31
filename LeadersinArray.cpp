/*Given an integer array A of size n. Find and print all the leaders present in the input array. An array element A[i] is called Leader, if all the elements following it (i.e. present at its right) are less than or equal to A[i].
Print all the leader elements separated by space and in the same order they are present in the input array.
input:
6
3 12 34 2 0 -1
output:
34 2 0 -1 */
#include<iostream>
#include<climits>
using namespace std;
void Leaders(int* arr,int len)
{
    int i,j;
    for(i=0;i<len;i++)
    {    int max=arr[i];
     j=1;
        for( j=i+1;j<len;j++)
        {
            if(max<arr[j])
            {
                max=arr[j];
                break;
            }
        }
     
     if(max==arr[i])
     {
         cout<<arr[i]<<" ";
     }
        
    }
}

int main()
{
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}
