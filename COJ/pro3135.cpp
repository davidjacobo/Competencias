#include <cstdio>
using namespace std;

int last_digit(int N){
    while(N%10==0)
        N/= 10;
    return N % 10;
}

int solve(int N){
    int out = last_digit(N);
    while(N-->1){
        out = last_digit((last_digit(N) * out));
    }
    return out;
}

int main(){
    int T, N;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        printf("%d\n", solve(N));
    }
    return 0;
}
