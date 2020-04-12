#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int num[4],counter;
	cin>>counter;
	for(int j=0;j<counter;++j){
		for(int i=0;i<4;++i){
			cin>>num[i];
			cout<<num[i]<<" ";
		}
		if(num[3]-num[2]==num[2]-num[1])
			cout<<num[3]*2-num[2]<<"\n";
		else if(num[3]/num[2]==num[2]/num[1])
			cout<<num[3]*num[3]/num[2]<<"\n";
		}
	return 0;
}