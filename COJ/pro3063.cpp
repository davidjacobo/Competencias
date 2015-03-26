#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAX_N 1001
using namespace std;
int arr[MAX_N];

int main(){
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);
    sort(arr, arr+N);
    arr[N] = arr[0];
    
    int t1,t2;
    t1 = t2 = 0;
    for(i=0;i<N;i+=2){
        t1+= min(abs(arr[i]-arr[i+1]), 24-abs(arr[i]-arr[i+1]));
        t2+= min(abs(arr[i+1]-arr[i+2]), 24-abs(arr[i+1]-arr[i+2]));
    }

    printf("%d\n", min(t1,t2));
    
    return 0;
}
