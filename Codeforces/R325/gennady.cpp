#include <iostream>
#include <vector>
#include <list>
#define MAX_N 4001
using namespace std;
typedef long long ll;
typedef pair<ll,ll> llll;
typedef pair<llll,llll> llll_llll;
ll children[MAX_N][3];
vector<ll> output;
list<llll_llll> q;

int main(){
    ll v,d,p;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>v>>d>>p;
        q.push_back(llll_llll(llll(v,d),llll(p,i+1)));
    }

    while(!q.empty()){
        llll_llll kid = q.front();
        q.pop_front();
        
        if(kid.second.first>=0){
            output.push_back(kid.second.second);
            v = kid.first.first;
            d = 0;
            for(list<llll_llll>::iterator it = q.begin();it!=q.end();){
                if(v<=0 && d==0) break;
                (*it).second.first-= d;
                if(v>0) (*it).second.first-= v;

                if((*it).second.first<0){
                    d+= (*it).first.second;
                    it = q.erase(it);
                }else{
                    ++it;
                }
                --v;
            }
        }
    }

    cout<<output.size()<<endl;
    for(int i=0;i<output.size();++i){
        cout<<output[i]<<" ";
    }
    return 0;
}
