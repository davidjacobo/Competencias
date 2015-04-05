#include <cstdio>
#define MAX_N 4096
using namespace std;
int heap[MAX_N];
int sums[MAX_N];
bool can_touch[MAX_N];
int max_sons;

void dfs_to_root(int v,int sum){
    if(v<=1){
        if(sum>max_sons)
            max_sons = sum;
        return;
    } else {
        sum+= heap[v];
        dfs_to_root(v>>1,sum);
    }
}

void dfs(int v,int N){
    int y = v<<1;
    if(y>N){
        dfs_to_root(v>>1,heap[v]);
    } else {
        dfs(v<<1,N);
        dfs((v<<1)+1,N);
    }
}

int main(){
    int N;
    scanf("%d",&N);
    heap[0] = heap[1] = -1;
    for(int i=2;i<(2<<N);i++)
        scanf("%d",&heap[i]);
    
    int branch;
    int max_branch = 0;
    for(int i=(2<<N)-1;i>=(1<<N);i--){
        //printf("working on %d\n",i);
        branch = 0;
        int j = i;
        while(j>1){
            branch+= heap[j];
            j>>=1;
        }
        
        sums[i] = branch;
        if(branch > max_branch)
            max_branch = branch;
    }

    can_touch[0] = can_touch[1] = false;
    for(int i=2;i<=(2<<N)-1;i++)
        can_touch[i] = true;    

    for(int i=(2<<N)-1;i>=(1<<N);i--)
        if(sums[i]==max_branch){
            int j=i;
            while(j>1){
                can_touch[j] = false;
                j>>=1;
            }
        }

    //solo los que can_touch[i] = true pueden agregarse lamparas [0, max_branch], binariamente
    int output = 0;
    for(int i=2;i<(2<<N);i++){
        if(can_touch[i]){
            max_sons = 0;
            dfs(i,(2<<N)-1);
            heap[i]+= max_branch-max_sons;
            output+= max_branch-max_sons;
        }
    }

    printf("%d\n",output);
    return 0;
}
