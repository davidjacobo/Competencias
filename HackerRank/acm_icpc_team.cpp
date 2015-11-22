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

int union_count(const string& a,const string& b) {
    int len = a.size();
    int ans = 0;
    for(int i=0;i<len;++i) {
        if(a[i]=='1' || b[i]=='1') ++ans;
    }
    return ans;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }
    
    int max_topics = 0;
    int counter = 0;
    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) {
            int top = union_count(topic[i],topic[j]);
            if(top > max_topics) {
                max_topics = top;
                counter = 1;
            } else if(top == max_topics) {
                ++counter;
            }
        }
    }
    
    cout<<max_topics<<endl<<counter<<endl;
    return 0;
}