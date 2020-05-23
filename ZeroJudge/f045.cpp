#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	string card;
	cin>>card;
	int b[2]={0,0};
	for(int i=0;i<9;++i)
		if(card[i]-'0'>b[1]){
			if(card[i]-'0'>b[0])
				b[1]=b[0],b[0]=card[i]-'0';
			else
				b[1]=card[i]-'0';
		}
	if(b[0]*b[0]+b[1]*b[1]==(card[8]-'0')+(card[7]-'0')*10+(card[6]-'0')*100)
		puts("Good Morning!");
	else
		puts("SPY!");
	return 0;
}
