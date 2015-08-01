#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int main(){
    vi vec;

    int N,K,t;
    scanf("%d %d",&N,&K);

    for(int i=0;i<K;++i){
        scanf("%d",&t);
        vec.push_back(t);
    }

    sort(vec.begin(), vec.end());

    int x,y,ans = K;
    for(int i=0;i<vec.size()-1;++i){
        x = vec[i], y = vec[i+1];
        ans+= (int)ceil((y-x-3)/2.0);
    }

    ans+= (int)ceil((vec[0]-2)/2.0);
    ans+= (int)ceil((N-vec[K-1]-1)/2.0);

    printf("%d\n",ans);
}
