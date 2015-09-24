#include <iostream>
#include <algorithm>
#include <vector>
#define INF (1<<30)

using namespace std;
typedef vector<int> vi;
int n;
vi numbers;

int main(){
    int t, n, a;
    cin>>t;
    while(t--){
        cin>>n;
        numbers.clear();
        numbers.push_back(-INF);
        numbers.push_back(INF);
        for(int i=0;i<n;++i){
            cin>>a;
            int ind = upper_bound(numbers.begin(), numbers.end(), a)-numbers.begin();
            if(ind==numbers.size()-1) numbers.push_back(INF);
            numbers[ind] = a;
        }

        cout<<numbers.size()-2;
        for(int i=1;i<numbers.size()-1;++i){
            cout<<" "<<numbers[i];   
        }
        cout<<endl;
    }

    return 0;
}
