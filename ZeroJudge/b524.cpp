#include<stdio.h>
#include<math.h>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int ans,p;
	string s;
	while(cin>>s){
		ans=0,p=0;
		for(int i=0;i<s.size();++i)
			if(s[i]=='y'){
				ans+=abs(i-p),p+=3;
			}
		printf("%d\n",ans);
	}
	return 0;
}
