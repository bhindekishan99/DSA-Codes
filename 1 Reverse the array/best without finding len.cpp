#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t=1;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// see this
string reverseWord(string str){    
    int start=0,end=str.length()-1;
    while(start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++,end--;
    }
  return str;
}