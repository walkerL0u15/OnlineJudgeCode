#include<iostream>
using namespace std;

int main()
{
	int N,biggest=0,remain=0;
	cin>>N;
	int draw[N],print[N],total[N];
	for(int i=0;i<N;++i){
		cin>>print[i]>>draw[i];
		total[i]=print[i]+draw[i];
		for(int j=i;j>=1;--j)
			if(total[j]>total[j-1]){
				swap(print[j],print[j-1]);
				swap(draw[j],draw[j-1]);
				swap(total[j],total[j-1]);
			}
	}
	for(int i=0;i<N;++i){
		remain+=print[i];
		remain+=draw[i];
		if(remain>biggest)
			biggest=remain;
		remain-=draw[i];
	}
	cout<<biggest;
}