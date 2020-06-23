#include<stdio.h>
#include<math.h>

int N,K;
double r[10003],lb=0,ub=10000000,mid;
bool cut(double num){
	int total=0;
	for(int i=0;i<N;++i)
		total+=(int)(r[i]/num);
	return total>=K;
}

int main(){
	scanf(" %d %d",&N,&K);
	for(int i=0;i<N;++i)
		scanf(" %lf",&r[i]);
	for(int i=0;i<100;++i){
		mid=(lb+ub)/2;
		if(cut(mid))
			lb=mid;
		else
			ub=mid;
	}
	printf("%.2lf\n",floor(lb*100)/100);
	return 0;
}
