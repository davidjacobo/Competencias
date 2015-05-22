#include <iostream>
#include <cstring>
#define MAX_N 6
using namespace std;
int num[MAX_N];
bool win;

int build_options(int state[],int candidates[],int k){
    int cand = 0;
    bool in_perm[5];
    memset(in_perm , false, sizeof(in_perm));

    for(int i=1;i<k;++i) in_perm[state[i]] = true;

    for(int i=0;i<5;++i){
        if(!in_perm[i]) candidates[cand++] = i;
    }
    return cand;
}

bool valid(int state[], int k, int sum){
    if(k==0){
        return valid(state, 1, num[state[2]]*num[state[1]]) |
                valid(state, 1, num[state[2]]+num[state[1]]) | 
                valid(state, 1, num[state[2]]-num[state[1]]);
    } else if(k==4) {
        return sum==23;
    } else {
        ++k;
        return valid(state, k, sum*num[state[k+1]]) |
                valid(state, k, sum+num[state[k+1]]) |
                valid(state, k, sum-num[state[k+1]]);
    }
}

void back(int state[],int k,int n){
    if(k==n){
        if(valid(state, 0, 0)){
            win = true;
        }
    } else {
        ++k;
        int candidates[5];
        int cand = build_options(state, candidates, k);
        for(int i=0;i<cand && !win;++i){
            state[k] = candidates[i];
            back(state, k, n);
        }
    }
}

int main(){
    int sum;
    while(1){
        sum = 0;
        for(int i=0;i<5;++i){
            cin>>num[i];
            sum+= num[i];
        }
        if(sum==0) break;

        int state[MAX_N];
        win = false;
        back(state, 0, 5);

        if(win){
            cout<<"Possible"<<endl;
        } else {
            cout<<"Impossible"<<endl;
        }
    }
    return 0;
}
