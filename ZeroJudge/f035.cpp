#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	string s;
	getline(cin,s);
	for(int i=0;i<s.size()-1;++i)
		printf("%d_",(int)s[i]);
	printf("%d\n",(int)s[s.size()-1]);
	return 0;
}
