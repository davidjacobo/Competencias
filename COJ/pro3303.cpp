#include <cstdio>
#define MAX_N 100001
using namespace std;

int arr[MAX_N];

int main(){
    char line[100];
    int n,q,x,y,num;

    sscanf(gets(line), "%d", &n);
    for(int i=0;i<n;++i) { 
        sscanf(gets(line), "%d", &arr[i+1]);
    }
        
    sscanf(gets(line), "%d", &q);
    while(q--){
        sscanf(gets(line), "%d %d %d", &x,&y,&num);
        int ans = 0;
        for(int i=x;i<=y;++i)
            ans+= (arr[i]%num==0)?1:0;
        printf("%d\n", ans);
    }
    return 0;
}
