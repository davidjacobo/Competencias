#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
vi arr[3], input;

void build() {
    arr[0].push_back(0);
    arr[0].push_back(1);
    arr[0].push_back(2);
    arr[0].push_back(3);
    
    arr[1].push_back(0);
    arr[1].push_back(1);
    arr[1].push_back(5);
    
    arr[2].push_back(0);
    arr[2].push_back(3);
    arr[2].push_back(4);
}

bool test(int index,int add) {
    input[index]+= add;
    
    bool fail = false;
    for(int i=0;i<3;++i) {
        int sum = 0;
        for(int j=0;j<arr[i].size();++j) {
            sum+= input[arr[i][j]];
        }
        
        if(sum < 0) fail|= true;
    }
    
    input[index]-= add;
    return fail;
}

int main() {
    int t;
    for(int i=0;i<6;++i) {
        cin>>t;
        input.push_back(t);
    }
    build();
    
    if(!test(0,0)) {
        cout<<0<<endl;
    } else {
        int min_add = (1<<30);
        for(int i=0;i<6;++i) {
            for(int j=0;j<1000;++j) {
                bool out = test(i, j);
                if(!out && j < min_add) min_add = j;
            }
        }
        
        if(min_add==(1<<30)) {
            cout<<-1<<endl;
        } else {
            cout<<min_add<<endl;
        }
    }
    return 0;
}
