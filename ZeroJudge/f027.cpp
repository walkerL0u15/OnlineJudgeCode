#include<iostream>
#include<string>
using namespace std;

int main()
{
	string name,pass;
	cin>>name>>pass;
	for(int i=0;i<name.size();++i)
		if(name[i]==':')
			for(int j=i+1;j<name.size();++j)
				printf("%c",name[j]);
	puts("");
	for(int i=0;i<pass.size();++i)
		if(pass[i]==':')
			for(int j=i+1;j<pass.size();++j)
				printf("%c",pass[j]);
	puts("\nLog in");
	return 0;
}
