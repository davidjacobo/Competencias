#include <cstdio>
#include <cstring>
#define MAX_N 1001
#define MOD 1000000000
using namespace std;
int nuevo[3], viejo[3];

int main(){
    int N, t, x;
    memset(nuevo, 0, sizeof(nuevo));
    memset(viejo, 0, sizeof(viejo));

    viejo[0] = 1;
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d",&t);
        t = t%3;
        for(int j=0;j<3;j++) nuevo[j] = viejo[j];
        for(int j=0;j<3;j++) {
            if(viejo[j]) {
                x = (j + t)%3;
                nuevo[x]= (nuevo[x] + viejo[j]) % MOD;
            }
        }
        for(int j=0;j<3;j++) viejo[j] = nuevo[j];
    }

    printf("%d\n", nuevo[0]-1);
    return 0;
}
