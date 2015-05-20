#include <iostream>
#include <cstring>
#define MAX_N 100001
using namespace std;
bool erroneos[MAX_N];
char s[MAX_N], t[MAX_N];
int len, dist;

int distance(){
    int ans = 0;
    memset(erroneos, false, sizeof erroneos);

    for(int i=0;i<len;++i)
        if(s[i]!=t[i]){ 
            erroneos[i] = true;
            ++ans;
        }
    return ans;
}

char flip(char car){
    if(car=='1') return '0';
    return '1';
}

void flip_erroneos(){
    int to_flip = (dist>>1);
    for(int i=0;i<len && to_flip>0;++i){
        if(erroneos[i]){
            s[i] = flip(s[i]);
            --to_flip;
        }
    }
}

int main(){
    cin>>s>>t;
    len = strlen(s);
    dist = distance();
    if((dist&1)!=0) {
        cout<<"impossible"<<endl;
    } else {
        flip_erroneos();
        cout<<s<<endl;       
    }

    return 0;
}
