#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int N;
int A[4005],B[4005],C[4005],D[4005];
ll CD[4005*4005];

int main(){
	ll res=0;
	ll ab;
	scanf(" %d",&N);
	for(int i=0;i<N;++i)
		scanf(" %d %d %d %d",&A[i],&B[i],&C[i],&D[i]);
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			CD[i*N+j]=C[i]+D[j];
	sort(CD,CD+N*N);
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j){
			ab=-(A[i]+B[j]);
			res+=upper_bound(CD,CD+N*N,ab)-lower_bound(CD,CD+N*N,ab);
		}
	printf("%lld\n",res);
	return 0;
}
