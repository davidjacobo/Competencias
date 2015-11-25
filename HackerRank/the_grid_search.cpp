#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool test(const vector<string>& G,int x,int y,const vector<string>& P,int r,int R) {
    for(int i=0;i<r && x+i<R;++i) {
        int pos = G[x+i].find(P[i],y);
        if(pos!=y) return false;
    }
   
    return true;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        
        bool done = false;
        for(int i=0;i<R && !done;++i) {
            int pos = -1;
            while(true) {
                ++pos;
                pos = G[i].find(P[0], pos);
                if(pos==string::npos) break;
                
                if(test(G,i,pos,P,r,R)) {
                    done = true;
                    break;
                }
            }
        }
        
        if(done) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}