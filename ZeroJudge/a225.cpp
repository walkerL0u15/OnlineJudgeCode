#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	while(cin>>N){
		int num[N],first[N];
		for(int i=0;i<N;++i){
			cin>>num[i];
			first[i]=(num[i]<=0?-num[i]:num[i])%10;
		}
		for(int i=1;i<N;++i)
			for(int j=i;j>0;--j){
				if(first[j]<first[j-1]){
					swap(first[j],first[j-1]);
					swap(num[j],num[j-1]);
				}
				else if(first[j]==first[j-1]&&num[j]>num[j-1]){
					swap(first[j],first[j-1]);
					swap(num[j],num[j-1]);
				}
			}
		for(int i=0;i<N;++i)
			cout<<num[i]<<" ";
		cout<<endl;
	}
	return 0;
}