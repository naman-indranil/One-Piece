#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends


#include<stack>
int countRev (string str)
{
    int len = str.size();
	if(len%2) 
		return -1;
	
	stack<char> s;
	for(int i=0; i<len; i++){
		if(str[i] == '}' && !s.empty()){
			if(s.top() == '{')
				s.pop();
			else
				s.push(str[i]);
		}else
			s.push(str[i]);
	}
	int count_left = s.size();
	int n = 0;
	while(!s.empty() && s.top() == '{'){
		s.pop();
		n++;
	}
	
	return (count_left/2 + n%2);
}