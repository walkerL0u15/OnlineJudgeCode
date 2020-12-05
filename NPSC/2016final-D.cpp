#include<cstdio>

int main(){
	int N,A,B;
	int time[1000005];
	scanf(" %d",&N);
	for(int i=1;i<=N;++i)
		scanf(" %d",&time[i]);
	scanf(" %d %d",&A,&B);
	int low=A,high=A,wl=A-1,wh=A;
	long long cnt=0;
	while(true){
		if(wl==time[cnt%N+1]){
			wl-=1;low-=1;
			if(wl==0) wl=N;
			if(low==0) low=N;
		}
		if(wh==time[cnt%N+1]){
			wh+=1;high+=1;
			if(wh==N+1) wh=1;
			if(high==N+1) high=1;
		}
		if(high==B||low==B) break;
		++cnt;
	}
	printf("%lld\n",cnt+1);
	return 0;
}