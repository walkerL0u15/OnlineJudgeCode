#include<iostream>
using namespace std;

int main()
{
	int N,ans,counter;
	string street;
	street.resize(10000000);
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		counter=0;
		ans=0;
		scanf("%s",&street[0]);
		for(int j=0;j<street.size();++j){
			if(street[j]=='p')
				++counter;
			else if(street[j]=='q'&&counter>0){
				--counter;
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}