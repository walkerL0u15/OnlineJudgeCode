#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,score,sum;
	while(cin>>N){
		sum=0;
		for(int i=0;i<N;++i){
			cin>>score;
			sum+=score;
		}
		cout<<(sum>59*N?"no":"yes")<<endl;
	}
	return 0;
}