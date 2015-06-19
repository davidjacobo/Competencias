#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 2001
#define INF (1<<30)

using namespace std;
typedef long long ll;
int n, points[MAX_N][2];

double pendiente(int i,int j){
    int num = points[i][0] - points[j][0];
    int den = points[i][1] - points[j][1];

    if(den==0) return INF;
    return (double)num/den;
}

ll solve(){
    vector<double> vec;
    ll ans = 0;
    int rep;

    for(int i=0;i<n;++i){
        vec.clear();
        for(int j=i+1;j<n;++j){
            vec.push_back(pendiente(i,j));
        }
        sort(vec.begin(), vec.end());
        
        double m1;
        for(int j=0;j<vec.size();++j){
            m1 = vec[j];
            rep = (upper_bound(vec.begin(), vec.end(), m1)-vec.begin());
            rep-= (lower_bound(vec.begin(), vec.end(), m1)-vec.begin());
            ans+= vec.size()-rep;
        }
    }
    return ans>>1;
}

int main(){
    int x,y;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        points[i][0] = x;
        points[i][1] = y;
    }

    cout<<solve()<<endl;
    return 0;
}
