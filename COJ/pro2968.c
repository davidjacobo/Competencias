#include <stdio.h>

int suma_on(int arr[], int n){
    int i, total = 0;
    for(i=0;i<6;i++){
        if(((1<<i)&n) != 0) 
            total+= arr[i];
    }
    return total;
}

int main(){
    int nums[6];
    int N,i,total;
    scanf("%d",&N);
    while(N-->0){
        total = 0;
        for(i=0;i<6;i++) {
            scanf("%d",&nums[i]);
            total+= nums[i];
        }
    
        if(total&1) {
            printf("Tobby no puede cruzar\n");
            continue;
        }

        int win = 0;
        int half = total>>1;
        for(i=0;i<(1<<6) && win==0;i++) {
            if(half == suma_on(nums, i)){
                win = 1;
            }
        }

        if(win) printf("Tobby puede cruzar\n");
        else printf("Tobby no puede cruzar\n");
    }
    return 0;
}
