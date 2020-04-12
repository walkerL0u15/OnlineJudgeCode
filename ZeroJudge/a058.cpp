#include<iostream>
using namespace std;

int main()
{
	int N,num,count[3]={0};
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>num;
		if(num%3==0)
			++count[0];
		else if(num%3==1)
			++count[1];
		else
			++count[2];
	}
	cout<<count[0]<<" "<<count[1]<<" "<<count[2]<<"\n";
	return 0;
}