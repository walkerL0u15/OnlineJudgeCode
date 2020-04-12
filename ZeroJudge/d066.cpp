#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h,m;
	cin>>h>>m;
	if(h>=17)
		cout<< "Off School\n";
	else if(h<7)
		cout<< "Off School\n";
	else if(h==7&&m<30)
		cout<< "Off School\n";
	else
		cout<< "At School\n";
	return 0;
}