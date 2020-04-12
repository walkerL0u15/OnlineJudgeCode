#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int count;
	while(getline(cin,s)){
		count=1;
		for(int i=1;i<s.size();++i)
			if(isalpha(s[i])&&!isalpha(s[i-1]))
				++count;
		cout<<count<<"\n";
	}
	return 0;
}