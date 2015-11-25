#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
vi nums, stack;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vi::iterator it;
    int n,t;
    cin>>n;
    nums.push_back(-(1<<30));
    for(int i=0;i<n;++i) {
        cin>>t;
        it = lower_bound(nums.begin() , nums.end(), t);
        if(it==nums.end()) nums.push_back(t);
        else if((*it)!=t) (*it) = t;
    }
    cout<<nums.size()-1<<endl;
    
    return 0;
}
