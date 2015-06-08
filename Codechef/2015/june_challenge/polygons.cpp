#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 100001
#define INF 2000000000
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> ii_i;
typedef vector<ii_i> vii_i;

int output[MAX_N];
vii_i poly;

int main(){
    int T,N,x,y,xmin,xmax,ymin,ymax,P;
    cin>>T;
    while(T--){
        cin>>N;

        poly.clear();
        for(int i=0;i<N;++i){
            cin>>P;
            xmin = ymin = INF;
            xmax = ymax = -INF;
            for(int j=0;j<P;++j){
                cin>>x>>y;
                if(x<xmin) xmin = x;
                if(y<xmin) ymin = y;
                if(x>xmax) xmax = x;
                if(y>ymax) ymax = y;
            }

            poly.push_back(ii_i(ii(xmax-xmin, ymax-ymin),i));
        }
        sort(poly.begin(), poly.end());
        for(int i=0;i<N;++i)
            output[poly[i].second] = i;

        bool first = true;
        for(int i=0;i<N;++i){
            if(!first) cout<<" ";
            first = false;
            cout<<output[i];
        }
        cout<<endl;
    }
    return 0;
}
