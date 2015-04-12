#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX_N 200001
using namespace std;
typedef vector<int> vi;
bool seen[MAX_N];
vi graph[MAX_N];
vector<int> output;

void dfs(int level,int n){
    int size = graph[level].size();
    if(size==0){
        if(level==0) return;
        dfs(max(0,level-3),n);
        return;
    }
    int y = graph[level][size-1];
    graph[level].pop_back();
    output.push_back(y);
    dfs(level+1, n);
}

int main(){
    int n,t;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        graph[t].push_back(i);
    }

    memset(seen, 0, sizeof(seen));
    dfs(0,n);
    if(output.size()!=n) {
        cout<<"Impossible"<<endl;
    } else {
        cout<<"Possible"<<endl;
        for(int i=0;i<n;i++){
            cout<<output[i]<<" ";
        }
    }
    return 0;
}
