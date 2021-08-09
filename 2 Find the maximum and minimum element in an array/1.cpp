// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
//METHOD 2 (Tournament Method) 


#include<iostream>
using namespace std;

struct minmax
{
    int min,max;
};

// see this
struct minmax findMinMax(int arr[],int low,int high)
{   
    struct minmax mml,mmr,mmf;
    if(low == high)
    {
        mmf.min = mmf.max = arr[low];
    }
    else if(high == low+1)
    {
        mmf.min = arr[high] < arr[low] ? arr[high] : arr[low];
        mmf.max = mmf.min == arr[high] ? arr[low] : arr[high];
    }
    else
    {
        int mid = (low+high)/2;
        mml = findMinMax(arr,low,mid);
        mmr = findMinMax(arr,mid+1,high);
        mmf.min = mml.min < mmr.min ? mml.min : mmr.min;
        mmf.max = mml.max > mmr.max ? mml.max : mmr.max;
    }
    return mmf;
}

// T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2
// T(2)=1
// T(1)=0
// T(n)=3n/2 -2

int main()
{
    cout<<"enter array size ";
    int n,i;
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" elements : ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    
    struct minmax mm = findMinMax(arr,0,n-1);
    cout<<"max = "<<mm.max<<" min = "<<mm.min<<endl;
    return 0;
}