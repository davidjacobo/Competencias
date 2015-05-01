#include <iostream>

using namespace std;

int main(){
    int n,k,p,x,y;
    cin>>n>>k>>p>>x>>y;
    int up, low, t, sum, total;
    up = low = sum = 0;
    for(int i=0;i<k;i++){
        cin>>t;
        sum+= t;
        if(t >= y) up++;
        else low++;
    }

    int test_remaining = n-k;
    int points_available = x - sum;

    total = sum;
    int needed_up = n/2+1-up;
    total+= needed_up*y;

    int needed_low = n-(k+needed_up);
    total+= needed_low;

    if(points_available < test_remaining || needed_up > test_remaining){
        cout<<-1;
        return 0;
    }

    if(y==1 || needed_up<=0){
        if(sum+test_remaining<=x){  
            for(int i=0;i<test_remaining;i++)
                cout<<1<<" ";
        } else {
            cout<<-1;
        }
    } else if(needed_up){
        if(total<=x){
            for(int i=0;i<needed_up;i++)
                cout<<y<<" ";
            for(int i=0;i<needed_low;i++)
                cout<<"1 ";
        } else {
            cout<<-1;
        }
    } else {
        cout<<-1;
    }
    return 0;
}
