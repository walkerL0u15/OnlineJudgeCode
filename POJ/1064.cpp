#include<cstdio>
#include<cmath>

int N,K;
double line[10005];
bool C(double num){
	int res=0;
	for(int i=0;i<N;++i)
		res+=line[i]/num;
	return res>=K;
}

int main(){
	scanf(" %d %d",&N,&K);
	for(int i=0;i<N;++i)
		scanf(" %lf",&line[i]);
	double lb=0,ub=200000;
	for(int i=0;i<100;++i){
		double mid=(lb+ub)/2;
		if(C(mid))
			lb=mid;
		else
			ub=mid;
	}
	printf("%.2lf\n",floor(lb*100)/100);
	return 0;
}
