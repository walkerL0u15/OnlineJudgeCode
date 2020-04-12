#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long int num,test,counter;
	while(cin>>num){
		for(int i=2;i<=num;++i){
			counter=0;
			while(num%i==0){
				++counter;
				num/=i;
			}
			if(counter>1)
				cout<<i<<"^"<<counter;
			else if(counter==1)
				cout<<i;
			if(num!=1&&counter>=1)
				cout<<" * ";
			else if(num==1)
				break;
		}
		cout<<"\n";
	}
	return 0;
}