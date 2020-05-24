#include<stdio.h>

int main(){
    int card,t=0,l;
    const int letter[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    int letnum[26];
    for(int i=0;i<26;++i)
        letnum[i]=(letter[i]%10)*9+letter[i]/10;
    scanf(" %d",&card);
    l=card%10,card/=10;
    if(l==0)    l=10;
    for(int i=1;i<=8;++i) 
        t+=(card%10)*i,card/=10;
    for(int i=0;i<26;++i){
        if((10-(t+letnum[i])%10)==l)
            printf("%c",'A'+i);
    }
    puts("");
    return 0;
}
