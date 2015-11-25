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
typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int b;
        int w;
        cin >> b >> w;
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
        int converted_w = x + z;
        int converted_b = y + z;
        x = min(x, converted_b);
        y = min(y, converted_w);
        ll out = 0;
        out = (ll)x*b + (ll)y*w;
        cout<<out<<endl;
    }
    return 0;
}