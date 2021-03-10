#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    char s[3],t[3];
    scanf(" %s %s",s,t);
    printf("%d\n",max(abs(s[0]-t[0]),abs(s[1]-t[1])));
    while(!(s[0]==t[0]&&s[1]==t[1])){
        if(t[0]>s[0]){
            ++s[0];
            printf("R");
        }
        else if(t[0]<s[0]){
            --s[0];
            printf("L");
        }
        if(t[1]>s[1]){
            ++s[1];
            printf("U");
        }
        else if(t[1]<s[1]){
            --s[1];
            printf("D");
        }
        printf("\n");
    }
    return 0;
}
