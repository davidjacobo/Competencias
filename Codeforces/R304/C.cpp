#include <iostream>
#include <queue>
#define MAX_IT 1000000
using namespace std;

queue<int> qA;
queue<int> qB;

int main(){
    int n;
    int A, B, t;
    cin>>n;
    cin>>A;
    for(int i=0;i<A;++i){
        cin>>t;
        qA.push(t);
    }

    cin>>B;
    for(int i=0;i<B;++i){
        cin>>t;
        qB.push(t);
    }

    int max_it = 0;
    while(max_it<MAX_IT && !qA.empty() && !qB.empty()){
        int tA = qA.front();
        int tB = qB.front();
        
        qB.pop(); qA.pop();

        if(tA > tB){
            qA.push(tB);
            qA.push(tA);
        } else {
            qB.push(tA);
            qB.push(tB);
        }
        max_it++;
    }

    if(qA.empty()){
        cout<<max_it<<" "<<2<<endl;
    } else if(qB.empty()) {
        cout<<max_it<<" "<<1<<endl;
    } else {
        cout<<-1;
    }
}
