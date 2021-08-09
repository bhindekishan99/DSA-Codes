12#include<iostream>
using namespace std;
void maxHeapify(int a[], int idx, int s); // declaration of function is needed otherwise you will get error.
void deleteMax(int a[],int s);
int findKthMax(int a[],int s);
void creatMaxHeap(int a[],int s)
{
    int last_none_leaf = s/2-1,i;
    for(i=last_none_leaf;i>=0;i--)
        maxHeapify(a,i,s);
}
void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void maxHeapify(int a[], int idx, int s)
{
    // cout<<"for idx= "<<idx<<" ::->> ";
    if((2*idx+2 > s-1) && (2*idx+1 <= s-1)) //means node at index idx does not have right child and only has left child.
        {
            if(a[idx] < a[2*idx+1])
            {
                // cout<<"swapping is for "
                swap(a+idx,a+2*idx+1);
            }
            // for(int i=0;i<s;i++)
            //     cout<<a[i]<<" ";
            // cout<<endl;
        }
    else if(2*idx+2 <= s-1) //means node at index idx has both child.
    {
        int large_child_idx = a[2*idx+1] > a[2*idx+2] ? 2*idx+1 : 2*idx+2;
        if(a[large_child_idx] > a[idx])
        {

            swap(a+large_child_idx, a+idx);
            // for(int i=0;i<s;i++)
            //     cout<<a[i]<<" ";
            // cout<<endl;
            maxHeapify(a,large_child_idx,s);
        }
    }
    else
    {
        // cout<<endl;
        //means node at index idx does not havechild, i.e it is leaf node.
    }

}
void deleteMax(int a[],int s)
{
    swap(a+0,a+s-1);
    s--; //now one element is removed so size is reduced by 1
    maxHeapify(a,0,s); 
}
int findKthMax(int a[],int s,int k)
{
    int temp = k;
    while(temp--)
    {
        deleteMax(a,s);
        s--;
        // cout<<"::"<<a[s]<<endl;
    }
    return a[s];
}
int main()
{
    int size,i,k;
    cout<<"enter size of array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"enter "<<size<<" numbers: ";
    for(i=0;i<size;i++)
        cin>>arr[i];
    // for(i=0;i<size;i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    creatMaxHeap(arr,size);
    cout<<"max heap is : "<<endl;
    for(i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"enter k to fin kth max number : ";
    cin>>k;
    int kthmax=findKthMax(arr,size,k);
    cout<<k<<" max is "<<kthmax<<endl;
}
