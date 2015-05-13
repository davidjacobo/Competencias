#include <iostream>
#include <cstring>
#define MAX_N 100001

using namespace std;
char line[MAX_N];

char flip(char car){
    if(car=='0') return '1';
    return '0';
}

int start(char car,int len){
    int ans = 0;
    for(int i=0;i<len;++i){
        if(line[i]!=car) ++ans;
        car = flip(car);
    }   
    return ans;
}

void transform(char car,int len){
    for(int i=0;i<len;++i){
        if(line[i]!=car) line[i] = car;
        car = flip(car);
    }
}

void transform(int K,int len){
    char car;
    int j, seq, needed_flips;
    int ans = 0;

    for(int i=0;i<len;++i){
        j = i+1;
        while(j<len && line[j]==line[i])    ++j;
        seq = j-i;
        --j;

        if(seq > K){
            needed_flips = seq/(K+1);
            ans+= needed_flips;

            if(needed_flips==1) {
                line[i+seq/2] = flip(line[i+seq/2]);
            } else {
                for(int t=i+K;t<j;t+=(K+1)){
                    --needed_flips;
                    line[t] = flip(line[t]);
                }

                if(needed_flips)
                    line[j-1] = flip(line[j-1]);
            }       
            i = j;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int T, N, K;
    cin>>T;
    while(T--){
        cin>>N>>K>>line;
        if(K==1) {
            int a = start('1',N);
            int b = start('0',N);
            if(a < b){
                transform('1',N);
                cout<<a<<endl;
            } else {
                transform('0',N);
                cout<<b<<endl;
            }
        } else {
            transform(K, N);
        }

        cout<<line<<endl;
    }
    return 0;
}
