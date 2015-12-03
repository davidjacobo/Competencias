#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool try_delete(int arr[],int i) {
    --arr[i];
    int min_val = (1<<30), max_val = -1;
    for(int i=0;i<26;++i) {
        if(arr[i] > 0) {
            min_val = min(min_val, arr[i]);
            max_val = max(max_val, arr[i]);
        }
    }
    ++arr[i];
    
    return min_val==max_val;
}

void solve(const string& input) {
    int counter[26];
    fill(counter, counter+26, 0);
    int len = input.size();
    if(len==1) {
        //cheap shot
        cout<<"YES"<<endl;
        return;
    }
    
    for(int i=0;i<len;++i) {
        char car = input[i];
        ++counter[car-'a'];
    }
    
    for(int i=0;i<26;++i) {
        if(try_delete(counter, i)) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string input;
    cin>>input;
    solve(input);
    return 0;
}
