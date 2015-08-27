#include <cstdio>
#define MAX_N 31

using namespace std;
int pot[MAX_N], output[MAX_N];

void build(){
    int i = 0;
    pot[i] = 1;
    output[i] = 2;

    for(i=i+1;i<MAX_N;++i){
        pot[i] = ((pot[i-1]+1)<<1)-1;
        output[i] = pot[i]>>1;
        //printf("i:%d pot:%d output:%d\n", i,pot[i],output[i]);
    }
}

int look_for(int n){
    for(int i=0;i<MAX_N;++i){
        if(pot[i]==n) return output[i];
    }
    return -1;
}

int main(){
    build();

    int T,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        printf("%d\n",look_for(N));
    }
    return 0;
}
