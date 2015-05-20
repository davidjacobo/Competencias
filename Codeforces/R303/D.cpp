#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100001

using namespace std;
vector<int> vec;

int main(){
    int n,t;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>t;
        vec.push_back(t);
    }

    sort(vec.begin(), vec.end());
    int ans = 0, total = 0;
    for(int i=0;i<n;++i){
        if(total <= vec[i]){
            total+= vec[i];
            ++ans;
        }   
    }
    cout<<ans<<endl;
    return 0;
}
