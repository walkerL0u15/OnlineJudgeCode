#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int count,can;
	string word;
	while(cin>>word){
		can=2;
		for(int i=0;i<word.size();++i){
			if(word[i]>=65&&word[i]<=90)
				word[i]+=32;
			else if(!(word[i]>=97&&word[i]<=122)){
				word.erase(i,1);
				--i;
			}
		}
		while(!word.empty()){
			count=1;
			for(int j=1;j<word.size();j+=1)
				if(word[0]==word[j]){
					++count;
					word.erase(j,1);
					--j;
				}
			word.erase(0,1);
			if(count%2!=0)
				can-=1;
			if(can==0)
				break;
		}
		if(can!=0)
			cout<<"yes !"<<endl;
		else
			cout<<"no..."<<endl;
	}
	return 0;
}
