#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL n;
	cin>>n;
	cout<<floor(log2((long double)n))<<"\n";
	return 0;
}
