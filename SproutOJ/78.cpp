//sprout 78
#include<cstdio>

int gift[10];

int main(){
    bool finish;
    while(true){
        finish=true;
        for(int i=1;i<=6;++i){
            scanf(" %d",&gift[i]);
            if(gift[i]>0) finish=false;
        }
        if(finish) break;
        int ans=0,left1=0,left2=0;
        ans+=gift[6];
        ans+=gift[5],left1=gift[5]*(36-25);
        ans+=gift[4],left2=gift[4]*5;
        ans+=gift[3]/4;
        if(gift[3]%4==1)
            left2+=5,left1+=7,++ans;
        else if(gift[3]%4==2)
            left2+=3,left1+=6,++ans;
        else if(gift[3]%4==3)
            left2+=1,left1+=5,++ans;
        if(left2>=gift[2]){
            left2-=gift[2];
            left1+=left2*4;
        }
        else{
            gift[2]-=left2;
            ans+=gift[2]/9;
            if(gift[2]%9!=0)
                left1+=(9-gift[2]%9)*4,++ans;
        }
        if(left1<gift[1]){
            gift[1]-=left1;
            ans+=gift[1]/36;
            if(gift[1]%36!=0) ++ans;
        }
        printf("%d\n",ans);
    }
}
