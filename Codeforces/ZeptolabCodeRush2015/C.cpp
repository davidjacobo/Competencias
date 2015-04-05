#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int lli;

int main(){
    int C,Hr,Hb,Wr,Wb;
    int max_red;
    scanf("%d %d %d %d %d",&C,&Hr,&Hb,&Wr,&Wb);
    if(C/Wb<2000){
        Hr^=Hb;
        Hb^=Hr;
        Hr^=Hb;

        Wb^=Wr;
        Wr^=Wb;
        Wb^=Wr;
        max_red = C;
    } else if(C/Wr<2000) {
        max_red = C;
    } else if((lli)Wb*Hr>(lli)Wr*Hb) {
        Hr^=Hb;
        Hb^=Hr;
        Hr^=Hb;

        Wb^=Wr;
        Wr^=Wb;
        Wb^=Wr;
        max_red = sqrt(C)+1;
        //reducing range, if possible
    } else {
        max_red = sqrt(C)+1;
    }

    if(Wb==Wr){
        //no sense in simulating, use the one who gives more joy
        if(Hr > Hb)
            Hb = Hr;
        printf("%lld\n",(lli)(C/Wb)*Hb);
    } else {
        int y,weight_r=0;
        lli max_joy = 0, joyt, red_sum=0;
        for(int i=0;i<=max_red && weight_r<=C;i++){
            y = (C-weight_r)/Wb;
            joyt = red_sum+(lli)y*Hb;
            //printf("x:%d y:%d joy:%lld\n",i,y,joyt);
            if(joyt > max_joy) max_joy = joyt;

            weight_r+= Wr;
            red_sum+= Hr;
        }
        printf("%lld\n",max_joy);
    }
    return 0;
}
