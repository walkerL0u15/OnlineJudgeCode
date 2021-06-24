#include<cstdio>
#include<stack>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define f first
#define s second

stack<P> st;

int main(){
    ll N,a,res=0,cnt;
    scanf(" %lld",&N);
    for(ll i=0;i<N;++i){
        scanf(" %lld",&a);
        cnt=i;
        while(!st.empty()&&st.top().f>=a){
            res=max(res,st.top().f*(i-st.top().s));
            cnt=st.top().s;
            st.pop();
        }
        st.push(make_pair(a,cnt));
    }
    while(st.size()>=2){
        res=max(res,st.top().f*(N-st.top().s));
        st.pop();
    }
    if(!st.empty()){
        res=max(res,st.top().f*N);
    }
    printf("%lld\n",res);
    return 0;
}
