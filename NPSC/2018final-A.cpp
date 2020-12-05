#include<cstdio>

int main(){
	int T;
	int h,m;
	scanf(" %d",&T);
	while(T--){
		scanf(" %d %d",&h,&m);
		if(m>=30){
			m-=30;
			h+=1;
			if(h==24) h=0;
		}
		else
			m+=30;
		printf("%d %d\n",h,m);
	}
	return 0;
}