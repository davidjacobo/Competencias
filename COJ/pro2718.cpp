#include <cstdio>
using namespace std;
int main(){
    int h,m,x,y;
    scanf("%d:%d",&h,&m);
    x = h*60+m + 24*60;
    scanf("%d:%d",&h,&m);
    y = h*60+m;
    x-= y;
    printf("%02d:%02d\n",(x/60)%24,x%60);
    return 0;
}
