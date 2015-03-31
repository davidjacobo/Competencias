#include <cstdio>
#include <cmath>
#define MAX_N 51
using namespace std;
int counter;

void dfs(int arr[],int i,int root){
    counter+= abs(i-arr[i]);
    if(root==arr[i]) return;
    int t = arr[i];
    arr[i] = i;
    dfs(arr, t, root);
}

int main(){
    int T, N, arr[MAX_N],i;
    scanf("%d",&T);
    while(T--){     
        scanf("%d",&N);
        for(i=1;i<=N;i++)
            scanf("%d",&arr[i]);

        counter = 0;
        for(i=1;i<=N;i++){
            if(arr[i]!=i)
                dfs(arr, arr[i], arr[i]);
        }
        printf("%d\n",counter);
    }
    return 0;
}
