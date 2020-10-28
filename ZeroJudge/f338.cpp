#include<cstdio>

int N,sx,sy,sl,R;
bool dis(int xa,int ya,int xb,int yb){
	int d=(xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
	if(d>R*R)
		return false;
	return true;
}

int main(){
	int ans=0;
	scanf(" %d %d %d %d",&sx,&sy,&sl,&R);
	int sunx,suny,sunl;
	scanf(" %d",&N);
	for(int i=0;i<N;++i){
		scanf(" %d %d %d",&sunx,&suny,&sunl);
		if(sl>=sunl&&dis(sunx,suny,sx,sy))
			++ans;
	}
	printf("%d\n",ans);
	return 0;
}
