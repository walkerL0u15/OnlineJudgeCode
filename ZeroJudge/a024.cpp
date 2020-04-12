#include<iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b;
	while(cin>>a>>b){
		while(a/b==0||b/a==0){
			while(a>b)
				a-=b;
			while(b>a)
				b-=a;
		}
		cout<<((a>b)?b:a)<<"\n";
	}
	return 0;
}