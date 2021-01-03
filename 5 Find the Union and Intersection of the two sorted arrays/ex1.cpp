#include<iostream>
using namespace std;

void findUnion(int a1[],int s1,int a2[],int s2)
{
    int i=0,j=0,k=0;
    int u[s1+s2];
    while(i<s1 && j<s2)
    {
        if(a1[i] > a2[j])
        {
            u[k++] = a2[j++];        
        }
        else if(a1[i] == a2[j])
        {
            u[k++] = a1[i++];
            j++;
        }
        else
        {
            u[k++] = a1[i++];
        }
    }
    while(i<s1)
    {
        u[k++]=a1[i++];
    }
    while(j<s2)
    {
        u[k++]=a2[j++];
    }
    cout<<"union is : "<<endl;
    for(int x=0;x<k;x++)
    {
        cout<<u[x]<<" ";
    }
}
void findIntersection(int a1[],int s1,int a2[],int s2)
{
    int i=0,j=0,k=0;
    int u[s1<s2 ? s1 : s2];
    while(i<s1 && j<s2)
    {
        if(a1[i] > a2[j] && j++);
        else if(a1[i] == a2[j])
        {
            u[k++] = a1[i++];
            j++;
        }
        else
        {i++;}
    }

    cout<<"Intersection is : "<<endl;
    for(int x=0;x<k;x++)
    {
        cout<<u[x]<<" ";
    }
}
int main()
{
    int size1,size2;
    cout<<"enter size of array 1 and array 2 :";
    cin>>size1>>size2;
    int arr1[size1],arr2[size2];
    cout<<"enter "<<size1<<" numbers for array1 :";
    for(int i=0;i<size1;i++)
        cin>>arr1[i];
    
    for(int i=0;i<size1;i++)
        cout<<arr1[i]<<" ";
    cout<<endl;    
    
    cout<<"enter "<<size2<<" numbers for array2 :";
    for(int i=0;i<size2;i++)
        cin>>arr2[i]; 

    for(int i=0;i<size2;i++)
        cout<<arr2[i]<<" ";
    cout<<endl;

    findUnion(arr1,size1,arr2,size2);
    findIntersection(arr1,size1,arr2,size2);
}