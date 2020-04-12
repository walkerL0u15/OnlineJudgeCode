#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	unsigned int word[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
	int total,first,num[8];
	string s;
	while(cin>>s){
		total=word[s[0]-65]%10*9+word[s[0]-65]/10;
		for(int i=1,j=8;i<=8;++i,--j)
			total+=(s[i]-48)*j;
		total+=s[9]-48;
		if(total%10==0)
			cout<< "real\n";
		else
			cout<< "fake\n";
	}
	return 0;
}
