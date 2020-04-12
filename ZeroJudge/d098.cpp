#include<iostream>
#include<sstream>
#include<cstring>
using namespace std;

bool isint(string word){
	for(int i=0;i<word.length();++i)
		if(!isdigit(word[i]))
			return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s,sa;
	int ans;
	while(getline(cin,s)){
		ans=0;
		stringstream ss(s);
		while(ss>>sa)
			if(isint(sa))
				ans+=stoi(sa);
		cout<<ans<<"\n";
	}
	return 0;
}