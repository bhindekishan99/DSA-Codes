//method learnt in GATE no of comparisions 1)
//no of comparision 
    // 3n/2-2 [n/2 + n/2-1 + n/2-1] if n is even
    // 3(n-1)/2 [ 3(n-1)/2 - 2 + 2 ] if n is odd
#include<iostream>
using namespace std;

struct minmax
{
    int min,max;
};


// see this
struct minmax findMinMax(int arr[],int size)
{
    struct minmax mm = { arr[0], arr[1] };

    int temp,i;
    int n = size-1;
    if(size%2 != 0)
        n = size-2;
    for(i=0; i<n ;i+=2)
    {
        //at index 0,2,... candidates for min and at odd index candidates for max
        if(arr[i] > arr[i+1])
        {
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    for(i=2; i<n; i+=2)
        if(arr[i] < mm.min)
            mm.min = arr[i];
    for(i=3; i<=n; i+=2)
        if(arr[i] > mm.min)
            mm.max = arr[i];    
    if(size%2!=0)
    {
        if(arr[size-1] > mm.max)
            mm.max = arr[size-1];
        else if(arr[size-1] < mm.min)
            mm.min = arr[size-1];
    }        
    return mm;
}

int main()
{
    cout<<"enter array size ";
    int n,i;
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" elements : ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    
    struct minmax mm = findMinMax(arr,n);
    cout<<"max = "<<mm.max<<" min = "<<mm.min<<endl;
    return 0;
}