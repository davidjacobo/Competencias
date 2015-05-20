#include <iostream>
#include <vector>
#define MAX_N 101
using namespace std;

int main(){
    vector<int> output;
    int n,x;
    bool flip;
    cin>>n;
    for(int i=0;i<n;++i){
        flip = false;
        for(int j=0;j<n;++j){
            cin>>x;
            if(1==x || 3==x) flip = true;
        }
        if(!flip) output.push_back(i+1);
    }

    cout<<output.size()<<endl;
    if(output.size()>0){
        for(int i=0;i<output.size();++i){
            cout<<output[i]<<" ";
        }
    } else {
        //do nothing
    }
    return 0;
}
