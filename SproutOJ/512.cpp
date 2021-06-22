#include<cstdio>
#include<stack>
using namespace std;

int main(){
    int N,a;
    stack<int> s;
    scanf(" %d",&N);
    while(N--){
        scanf(" %d",&a);
        if(a<0&&(s.empty()||(!s.empty()&&s.top()!=-a))){
            printf("lose light light\n");
            return 0;
        }
        if(!s.empty()&&s.top()==-a)
            s.pop();
        else
            s.push(a);
    }
    if(s.empty())
        printf("weed\n");
    else
        printf("lose light light\n");
    return 0;
}
