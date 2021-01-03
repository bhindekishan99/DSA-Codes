#include<bits/stdc++.h>
using namespace std;


int getMinDiff(int arr[], int n, int k) {
    // code here
    pair<int, int> pi;
    vector<pair<int, int>> height;
    int i, minDiff = INT_MAX;
    for( i = 0; i < n; i++ )
    {
        if( arr[i] >= k )
            height.push_back(make_pair(arr[i]-k, i));

        height.push_back(make_pair(arr[i]+k, i));
    }
    sort(height.begin(), height.end());
    // for(int i = 0; i < height.size(); i++ )
    //     cout<<height[i].first<<" "<<height[i].second<<endl;
    int x = height.size();
    int present[n];
    for(i = 0; i < n; i++ )
        present[i] = 0;
    
    // int start = 0, end = 0, count = 0;
    // while( end < size )
    // {
    //     if( present[ height[end].second ] == 0 )
    //     {
    //         present[ height[end].second ]++;
    //         count++;
    //         if( count == n )
    //         {
    //             minDiff = min(minDiff, height[end].first - height[start].first);
    //             present[ height[start].second ]--;
    //             if( present[ height[start].second ] == 0 )
    //                 count--;
    //         }
    //         end++;
    //     }
    //     else
    //     {
    //         end++;
    //     }
    // }
    
    int start=0, end = -1, count = 0; 
    while( end+1 < x )
    {
        if( count < n )
        {
            end++;
            present[ height[end].second ]++;
            // cout<<"end = "<<end<<" "<<start<<"c = "<<count<<" size = "<<x<<endl; 
            if( present[ height[end].second ] == 1 )
            {
                count++;
            }
        }
        if( count == n )
        {
            
            minDiff = min( minDiff, height[end].first - height[start].first );
            // cout<<end<<" "<<start<<" "<<minDiff<<endl;
            present[ height[start].second ]--;
            if( present[ height[start].second ] == 0 )
            {
                count--;
            }
            start++;
        }
    }
    return minDiff;
}   

int main()
{
    int arr[] = {3, 9, 12, 16, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    // cout<<"helo";
    int ans = getMinDiff(arr,n,k);
    cout<<ans;
    return 0;
}