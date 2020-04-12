#include<iostream>
using namespace std;

int main()
{
	int M,D;
	while(cin>>M>>D){
		if((M*2+D)%3==0)
			cout<<"普通";
		else if((M*2+D)%3==1)
			cout<<"吉";
		else
			cout<<"大吉";
	}
	return 0;
}