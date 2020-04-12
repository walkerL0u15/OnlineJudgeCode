#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int counter=1,num[10001];
	while(cin>>num[counter]){
		for(int i=counter-1;i>=1;--i)
			if((num[counter]>=num[i]&&counter!=2)||(i==1&&num[counter]<num[i])){
				for(int j=i+1;j<=counter;++j)
					swap(num[(i==1)?i:(i+1)],num[j]);
				break;
			}
		cout<<((counter%2==0)?(num[counter/2]+num[counter/2+1])/2:num[counter/2+1])<<"\n";
		++counter;
	}
	return 0;
}