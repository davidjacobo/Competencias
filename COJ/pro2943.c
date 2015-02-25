#include <stdio.h>
#include <stdlib.h>

int find(int *cmp,int x){
    if(x == cmp[x]) return x;
    return cmp[x] = find(cmp, cmp[x]);
}

void propagate(int *cmp,int *phone,int i,int val){
    //idea: the phone number is somewhere on the tree (component)
    //      this method will put the number on the root of every
    //      tree, so find(cmp, i) will find the phone number
    int cmp_i = find(cmp, i);
    phone[cmp_i] |= val;
}

int main(){
    int N;
    int i,x,y,num;
    int *phone, *cmp, *siz;

    scanf("%d",&N);
    phone = (int *)malloc(sizeof(int)*N);
    cmp = (int *)malloc(sizeof(int)*N);
    siz = (int *)malloc(sizeof(int)*N);

    for(i=0;i<N;i++){
        cmp[i] = i;
        siz[i] = 1;
        scanf("%d",&phone[i]);
    }

    int cmp_x,cmp_y;
    while(scanf("%d %d",&x,&y)!=EOF){
        //if(x==-1 && y==-1) break;
        x--;
        y--;
        cmp_x = find(cmp, x);
        cmp_y = find(cmp, y);

        if(cmp_x != cmp_y){
            if(siz[cmp_x] > siz[cmp_y]){
                siz[cmp_x]+= siz[cmp_y];
                cmp[cmp_y] = cmp_x;
            } else {
                siz[cmp_y]+= siz[cmp_x];
                cmp[cmp_x] = cmp_y;
            }
        }
    }

    for(i=0;i<N;i++)
        propagate(cmp,phone,i,phone[i]);
    for(i=0;i<N;i++)
        printf("%d\n",phone[find(cmp, i)]);
    return 0;
}
