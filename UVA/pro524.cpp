#include <cstdio>
#include <cstring>
#define MAX_N 17
using namespace std;
bool is_prime[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};

void print_solution(int state[],int n){
    bool first = true;
    for(int i=1;i<=n;++i){   
        if(!first)
            printf(" ");
        first = false;
        printf("%d",state[i]);
    }
    printf("\n");
}

bool valid(int state[],int n){
    return is_prime[state[1]+state[n]];
}

int build_candidates(int state[],int candidates[],int k,int n){
    bool in_array[n+1];
    memset(in_array, 0, sizeof(in_array));

    for(int i=1;i<k;++i) in_array[state[i]] = true;

    int cand = 0;
    for(int i=1;i<=n;++i){
        if(!in_array[i])
            candidates[cand++] = i;
    }
    return cand;
}

void backtracking(int state[],int k,int n){
    if(k==n){
        if(valid(state, k)){
            print_solution(state, k);
        }
    } else {
        ++k;
        int candidates[n], cand;
        cand = build_candidates(state, candidates, k, n);

        for(int i=0;i<cand;++i){
            state[k] = candidates[i];
            if(k>1) {
                if(!is_prime[candidates[i]+state[k-1]])
                    continue;
            }
            backtracking(state, k, n);
        }
    }
}

int main(){
    int n, state[MAX_N], counter = 0;
    bool first = true;

    while(scanf("%d",&n)!=EOF){
        if(!first) printf("\n");
        first = false;
        printf("Case %d:\n", ++counter);
        state[1] = 1;
        backtracking(state, 1, n);
    }
    return 0;
}
