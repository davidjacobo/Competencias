#include <stdio.h>
#include <algorithm>

using namespace std;

void swap(int *p,int i,int j){
    p[i]^= p[j];
    p[j]^= p[i];
    p[i]^= p[j];
}

int find_nonzero(int nums[],int i,int n){
    int j;
    for(j=i;j<n;j++){
        if(nums[j]!=0) 
            return j;
    }
    return -1;
}

int main(){
    int nums[15];
    int N, i, total, base, t;
    while(1){
        scanf("%d", &N);
        if(N==0) break;

        for(i=0;i<N;i++){
            scanf("%d", &nums[i]);
        }

        sort(nums, nums+N);
        if(!nums[0]){
            t = find_nonzero(nums, 0, N);
            swap(nums,0,t);
        }
        if(!nums[1]){
            t = find_nonzero(nums, 1, N);
            swap(nums, 1, t);
        }

        base = 1;
        total = 0;
        for(i=N-1;i>=0;i-=2){
            if(i-1>=0)
                total+= base*(nums[i]+nums[i-1]);
            else 
                total+= base*nums[i];
            base*= 10;
        }

        printf("%d\n",total);
    }
    return 0;
}
