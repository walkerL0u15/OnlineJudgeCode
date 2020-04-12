#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string word;
	bool que;
	while(cin>>word){
		que=true;
		for(int i=0;i<=word.size()/2;++i)
			if(word[i]!=word[word.size()-i-1]){
				cout<<"no\n";
				que=false;
				break;
			}
		if(que==true)
			cout<<"yes\n";
		}
}