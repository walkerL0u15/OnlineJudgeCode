#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string a;
	cin>>a;
	sort(a.begin(),a.end());
	cout<<a<<"\n";
	return 0;
}