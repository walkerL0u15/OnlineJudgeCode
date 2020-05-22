#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

string a,b,ans="";
char cnt='0';
int as,ap=0,bs;
void check(){
	if(ap>=1&&a[ap-1]>'0')
		return;
	for(int i=0;i<=bs;++i){
		if(a[ap+i]>b[i])
			return;
		else if(a[ap+i]<b[i]){
			ans+=cnt;
			cnt='0';
			ap++;
            while(a[ap+i-1]<='0'&&a[ap+i]<b[i]&&as-ap>=bs){
                ans+='0';
                ap++;
            }
			return;
		}
	}
	return;
}
void sma(){
	for(int i=bs;i>=0;--i){
		if(a[ap+i]>=b[i])
			a[ap+i]+=('0'-b[i]);
		else{
			a[ap+i-1]-=1;
			a[ap+i]+=('0'+10-b[i]);
		}
	}
	return;
}

int main()
{
	cin>>a>>b;
	as=a.size()-1,bs=b.size()-1;
	check();
	while(as-ap>=bs){
		sma();
		cnt+=1;
		check();
	}
    if(ans.size()==1){
        printf("%s\n",ans.c_str());
        return 0;
    }
	for(int i=0;i<ans.size();++i)
        if(ans[i]!='0'){
            for(int j=i;j<ans.size();++j)
                printf("%c",ans[j]);
            puts("");
            return 0;
        }
    return 0;
}
