#include <iostream>
#include <cmath>
#define MAX_N 1000
using namespace std;
int timeIncrease[MAX_N], timeDecrease[MAX_N];

int main(){
    int v1,v2;
    int t,d;
    cin>>v1>>v2>>t>>d;
    timeIncrease[0] = v1;
    for(int i=1;i<t;i++){
        timeIncrease[i] = timeIncrease[i-1]+d;
    }

    timeDecrease[t-1] = v2;
    for(int i=t-2;i>=0;i--){
        timeDecrease[i] = timeDecrease[i+1]+d;
    }

    int ans = 0;
    for(int i=t-1;i>=0;i--){
        if(timeIncrease[i] >= timeDecrease[i])
            ans+= timeDecrease[i];
        else
            ans+= timeIncrease[i];
    }
    cout<<ans<<endl;
    
    
    return 0;
}
