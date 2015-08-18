#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#define INF (1<<30)
#define MAX_N 1000001

using namespace std;

typedef long long ll;
typedef pair<int,ll> ill;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ill> vill;

int siz[MAX_N], cmp[MAX_N];
bool used[MAX_N];
priority_queue<ii> pq;
vill max_nums;

void init_sets(int n){
    for(int i=0;i<n;++i){
        cmp[i] = i;
        siz[i] = 1;
        used[i] = false;
    }
}

int find(int x){
    if(x == cmp[x]) return x;
    return cmp[x] = find(cmp[x]);
}

int union_sets(int x,int y){
    int cmp_x = find(x);
    int cmp_y = find(y);

    int size_y = siz[cmp_y];
    
    if(siz[cmp_x] > siz[cmp_y]) {
        siz[cmp_x]+= siz[cmp_y];
        cmp[cmp_y] = cmp_x;
    } else {
        siz[cmp_y]+= siz[cmp_x];
        cmp[cmp_x] = cmp_y;
    }
    return size_y;
}

int main(){
    int N,M,K;
    int t,x,y,p,q;
    ll Q;
    char condition[5], start_player[5];
    vector<ill>::iterator it;

    scanf("%d %d",&N,&M);
    for(int i=0;i<N;++i){
        scanf("%d",&t);
        pq.push(ii(-t, i));
    }

    init_sets(N);

    max_nums.push_back(ill(0,0));
    while(!pq.empty()){
        x = -pq.top().first;  
        y = pq.top().second;
        pq.pop();

        used[y] = true;
        p = q = 1;
        if(y>0 && used[y-1]) {
            p+= union_sets(y, y-1);
        }
        if(y<N-1 && used[y+1]) {
            q+= union_sets(y, y+1);
        }

        if(max_nums[max_nums.size()-1].first==x) {
            max_nums[max_nums.size()-1].second+= ((ll)p*q);
        } else {
            max_nums.push_back(ill(x, ((ll)p*q)));
        }
    }   

    for(int i=1;i<max_nums.size();++i){
        max_nums[i].second+= max_nums[i-1].second; 
    }
    //all captured and good to go
    //lets solve some queries
    
    for(int i=0;i<M;++i){
        scanf("%s %d %s",condition,&K,start_player);

        if(condition[0]=='='){
            //specific number
            it = lower_bound(max_nums.begin(), max_nums.end(), ill(K,0));
            if((*it).first == K) Q = (*it).second - (*(it-1)).second;
            else Q = 0;
        } else if(condition[0]=='<') {
            //smaller than K
            it = lower_bound(max_nums.begin(), max_nums.end(), ill(K,0));
            --it;
            Q = (*it).second;
        } else {
            it = lower_bound(max_nums.begin(), max_nums.end(), ill(K,0));
            if((*it).first == K) {
                ++it;
            }
            --it;
            Q = max_nums[max_nums.size()-1].second - (*it).second;
        }

        Q = ((Q&1)==0)?0:1;
        if(Q==0) {
            if(start_player[0]=='D') start_player[0] = 'C';
            else start_player[0] = 'D';
        }

        printf("%c",start_player[0]);
    }
    return 0;
}
