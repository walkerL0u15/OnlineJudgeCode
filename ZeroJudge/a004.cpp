#include<iostream>
using namespace std;

int main()
{
	int a;
	while(cin>>a){
	if(a%4!=0)
		cout<<"平年\n";
	else if(a%100!=0)
		cout<<"閏年\n";
	else if(a%400!=0)
		cout<<"平年\n";
	else
		cout<<"閏年\n";
}
	return 0;
}