#include<iostream>
using namespace std;

int main()
{
	int times,a,b,total;
	cin>>times;
	for(int i=1;i<=times;++i){
		cin>>a>>b;
		total=0;
		for(int j=1;j<=b;++j){
			if(j*j>=a&&j*j<=b){
				total+=j*j;
			}
			else if(j*j>b)
				break;
		}
		cout<<"Case "<<i<<": "<<total<<"\n";
	}
	return 0;
}