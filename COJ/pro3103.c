#include <stdio.h>
int points[] = {10,9,8,7,6,5,4,3,2,1,0};
int distan[] = {20,40,60,80,100,120,140,160,180,200,3000};

void pre_work(){
    int i;
    for(i=0;i<11;i++){  
        distan[i] = distan[i]*distan[i];
    }
}

int fake_binary(int key){
    int i;
    for(i=0;i<12;i++)
        if(distan[i] >= key)
            return i;
    return -1;
}

int main(){
    pre_work();

    int T;
    int N, x, y,total;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        total = 0;
        while(N--){
            scanf("%d %d",&x,&y);
            x*= x;
            y*= y;
            x = fake_binary(x+y);
            total+= points[x];
        }
        printf("%d\n", total);
    }
    return 0;
}
