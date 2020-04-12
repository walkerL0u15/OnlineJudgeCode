#include<iostream>
using namespace std;

int N;
void Find(int counter,int left,int right,string maybe){
	if(counter<0)
		return;
	if(left==0){
		for(int i=1;i<=right;++i)
			maybe+=')';
		cout<<maybe<<"\n";
		return;
	}
	maybe+='(';
	Find(counter+1,left-1,right,maybe);
	maybe[N*2-right-left]=')';
	Find(counter-1,left,right-1,maybe);
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string maybe;
	while(cin>>N){
		Find(0,N,N,maybe);
		cout<<endl;
	}
	return 0;
}