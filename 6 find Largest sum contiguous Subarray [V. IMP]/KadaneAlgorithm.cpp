#include<iostream>
using namespace std;

int kadaneAlgo(int arr[], int size)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for(int i=0;i<size;i++)
    {
        max_ending_here += arr[i];
        if(max_ending_here > max_so_far)
            max_so_far = max_ending_here;
        if(max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
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
    cout<<"max array sum is : "<<kadaneAlgo(arr,size)<<endl;
    return 0;
}