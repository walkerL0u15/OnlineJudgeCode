#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	bool find;
	unsigned int a,b,test,ans,place;
	while(cin>>a>>b){
		find=false;
		for(;a<=b;++a){
			test=a;
			ans=0;
			place=0;
			while(test!=0){
				++place;
				test/=10;
			}
			test=a;
			while(test!=0){
				ans+=pow(test%10,place);
				test/=10;
			}
			if(ans==a){
				cout<<a<<" ";
				find=true;
			}
		}
		if(find==false)
			cout<<"none";
		cout<<"\n";
	}
	return 0;
