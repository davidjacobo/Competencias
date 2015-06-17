#include <iostream>

using namespace std;
int d1,m1,y1,d0,m0,y0;

int past(){
    if(y0<y1) {
        return 0;
    } else if(y0==y1){
        if(m0<m1) {
            return 0;
        } else if(m0==m1){
            if(d0<=d1) {
                return 0;
            } else {
                return 15*(d0-d1);
            }
        } else {
            return 500*(m0-m1);
        }
    } else {
        return 10000;
    }
}

int main(){
    cin>>d0>>m0>>y0>>d1>>m1>>y1;
    cout<<past()<<endl;
    return 0;
}
