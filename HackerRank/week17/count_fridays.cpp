#include <cstdio>
#define MONTHS 12
using namespace std;

int days[] = {3,0,3,2,3,2,3,3,2,3,2,3};

bool inline leap(int year){
    if(year%4==0){
        if(year%100==0){
            if(year%400==0) return true;
            return false;
        } else {
            return true;
        }
    }
    return false;
}

bool between(int d1,int m1,int y1,int d2,int m2,int y2,int d,int m,int y){
    //d/m/y >= d1/m1/y1
    if(y>y1){
    } else if(y==y1){
        if(m>m1){
        }else if(m==m1){
            if(d>=d1){
            } else {
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }

    if(y<y2){
    }else if(y==y2){
        if(m<m2){
        }else if(m==m2){
            if(d<=d2){
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }

    return true;
}

int count(int d1,int m1,int y1,int d2,int m2,int y2){
    --m1; --m2;
    int d0 = 13, m0 = 0, y0 = 1900;
    int dotw = 5;

    int ans = 0;
    bool is_leap;
    while(y0<10000){
        if(dotw==4 && between(d1,m1,y1,d2,m2,y2,13,m0,y0)){
            ++ans;
        }

        if(m0==1) {
            is_leap = leap(y0);
            if(is_leap) ++days[1];
        }
        dotw = (dotw+days[m0])%7;
        m0 = (++m0)%12;
        if(m0==2 && is_leap) {
            --days[1];
        } else if(m0==0) {
            ++y0;
        }
    }
    return ans;
}

int main(){
    int T;
    int d1,m1,y1,d2,m2,y2;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d %d %d",&d1,&m1,&y1,&d2,&m2,&y2);   
        printf("%d\n", count(d1,m1,y1,d2,m2,y2));
    }
    return 0;
}
