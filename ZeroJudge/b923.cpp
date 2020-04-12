#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int a,c;
	stack<int> b;
	cin>>a;
	for(int i=0;i<a;++i){
		cin>>c;
		if(c==1)
			b.pop();
		else if(c==2)
			cout<< b.top()<<"\n";
		else{
			cin>>c;
			b.push(c);
		}
	}
	return 0;
}