#include <stdio.h>
int used[102];
int nums[102];

int main(){
    int W, P;
    int i,j;
    scanf("%d %d",&W, &P);
    nums[0] = 0;
    for(i=1;i<=P;i++)
        scanf("%d", &nums[i]);
    nums[++P] = W;

    for(i=0;i<=100;i++)
        used[i] = 0;

    for(i=1;i<=P;i++)
        for(j=0;j<i;j++){
            //printf("%d - %d = %d\n",nums[i],nums[j],nums[i]-nums[j]);
            used[nums[i]-nums[j]]++;
        }

    int first = 1;
    for(i=0;i<=W;i++){
        if(used[i]){
            if(!first) printf(" ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
    
    return 0;
}
