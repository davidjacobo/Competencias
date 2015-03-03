#include <stdio.h>
int distances[20001];
int queue[20001];

void bfs(int n,int m){
    int i, v;
    for(i=0;i<=20000;i++)
        distances[i] = -1;
    distances[n] = 0;
    int index = 0,  last = 1;
    queue[index] = n;
    while(index<last){
        v = queue[index++];
        //printf("index: %d last: %d v: %d\n", index-1, last, v);
        if(v==m) break;
        if(v>0 && distances[v-1]==-1){
            queue[last++] = v-1;
            distances[v-1] = distances[v]+1;
        }
        if(v<m && distances[v<<1]==-1){
            queue[last++] = v<<1;
            distances[v<<1] = distances[v]+1;
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    bfs(n,m);
    printf("%d\n", distances[m]);
    return 0;
}}
