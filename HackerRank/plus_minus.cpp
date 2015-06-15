#include <cstdio>

using namespace std;

int main(){
    int N,t, pos, neg, zer;
    scanf("%d",&N);
    pos = neg = zer = 0;

    for(int i=0;i<N;++i){
        scanf("%d",&t);
        if(t==0) {
            zer++;
        } else if(t > 0){
            pos++;
        } else {
            neg++;
        }
    }

    printf("%.3lf\n",(double)pos/N);
    printf("%.3lf\n",(double)neg/N);
    printf("%.3lf\n",(double)zer/N);
    return 0;
}
