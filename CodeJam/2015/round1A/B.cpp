#include <cstdio>
#include <algorithm>
#define MAX_B 1001
#define INF 2000000000
#define TOO_FUCKING_MUCH 1000000000000000

using namespace std;

typedef long long int lli;

int mk[MAX_B];

int calc_atendidos(lli tiempo,int B){
    lli suma = 0;
    for(int i=0;i<B;i++){
        suma+= (tiempo/mk[i])+1;
        //logic: if the mod == 0, then I just started attending another guy
        //if mod != 0, +1 is the same as doing ceil(division)
    }

    return (int)min(suma, (lli)INF);
}

int find_my_turn(int atendidos,lli time,int B,int N){
    N-= atendidos;
    for(int i=0;i<B;i++){
        if(time%mk[i]==0){
            N--;
            if(N==0) {
                return i+1;
            }
        }
    }
    return -1;
}

int solve(int B,int N){
    lli p = 0, q = TOO_FUCKING_MUCH, m;
    int atendidos_t1, atendidos_t2;
    
    while(p<=q){
        m = (p+q)>>1;
        atendidos_t1 = calc_atendidos(m,B);
        atendidos_t2 = calc_atendidos(m+1, B);
        if(atendidos_t1 < N && atendidos_t2 >= N) {
            //printf("right time: %lld\n",m+1);
            return find_my_turn(atendidos_t1, m+1, B, N);
        } else if(atendidos_t1 >= N) {
            q = m-1;
        } else {
            p = m+1;
        }
    }

    return -2;
}

int main(){
    int T,N,B;
    int counter=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&B,&N);
        for(int i=0;i<B;i++)
            scanf("%d",&mk[i]);
        
        printf("Case #%d: ",counter++);
        if(N<=B){
            printf("%d\n", N);
        } else {
            printf("%d\n", solve(B,N));
        }
    }
    return 0;
}
