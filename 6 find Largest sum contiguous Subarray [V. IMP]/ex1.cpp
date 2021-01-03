#include<iostream>
using namespace std;

int findSum(int a[], int s);

int findSum(int a[], int size)
{
    int s = size;
    int i,j;

    int maxsum=a[0];
    for(i=0;i<s;i++)
    {
        int tempsum=0;
        for(j=i;j<s;j++)
        {
            tempsum+=a[j];
            if(tempsum > maxsum)
            {
                maxsum = tempsum;
            }
        }
    }
    return maxsum;
}

int main()
{
    int size;
    cout<<"enter size of array :";
    cin>>size;
    int arr[size];
    cout<<"enter "<<size<<" numberes :";
    for(int i=0;i<size;i++)
        cin>>arr[i];
    cout<<"max array sum is : "<<findSum(arr,size)<<endl;
    return 0;
}