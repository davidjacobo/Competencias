#include <cstdio>

using namespace std;

int main(){
    int T, N;
    int rep, x,y;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        rep = N/4;
        x = y = -(rep<<1);
        rep=N-(rep*4);
        if(rep==3) x-= N--;
        if(rep>=2) y+= N--;
        if(rep>=1) x+= N--;

        printf("%d %d\n",x,y);
    }
}
