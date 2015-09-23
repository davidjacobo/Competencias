#include <cstdio>
#include <algorithm>
#define MAX_N 100001
using namespace std;
int nums[MAX_N];

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&nums[i]);
    }

    int last = nums[0];
    int ans = 1;
    int counter = 1;
    for(int i=1;i<N;++i){
        if(nums[i]>= last){
            ++counter;
            ans = max(ans, counter);
        }else{
            counter = 1;
        }
        last = nums[i];
    }

    printf("%d\n",ans);
    return 0;
}
