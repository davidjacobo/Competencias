#include <iostream>
#include <cstring>
#define INV -1
#define MAX_N 1000001

using namespace std;
typedef long long ll;
ll m,x1,x2,y1,y2,h1,h2,a1,a2;
int time1[MAX_N], time2[MAX_N];

int main(){
    cin>>m;
    cin>>h1>>a1;
    cin>>x1>>y1;
    cin>>h2>>a2;
    cin>>x2>>y2;

    memset(time1, INV, sizeof time1);
    memset(time2, INV, sizeof time2);

    bool done = false;
    int time = 0, cycle1 = INV, cycle2 = INV, seen1 = 0, seen2 = 0;

    while(!done && time++<=(MAX_N<<1)){
        h1 = (h1*x1+y1)%m;
        h2 = (h2*x2+y2)%m;

        if(h1==a1) ++seen1;
        if(h2==a2) ++seen2;

        if(h1==a1 && h2==a2){
            done = true;
            break;
        }

        if(time1[h1]==INV)  time1[h1] = time;
        else if(cycle1==INV) cycle1 = time - time1[h1];

        if(time2[h2]==INV)  time2[h2] = time;
        else if(cycle2==INV) cycle2 = time - time2[h2];
    }

    if(done){
        cout<<time<<endl;
    } else if(time1[a1]!=INV && time2[a2]!=INV && seen1>1 && seen2>1) {
        h2 = time2[a2];
        h1 = time1[a1];
        ll k1, k2, ans = INV;

        if(cycle2 > cycle1){
            for(k2=0;k2<20000000;++k2){
                if((h2-h1+k2*cycle2)%cycle1==0){
                    ans = h2 + k2*cycle2;
                    break;
                }
            }
        } else {
            for(k1=0;k1<20000000;++k1){
                if((h1-h2+k1*cycle1)%cycle2==0){
                    ans = h1 + k1*cycle1;
                    break;
                }
            }
        }

        cout<<ans<<endl;
    } else {
        cout<<-1<<endl;
    }
    return 0;
}
