#include <cstdio>
#include <cstring>
#define MAX_N 100001
#define INF (1<<30)
#define INV -1

using namespace std;

int arr[MAX_N], time[MAX_N];

int main(){
    int N;
    scanf("%d",&N);

    arr[0] = INF;
    for(int i=1;i<=N;++i)   scanf("%d",&arr[i]);

    memset(time, INV, sizeof time);
    time[0] = 0;

    int last0 = INF, lasti = 0;
    int ans = 0;
    for(int i=1;i<=N;++i){
        if(arr[i] <= last0){
            last0 = arr[i];
            lasti = i;
            time[i] = 0;
        } else {
            if(arr[i] > arr[i-1]){
                if(i-1 != lasti){
                    time[i] = time[i-1];
                } else {
                    time[i] = 1;
                }
            } else {
                time[i] = time[i-1]+1;
            }
        }

        ans = (time[i]>ans)?time[i]:ans;
    }
    printf("%d\n",ans);
    return 0;
}
