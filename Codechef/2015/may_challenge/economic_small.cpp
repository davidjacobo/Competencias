#include <iostream>
#include <cstring>
#define MAX_V 21

using namespace std;
bool graph[MAX_V][MAX_V];
int cmp, vec;

bool valid(int mask,int n){
    bool seen[n];
    memset(seen, 0, sizeof(seen));

    for(int i=0;i<n;++i){
        if(mask&(1<<i)){
            ++cmp;
            if(!seen[i]){
                ++vec;
                seen[i] = true;
            }

            for(int j=0;j<n;++j){
                if(graph[i][j] && !seen[j]){
                    seen[j] = true;
                    ++vec;
                }
            }

            for(int j=i+1;j<n;++j){
                if(mask&(1<<j)){
                    if(graph[i][j]) return false;
                }
            }
        }
    }
    return true;
}

int main(){
    int n,m;
    int x,y;
    cin>>n>>m;
    memset(graph, 0, sizeof(graph));

    while(m--){
        cin>>x>>y;
        --x; --y;
        graph[x][y] = graph[y][x] = true;
    }

    int max = 0;
    for(int mask=0;mask<(1<<n);++mask){
        cmp = vec = 0;
        if(valid(mask,n)) {
            vec = cmp - (vec-cmp);
            if(vec > max) max = vec;
        }
    }
    cout<<max<<endl;
    return 0;
}
