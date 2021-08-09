#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    
  //Your code here
  int i,j,len=str.length();
  j=len-1;
  for(i=0;i<len/2;i++,j--)
  {
    char temp = str[i];
    str[i]=str[j];
    str[j]=temp;
  }
  return str;
}