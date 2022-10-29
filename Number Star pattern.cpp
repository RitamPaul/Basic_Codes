/*we have to print a pattern for given number of rows.
1234554321
1234**4321
123****321
12******21
1********1
*/
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int n,i,j,k,a=1;
    cin>>n;
    for(i=1;i<=n;i++)
    {      if(i==1){
        for(j=1;j<=n;j++)
        {
            cout<<j;
        }
        for(k=j-1;k>=1;k--)
        {
            cout<<k;
        }
        cout<<endl;
    }
     else
     {
         for(j=1;j<=n-i+1;j++)
        {
            cout<<j;
        }
         for(int y=n-i+2;y<n-i+2+2*a;y++)
         {
             cout<<"*";
             
         }
         
        for(k=n-i+2+2*a;k<=2*n;k++)
        {
            cout<<--j;
        }
         a++;
        cout<<endl; 
     }
    }
}
