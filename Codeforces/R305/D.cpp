#include <iostream>
#include <queue>
#define MAX_N 200002
using namespace std;
typedef pair<int,int> ii;
int n, cmp[MAX_N], siz[MAX_N];
priority_queue<ii> pq;

int find(int i){
    if(i==cmp[i]) return i;
    return cmp[i] = find(cmp[i]);
}

void try_join(int val,int i,int k){
    if(siz[k]>0){
        siz[i]+= siz[find(k)];
        cmp[find(k)] = i;
    }
}

int main(){
    cin>>n;
    int t;
    for(int i=1;i<=n;++i){
        cin>>t;
        pq.push(ii(t, i));
    }

    for(int i=0;i<=n+1;++i){
        cmp[i] = i;
        siz[i] = 0;
    }

    int last_size = 0, last_val;
    for(int i=1;i<=n;){
        if(i<=last_size){
            cout<<last_val<<" ";
            ++i;
        } else {
            ii p = pq.top(); pq.pop();
            siz[p.second] = 1;
            //try to join to the left
            try_join(p.first,p.second,p.second-1);
            try_join(p.first,p.second,p.second+1);

            if(siz[p.second] >= i){
                cout<<p.first<<" ";
                ++i;
            }
            last_val = p.first;
            last_size = siz[p.second];
        }
    }
    return 0;
}
