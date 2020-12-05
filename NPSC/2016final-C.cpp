#include<cstdio>
#include<string>
using namespace std;

int main(){
	string s,ans(305,'z');
	{
		char a[305];
		scanf(" %s",a);
		s=a;
	}
	int cnt=s.size()/4;
	bool find=false;
	for(int l=cnt;l>=1;--l){
		for(int i=0;i+l*4-1<s.size();++i){
			int dif=false;
			for(int j=i;j<=i+l -1;++j)
				if(s[j]!=s[j+l]||s[j]!=s[j+3*l]){
					dif=true;break;
				}
			if(!dif){
				string maybe(305,'\0');
				for(int j=0;j<l*4;++j)
					maybe[j]=s[i+j];
				find=true;
				if(maybe<ans) ans=maybe;
			}
		}
		if(find){
			printf("%s\n",ans.c_str());
			return 0;
		}
	}
	printf("===>{*}(*)<===\n");
	return 0;
}