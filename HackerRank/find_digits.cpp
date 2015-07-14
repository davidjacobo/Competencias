#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAX_N 12
using namespace std;
typedef long long ll;

int main(){
    ll N;
    char line[MAX_N];
    int T, len, counter;
    cin>>T;
    while(T--){
        cin>>line;
        N = atoi(line);
        len = strlen(line);

        counter = 0;
        for(int i=0;i<len;++i){
            if(line[i]=='0') continue;
            else if(N%(line[i]-'0')==0) ++counter;
        }

        cout<<counter<<endl;
    }
    return 0;
}
