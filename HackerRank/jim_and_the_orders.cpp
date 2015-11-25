#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vii orders;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,b,t;
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>b>>t;
        orders.push_back(ii(b+t,i+1));
    }
    
    sort(orders.begin(), orders.end());
    for(auto x:orders) {
        cout<<x.second<<" ";
    }
    return 0;
}