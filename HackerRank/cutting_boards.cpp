#include <cmath>
#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
#define VER 1
#define HOR 2
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
priority_queue<ii> pq;

void capture(int n,int side) {
    int t;
    for(int i=0;i<n-1;++i) {
        cin>>t;
        pq.push(ii(t, side));
    }
}

int solve() {
    ll ans = 0;
    ll mul;
    int h_sides = 1, v_sides = 1;
    while(!pq.empty()) {
        ii temp = pq.top();
        int c = temp.first;
        int side = temp.second;
        pq.pop();
        
        if(side==HOR) {
            mul = (ll)v_sides*c;
            ++h_sides;
        } else {
            mul = (ll)h_sides*c;
            ++v_sides;
        }
        
        ans = (ans + mul)%MOD;
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,m,n;
    cin>>t;
    while(t--) {
        cin>>m>>n;
        capture(m,HOR);
        capture(n,VER);
        cout<<solve()<<endl;
    }
    return 0;
}
