#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;

int main()
{
	int place;
	double ans;
	string s,nums;
	while(getline(cin,s)){
		stringstream ss(s);
		ans=0;
		while(ss>>s){
			place=0;
			while(s[place]!=':')
				++place;
			nums=s.substr(place+1,s.length()-place);
			if(static_cast<int>(s[place-1])%2==0)
				ans-=stod(nums);
			else
				ans+=stod(nums);
		}
		cout<<ans<<"\n";
	}
}