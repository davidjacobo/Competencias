#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
typedef vector<int> vi;
vi boys, grills;

int main(){
    int N,K, t;
    scanf("%d %d",&N,&K);

    for(int i=0;i<N;++i){
        scanf("%d",&t);
        boys.push_back(t);
    }
    for(int i=0;i<N;++i){
        scanf("%d",&t);
        grills.push_back(t);
    }

    sort(boys.begin(), boys.end());
    sort(grills.begin(), grills.end());

    int i=0, j=0, ans = 0;
    while(i<N && j<N){
        t = abs(boys[i]-grills[j]);

        if(t<=K){
            ++i;
            ++j;
            ++ans;
        } else if(boys[i]>grills[j]){
            ++j;
        } else {
            ++i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
