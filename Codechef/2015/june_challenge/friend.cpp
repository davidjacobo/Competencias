#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int T;
    double T1,T2,t1,t2,area, disjoint_area,side;

    scanf("%d",&T);
    while(T--){
        scanf("%lf %lf %lf %lf", &T1, &T2, &t1, &t2);
        if(T1==0 && T2==0){
            printf("1.0\n");
            continue;
        }

        if(t1==0 && t2==0){
            if(T1==0 && T2==0){
                printf("1.0\n");
            } else {
                printf("0.0\n");
            }
            continue;
        }

        if(T1==0 || T2==0){
            printf("0.0\n");
            continue;
        }

        swap(t1,t2);

        area = T1*T2;
        disjoint_area = 0;

        if(T1 < T2){
            swap(T1,T2);
            swap(t1,t2);
        }

        if(t2 >= T2) {
            disjoint_area+= 0.0;
        } else {
            disjoint_area+= (((T2-t2)*(T2-t2))/2.0);
        }

        if(t1>= T1) {
            disjoint_area+= 0.0;
        } else {
            disjoint_area+= (((T1-t1)*(T1-t1))/2.0);
            side = T1 - T2-t1;
            if(side > 0.0)
                disjoint_area-= ((side*side)/2.0);
        }

        printf("%.15lf\n", (area-disjoint_area)/area);
    }

}
