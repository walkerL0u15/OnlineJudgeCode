#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    char c;
    int cnt;
    string s;
    while(cin>>s){
        cnt=0;
        for(int i=0;i<s.size();){
            c=s[i];
            while(s[i]==c&&i<s.size())
                ++cnt,++i;
            if(cnt==2)
                printf("%c",c);
            else if(cnt!=1)
                printf("%d",cnt);
            printf("%c",c);
            cnt=0;
        }
        printf("\n");
    }
    return 0;
}
