#include<cstdio>

int main(){
    int need[7],ans,sum;
    int threet[]={0,1,3,5,0};
    int threeo[]={0,5,6,7,0};
    while(true){
        sum=0;
        for(int i=1;i<=6;++i){
            scanf(" %d",&need[i]);
            sum+=need[i];
        }
        if(!sum) break;
        ans=need[6]+need[5]+need[4]+(need[3]+3)/4;
        need[1]-=11*need[5]+threeo[4-need[3]%4];
        need[2]-=5*need[4]+threet[4-need[3]%4];
        if(need[2]>0){
            ans+=(need[2]+8)/9;
            need[2]=(need[2]%9-9);
        }
        need[1]+=need[2]*4;
        if(need[1]>0)
            ans+=(need[1]+35)/36;
        printf("%d\n",ans);
    }
    return 0;
}
