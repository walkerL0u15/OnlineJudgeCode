//sprout oj
#include<cstdio>
using namespace std;

void divide(int X,int Y,int lx,int rx,int ly,int ry){
    if(lx+1==rx) return;
    int ulx=(lx+rx)/2-1,uly=(ly+ry)/2-1,urx=(lx+rx)/2,ury=(ly+ry)/2-1;
    int dlx=(lx+rx)/2-1,dly=(ly+ry)/2,drx=(lx+rx)/2,dry=(ly+ry)/2;
    if(lx<=X&&(lx+rx)/2>X){
        if(ly<=Y&&(ly+ry)/2>Y){//up left
            Report(urx+1,ury+1,dlx+1,dly+1,drx+1,dry+1);
            divide(urx,ury,(lx+rx)/2,rx,ly,(ly+ry)/2);
            divide(dlx,dly,lx,(lx+rx)/2,(ly+ry)/2,ry);
            divide(drx,dly,(lx+rx)/2,rx,(ly+ry)/2,ry);
            divide(X,Y,lx,(lx+rx)/2,ly,(ly+ry)/2);
        }
        else{//down left
            Report(drx+1,dry+1,urx+1,ury+1,ulx+1,uly+1);
            divide(drx,dly,(lx+rx)/2,rx,(ly+ry)/2,ry);
            divide(urx,ury,(lx+rx)/2,rx,ly,(ly+ry)/2);
            divide(ulx,uly,lx,(lx+rx)/2,ly,(ly+ry)/2);
            divide(X,Y,lx,(lx+rx)/2,(ly+ry)/2,ry);
        }
    }
    else{
        if(ly<=Y&&(ly+ry)/2>Y){//up right
            Report(ulx+1,uly+1,dlx+1,dly+1,drx+1,dry+1);
            divide(drx,dly,(lx+rx)/2,rx,(ly+ry)/2,ry);
            divide(ulx,uly,lx,(lx+rx)/2,ly,(ly+ry)/2);
            divide(dlx,dly,lx,(lx+rx)/2,(ly+ry)/2,ry);
            divide(X,Y,(lx+rx)/2,rx,ly,(ly+ry)/2);
        }
        else{//down right
            Report(urx+1,ury+1,ulx+1,uly+1,dlx+1,dly+1);
            divide(urx,ury,(lx+rx)/2,rx,ly,(ly+ry)/2);
            divide(ulx,uly,lx,(lx+rx)/2,ly,(ly+ry)/2);
            divide(dlx,dly,lx,(lx+rx)/2,(ly+ry)/2,ry);
            divide(X,Y,(lx+rx)/2,rx,(ly+ry)/2,ry);
        }
    }
    return;
}

void solve(int N,int X,int Y){
    divide(X-1,Y-1,0,N,0,N);
}
