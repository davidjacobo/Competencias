#include <stdio.h>

int is_on(int t,int i){
    t = t&(1<<i);
    return (t)?1:0;
}

void turn_on(int *t,int i){
    *t = (*t)|(1<<i);
}

int main(){
    int out = 0;
    int i= 0, t;
    while(i++<5){
        scanf("%d",&t);
        if(t)   turn_on(&out, i);
    }

    int fuck = 0;
    i=0;
    while(i++<5){
        scanf("%d",&t);
        if(t) {
            if(is_on(out, i))
                fuck = 1;
        } else {
            if(!is_on(out, i))
                fuck = 1;
        }
    }

    if(fuck) printf("N\n");
    else printf("Y\n");

    return 0;
}
