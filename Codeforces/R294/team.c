#include <stdio.h>

int min(int A,int B){
    return (A<B)?A:B;
}

int max(int A,int B){
    return (A>B)?A:B;
}

int possible_B(int A,int B){
    return min(A/2, B);
}

int possible_A(int A,int B){
    return min(A, B/2);
}

int main(){
    int N,M, maximo = 0;
    scanf("%d %d",&N,&M);

    int teamsA, teamsB;
    for(teamsA = 0; teamsA<=N; teamsA++){
        if( (teamsA<<1) > M) break;
        maximo = max(maximo, teamsA + possible_B(N-teamsA,M-(teamsA<<1)));
    }

    for(teamsB = 0; teamsB<=M; teamsB++){
        if( (teamsB<<1) > N) break;
        maximo = max(maximo, teamsB + possible_A(N-(teamsB<<1), M-teamsB));
    }

    printf("%d\n", maximo);
    return 0;
}
