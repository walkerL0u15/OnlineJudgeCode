#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int min=1000;
	bool f;
	string g="love",g2="Love",s,ss;
	getline(cin,s);
	for(int i=0;i<s.size();++i){
		ss="";
		bool f=true;
		for(int j=i;j<i+4;++j)
			if(!((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')))
				f=false;
		if(!f)
			continue;
		for(int j=i;j<i+4;++j)
			ss+=(s[j]-1);
		for(int j=0;j<26;++j){
			for(int k=0;k<4;++k){
				ss[k]+=1;
				if((ss[k]=='Z'+1)||ss[k]=='z'+1)
					ss[k]-=26;
			}
			if(ss==g||ss==g2){
				if(min>j)
					min=j;
				break;
			}
		}
	}
	printf("%d\n",min);
	return 0;
}
