#include <queue>
#include <cstdio>
#include <cstring>
#define MAX_N 802
#define INV -1

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> ii_i;
int used[MAX_N];

int main(){
    int n,t;
    memset(used, INV, sizeof used);
    priority_queue<ii_i> pq;
    scanf("%d",&n);
    for(int i=2;i<=(n<<1);++i){
        for(int j=1;j<i;++j){
            scanf("%d",&t);
            pq.push(ii_i(ii(t,i),j));
        }
    }

    while(!pq.empty()){
        ii_i temp = pq.top(); 
        pq.pop();

        if(used[temp.first.second]==INV && used[temp.second]==INV){
            used[temp.first.second] = temp.second;
            used[temp.second] = temp.first.second;
        }
    }

    for(int i=1;i<=(n<<1);++i){
        printf("%d ",used[i]);
    }
    return 0;
}

