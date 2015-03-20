#include <iostream>
#include <vector>
#include <cstdio>
#define MAX_SIZE 201
#define NOT_SEEN -1
#define WHITE 0
#define BLACK 1
using namespace std;
typedef vector<int> vi;
vi graph[MAX_SIZE];
int color[MAX_SIZE];
bool bad_cicle;

void dfs(int v){
    if(bad_cicle) return;

    for(int i=0;i<graph[v].size();i++){
        int y = graph[v][i];
        if(color[y]==NOT_SEEN){
            color[y] = 1-color[v];   //trick for 2 states :)
            dfs(y);
        } else if(color[y] == color[v]){
            bad_cicle = true;
            return;
        }
    }
}

int main(){
    int v,e,x,y;
    while(scanf("%d",&v)){
        if(v==0) break;
        for(int i=0;i<v;i++){
            graph[i].clear();
            color[i] = NOT_SEEN;
        }

        scanf("%d", &e);
        while(e--){
            scanf("%d %d",&x,&y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        bad_cicle = false;
        dfs(0);

        printf("%s\n", (bad_cicle)?"NOT BICOLORABLE.":"BICOLORABLE.");
    }
    return 0;
}
