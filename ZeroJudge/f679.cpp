#include<cstdio>

int p[500000+10];

int main(){
    int N,Q,q;
    scanf(" %d %d",&N,&Q);
    for(int i=0;i<N;++i)
        scanf(" %d",&p[i]);
    while(Q--){
        scanf(" %d",&q);
        int l=-1,r=N;
        while(r-l>1){
            int mid=(r+l)/2;
            if(p[mid]>=q)
                r=mid;
            else
                l=mid;
        }
        if(p[r]==q)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
