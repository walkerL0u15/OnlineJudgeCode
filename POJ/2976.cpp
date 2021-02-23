#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
#define a first
#define b second

int N,k;
double y[1005];
pair<double,double> num[1005];
bool C(double x){
	for(int i=0;i<N;++i) y[i]=100.0*num[i].a-x*num[i].b;
	sort(y,y+N);
	double res=0;
	for(int i=N-1;i>=k;--i)
		res+=y[i];
	return res>=0;
}

int main(){
	while(scanf(" %d %d",&N,&k)==2&&N!=0){
		for(int i=0;i<N;++i) scanf(" %lf",&num[i].a);
		for(int i=0;i<N;++i) scanf(" %lf",&num[i].b);
		double l=0,r=0x3f3f3f3f*1.0;
		for(int i=0;i<100;++i){
			double mid=(l+r)/2;
			if(C(mid))
				l=mid;
			else
				r=mid;
		}
		printf("%d\n",(int)(l+0.5));
	}
	return 0;
}
