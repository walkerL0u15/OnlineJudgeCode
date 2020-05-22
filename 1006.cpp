#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

string a,b,ans="";
char cnt='0';
int as,ap=0,bs;
void check(){
	if(a[ap-1]>'0')
		return;
	for(int i=0;i<bs;++i){
		if(a[ap+i]>b[i])
			return;
		else if(a[ap+i]<b[i]){
			ans+=cnt;
			cnt='0';
			ap++;
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
		cout<<a<<endl;
	}
	return;
}

int main()
{
	cin>>a>>b;
	as=a.size(),bs=b.size();
	check();
	while(as-ap>=bs){
		sma();
		cnt+=1;
		check();
	}
	printf("%s\n",ans.c_str());
}
