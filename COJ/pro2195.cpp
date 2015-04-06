#include <cstdio>
#include <algorithm>
#define MAX_N 100005
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
int nums[MAX_N];
int p,q;
ii stack[MAX_N];

void print_stack(){
    for(int i=p;i<=q;i++){
        printf("%d %d - ",stack[i].first,stack[i].second);
    }
    printf("\n");
}

int do_stack_shit(int N){
    int h = nums[N], m;
    int low = p,up = q;

    while(low<=up){
        m = (low+up)/2;
        if(stack[m].first==h){
            //same height, update the index and return m+1
            stack[m].second = N;
            //replace dummy
            stack[m-1].first = -INF;
            stack[m-1].second = -1;
            //erase previous shit
            p = m-1;
            return stack[m+1].second;
        } else if(stack[m].first<h && stack[m+1].first>h){
            //found my position at m
            stack[m].first = h;
            stack[m].second = N;
            //replace the dummy
            stack[m-1].first = -INF;
            stack[m-1].second = -1;
            //erase all < m-1
            p = m-1;
            return stack[m+1].second;
        } else if(stack[m].first > h){
            up = m-1;
        } else {
            low = m+1;
        }
    }

    //some weirdo shit happened, error
    return -1;
}

void solve(int N){
    if(N<=0) return;
    int t = do_stack_shit(N);
    solve(--N);
    printf("%d\n",(-1==t)?0:t);
}

void init_stack(){
    q = MAX_N-1;
    stack[q] = ii(INF,-1);
    p = q-1;
    stack[p] = ii(-INF,-1);
}

int main(){
    int N;
    scanf("%d",&N);
    init_stack();

    for(int i=1;i<=N;i++)
        scanf("%d",&nums[i]);

    solve(N);
    return 0;
}
