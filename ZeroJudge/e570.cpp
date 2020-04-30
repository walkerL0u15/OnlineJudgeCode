#include<iostream>
using namespace std;

int main()
{
	string s;
	char ru[]="¤§",zi[]="¬O";
	
	while(cin>>s){
		for(int i=0;i<s.size();i+=3)
			if(s[i]==ru[0]&&s[i+1]==ru[1]||s[i]==zi[0]&&s[i+1]==zi[1]){
				for(int j=i+3;j<s.size();++j)
					cout<<s[j];
				for(int j=0;j<i;++j)
					cout<<s[j];
				puts("");
				break;
			}
	}
	return 0;
}
