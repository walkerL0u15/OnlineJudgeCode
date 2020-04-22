#include<iostream>
using namespace std;

int main(){
	int h1,h2,m1,m2,s,e,ans;
	scanf(" %d %d %d %d",&h1,&m1,&h2,&m2);
	s=h1*60+m1;
	e=h2*60+m2;
	ans=e-s;
	if(ans<0){
		ans=1440+ans;
	}
	int h=ans/60,m=ans%60;
	printf("%d %d\n",h,m);
	return 0;
}
