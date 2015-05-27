#include <iostream>
#include <cstring>
using namespace std;

char line[101];
bool limit[101];

int subchains(int len){
    bool used[26];
    memset(limit, false, sizeof limit);
    memset(used, false, sizeof used);
    int ans = 0;
    for(int i=0;i<len;++i){
        int car = line[i]-'a';
        if(!used[car]){
            used[car] = true;
            limit[i] = true;
            ++ans;
        }
    }
    return ans;
}

int main(){
    int k,len;
    cin>>k>>line;
    len = strlen(line);
    int subs = subchains(len);
    if(subs>=k) {
        cout<<"YES"<<endl;
        int ind = 0;
            cout<<line[ind++];
            --k;
            while(ind<len){
                if(limit[ind] && k>0){
                    --k;
                    cout<<endl;
                    cout<<line[ind++];
                } else {
                    cout<<line[ind++];
                }
            }
    } else {
        cout<<"NO"<<endl;
    }
    return 0;
}
