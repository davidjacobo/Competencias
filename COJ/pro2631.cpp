#include <cstdio>
#include <cstring>
#define MAX_N 9
using namespace std;
int counter;

int fact(int n){
    if(1>=n) return 1;
    return n*fact(n-1);
}

void back(int arr[],int k,int n,int target){
    if(k==n) {
        counter++;
        if(counter==target){
            for(int i=1;i<=n;i++)
                printf("%d",arr[i]);
            printf("\n");
        }
        return;
    } else {
        k++;
        bool used[n+1];
        memset(used, 0, (n+1)*sizeof(bool));
        for(int i=1;i<k;i++)
            used[arr[i]] = true;

        for(int i=1;i<=n && counter<target;i++){
            if(used[i]) continue;
            arr[k] = i;
            back(arr,k,n,target);
        }
    }
}

int main(){
    int T, n,target, arr[MAX_N];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        target = fact(n)/3+1;

        counter = 0;
        back(arr, 0, n, target);
    }
    return 0;
}
