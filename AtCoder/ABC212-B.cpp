#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	char pin[5];
	cin>>pin;
	if(pin[0]==pin[1]&&pin[1]==pin[2]&&pin[2]==pin[3]){
		cout<<"Weak\n";
		return 0;
	}
	for(int i=1;i<=3;++i)
		if(!(pin[i]-pin[i-1]==1||pin[i]-pin[i-1]==-9)){
			cout<<"Strong\n";
			return 0;
		}
	cout<<"Weak\n";
	return 0;
}
