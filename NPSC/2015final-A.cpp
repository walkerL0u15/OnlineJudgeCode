#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int T;
    scanf(" %d",&T);
    int num[6];
    while(T--){
        for(int i=0;i<6;++i)
            scanf(" %d",&num[i]);
        sort(num,num+6);
        bool f=false;
        for(int i=0;i<6;++i)
            for(int j=i+1;j<6;++j)
                for(int k=j+1;k<6;++k){
                    if(f) break;
                    if(num[i]+num[j]<=num[k]) continue;
                    int cnt=0,sum=0;
                    for(int l=0;l<6;++l)
                        if(l!=i&&l!=j&&l!=k){
                            if(cnt==2&&num[l]-sum<0) f=true;
                            else
                                sum+=num[l],++cnt;
                        }
                }
        if(f) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}