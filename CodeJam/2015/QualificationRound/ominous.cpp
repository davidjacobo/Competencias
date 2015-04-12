#include <cstdio>
#include <algorithm>
using namespace std;

bool richard_wins(int r,int c,int x){
    if(r==1 && c==1) {
        if(x==1) return false;
        return true;
    } else if(r==1 && c==2) {
        if(x<=2) return false;
        return true;
    } else if(r==1 && c==3) {
        if(x==1) return false;
        return true;
    } else if(r==1 && c==4) {
        if(x<=2) return false;
        return true;
    } else if(r==2 && c==2) {
        if(x<=2) return false;
        return true;
    } else if(r==2 && c==3) {
        if(x<=3) return false;
        return true;
    } else if(r==2 && c==4) {
        if(x<=2) return false;
        return true;
    } else if(r==3 && c==3) {
        if(x%2!=0) return false;
        return true;
    } else if(r==3 && c==4) {
        if(x<=4) return false;
        return true;
    } else if(r==4 && c==4) {
        if(x!=3) return false;
        return true;
    }
    return false;
}

int main(){
    int x,r,c,T,counter = 1;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&x,&r,&c);
        if(r>c)  swap(r,c);
        if(richard_wins(r,c,x)) printf("Case #%d: RICHARD\n",counter++);
        else printf("Case #%d: GABRIEL\n",counter++);
    }
    return 0;
}
