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

string reverseWord(string str){
    // std::string::reverse_iterator i;
    // string res = "";
    // for(i=str.rbegin();i!=str.rend();i++)
    // {
    //     res.push_back(*i);
    // }
	// return res;
	reverse(str.begin(),str.end());
    return str;
       
}