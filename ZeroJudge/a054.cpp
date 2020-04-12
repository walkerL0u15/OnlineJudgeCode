#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int word[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
	int total;
	string s;
	while(cin>>s){
		total=0;
		for(int i=8;i>=1;--i)
			total+=(s[8-i]-48)*i;
		for(int i=0;i<26;++i)
			if((total+word[i]%10*9+(word[i]-word[i]%10)/10)%10==10-s[8]+48)
				cout<<static_cast<char>(i+65);
		cout<<"\n";
	}
	return 0;
}