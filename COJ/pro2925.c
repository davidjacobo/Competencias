#include <stdio.h>
int distances[1000001];

void bfs(int init, int goal){
    int queue[1000001];
    int i, front, back, v;
    
    for(i=0;i<=1000000;i++)
        distances[i] = -1;
    distances[init] = 0;

    front = back = 0;
    queue[back++] = init;
    while(front < back){
        v = queue[front++];
        if(v==goal) break;

        if((v>>1) >= 0 && distances[v>>1]==-1){
            queue[back++] = v>>1;
            distances[v>>1] = distances[v]+1;
        }
        if(v+1<= goal && distances[v+1]==-1){
            queue[back++] = v+1;
            distances[v+1] = distances[v]+1;
        }
    }
}

int main(){
    int T;
    int init,goal;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d",&init,&goal);
        bfs(init,goal);
        printf("%d\n", distances[goal]);
    }
    return 0;
}
