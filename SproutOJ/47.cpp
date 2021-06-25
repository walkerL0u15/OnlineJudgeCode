//sprout 47
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;

set<int> s_up,s_down;

int main(){
    int N,num,u,d;
    char cmd[10];
    scanf(" %d",&N);
    while(N--){
        scanf(" %s %d",cmd,&num);
        if(cmd[0]=='i'){
            s_up.insert(num);
            s_down.insert(-num);
        }
        else if(cmd[0]=='d'){
            s_up.erase(num);
            s_down.erase(-num);
        }
        else{
            u=*s_up.lower_bound(num);
            d=-(*s_down.lower_bound(-num));
            if(abs(u-num)==abs(d-num)){
                if(u==d)
                    printf("%d\n",u);
                else
                    printf("%d %d\n",d,u);
            }
            else if(abs(u-num)>abs(d-num))
                printf("%d\n",d);
            else
                printf("%d\n",u);
        }
    }
    return 0;
}
