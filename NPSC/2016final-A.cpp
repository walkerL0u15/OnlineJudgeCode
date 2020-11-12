#include<cstdio>

int N,num;
int dice(int total,int now){
    int ans=0;
    if(total>num)
        return 0;
    else if(now==N+1){
        if(total==num)
            return 1;
        else
            return 0;
    }
    for(int i=1;i<=6;++i)
        ans+=dice(total+i,now+1);
    return ans;
}

int main(){
    scanf(" %d %d",&N,&num);
    printf("%d\n",dice(0,1));
}
