#include<iostream>
#include<string>
using namespace std;

int main()
{
	string name;
	while(getline(cin,name))
		printf("HELLO,%s\n",name.c_str());
	return 0;
}
