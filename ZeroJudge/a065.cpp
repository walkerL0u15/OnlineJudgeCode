#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	char word[7];
	while(cin>>word){
		for(int i=1;i<=6;++i){
			if(word[i]-word[i-1]>=0)
				cout<<word[i]-word[i-1];
			else 
				cout<<word[i-1]-word[i];
		}
		cout<<"\n";
	}
}