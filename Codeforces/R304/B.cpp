#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> vec;
    int n, t;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>t;
        vec.push_back(t);
    }

    int ans = 0;
    sort(vec.begin(), vec.end());
    int last = 0;
    for(int i=0;i<n;++i){
        t = vec[i];
        if(last<t){
            last = vec[i];
            continue;
        }   

        ans+= abs(last+1-vec[i]);
        ++last;
    }
    cout<<ans<<endl;
    return 0;
}
