#include<set>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	string ss;
	set<string> s;
	while(getline(cin,ss)){
		if(s.find(ss)==s.end()){
			s.insert(ss);
			puts("NO");
		}
		else
			puts("YES");
	}
	return 0;
}
