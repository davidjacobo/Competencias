#include <cstdio>
using namespace std;
typedef long long int lli;

lli joy(int Hr, int x,int Hb,int y){
    return (lli)Hr*x+(lli)Hb*y;
}

lli weight(int Wr,int x,int Wb,int y){
    return (lli)(Wr*x+Wb*y);
}

int x_y(int x,int Wr,int C,int Wb){
    lli total = (lli)x*Wr;
    if(total > C) return -1;
    return (int)((C-total)/Wb);
}

int main(){
    int C,Hr,Hb,Wr,Wb;
    scanf("%d %d %d %d %d",&C,&Hr,&Hb,&Wr,&Wb);
    if(Wb>Wr){
        Hr^=Hb;
        Hb^=Hr;
        Hr^=Hb;

        Wb^=Wr;
        Wr^=Wb;
        Wb^=Wr;
        //reducing range, if possible
    }

    if(Wb==Wr){
        //no sense in simulating, use the one who gives more joy
        if(Hr > Hb)
            Hb = Hr;
        printf("%lld\n",(lli)(C/Wb)*Hb);
    } else {
        int x,y;
        lli max_joy = 0, joyt;
        for(int i=0;i<=C;i++){
            x = i;
            y = x_y(x,Wr,C,Wb);
            if(y<0) break;
            joyt = joy(Hr,x,Hb,y);
            printf("x:%d y:%d joy:%lld\n",x,y,joyt);
            if(joyt > max_joy) max_joy = joyt;
        }
        printf("%lld\n",max_joy);
    }
    return 0;
}
