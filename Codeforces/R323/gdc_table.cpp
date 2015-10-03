#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#define MAX_N 250001

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
vi nums;
vi output;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int n;
    scanf("%d",&n);
    map<int,int> el_mapa;
    map<int,int>::iterator it;

    int t;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&t);
            nums.push_back(t);
            it = el_mapa.find(t);
            if(it != el_mapa.end()){
                el_mapa[t] = el_mapa[t]+1;
            }else{
                el_mapa[t] = 1;
            }
        }
    }
    sort(nums.begin(), nums.end());
    for(int i=(n*n)-1;i>=0;--i){
        t = nums[i];
        if(el_mapa[t] > 0){
            el_mapa[t] = el_mapa[t]-1;
            output.push_back(t);
        }else{
            continue;
        }

        for(int j=0;j<output.size()-1;++j){
            int t2 = output[j];
            int com = gcd(max(t,t2), min(t,t2));

            el_mapa[com] = el_mapa[com] - 2;
        }
    }

    for(int i=0;i<output.size();++i){
        printf("%d ",output[i]);
    }
    return 0;
}
