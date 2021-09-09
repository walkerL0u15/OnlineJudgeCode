#include<bits/stdc++.h>
using namespace std;

int a[(int)2e5+10];
priority_queue<int,vector<int>,greater<int> > pq;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int Q,cmd,head=0,tail=0;//[head,tail)
	cin>>Q;
	while(Q--){
		cin>>cmd;
		if(cmd==1)
			cin>>a[tail++];
		else if(cmd==2){
			if(!pq.empty()){
				cout<<pq.top()<<"\n";
				pq.pop();
			}
			else
				cout<<a[head++]<<"\n";
		}
		else{
			while(head<tail)
				pq.push(a[head++]);
		}
	}
	return 0;
}
