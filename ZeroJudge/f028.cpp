#include<iostream>
using namespace std;

int main()
{
	string name;
	int score;
	while(cin>>name>>score){
		cout<<name<<":"<<(score>=60?"Yes\n":"No\n");
	}
	return 0;
}
