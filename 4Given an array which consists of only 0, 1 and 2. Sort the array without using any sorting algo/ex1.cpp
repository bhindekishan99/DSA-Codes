void sort012(int a[], int n)
{
    int low=0,mid=0,high=n-1,temp;
    
    /*
    low points to left most 1
    mid points to index which is going to examined, all element left ot mid are eamined and
        arrenged as expected
    high is points to left of left most 2
    
    see ex :
        0 0 0 0 1 1 1 x x x x 2 2 2 2
        l             m     h       

    NOTE : initial vaues of low = 9, mid = 0 and high = n-1
     
    */
    
    
    
    
     /*CONDITION
        if we use condition mid < high, it will give wrong as,
        consider this example
        so here mid == high, and we if apply condition mid<high
        then here we come uot of loop without examin element at arr[mid]
        0 0 0 1 1 1 x 2 2 2
              L     m    
                    h
        
        other ex : 0 1 0, which gives wrong ans on condition mid < high
        So mid <= high is RGHHT CONDITION
    */
    while(  mid <= high  )
    {
        if( a[mid] == 0 )
        {
            temp = a[mid];
            a[mid] = a[low];
            a[low] = temp;
            mid++;
            low++;
        }
        else if( a[mid] == 1 )
        {
            mid++;
        }
        else if(a[mid] == 2)
        {
            temp = a[high];
            a[high] = a[mid];
            a[mid] = temp;
            high--;
        }
        
    }
}