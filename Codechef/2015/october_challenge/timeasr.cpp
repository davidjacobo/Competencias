#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define INF (1<<30)
#define epsilon (1.0/120.0)

using namespace std;
typedef pair<int,int> ii;
typedef pair<double,ii> dii;
typedef vector<dii> vd;

vd vec;

void build(){
    int hour, minu;
    double m,h,diff;

    vec.push_back(dii(-INF,ii(0,0)));
    for(hour=0;hour<12;++hour){
        m = 0.0;
        h = 30.0*hour;
        for(minu=0;minu<60;++minu){
            diff = max(m,h)-min(m,h);
            diff = min(diff, 360.0-diff);

            vec.push_back(dii(diff,ii(hour,minu)));

            m+= 6.0;
            h+= 0.5;   
        }
    }
    vec.push_back(dii(INF,ii(0,0)));

    sort(vec.begin(), vec.end());
}

void print(int n){
    if(n<10) cout<<"0";
    cout<<n;
}

int main(){
    vector<dii>::iterator init, end;
    int t;
    double a;
    build();
    cin>>t;
    while(t--){
        cin>>a;
        
        init = lower_bound(vec.begin(), vec.end(), dii(a-epsilon,ii(-INF,-INF)));
        end  = upper_bound(vec.begin(), vec.end(), dii(a+epsilon,ii(INF,INF))); 

        for(vector<dii>::iterator it = init;it!=end;++it){
            print(it->second.first);
            cout<<":";
            print(it->second.second);
            cout<<endl;
        }
        
    }
    return 0;
}
