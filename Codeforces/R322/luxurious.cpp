#include <iostream>
#include <algorithm>
#define MAX_N 100001

using namespace std;
int nums[MAX_N];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    nums[n] = -1;
    int maximo = -1;

    for(int i=n-1;i>=0;--i){
        if(nums[i] > maximo){
            maximo = nums[i];
            nums[i] = 0;
        }else{
            nums[i] = (maximo-nums[i])+1;
        }
    }

    for(int i=0;i<n;++i){
        cout<<nums[i]<<" ";
    }
    return 0;
}
