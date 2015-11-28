#include <iostream>
#include <deque> 
#include <queue>
using namespace std;
typedef pair<int,int> ii;

void printKMax(int arr[], int n, int k){
    priority_queue<ii> pq;
   for(int i=0;i<k-1;++i) {
       pq.push(ii(arr[i],i));
   }
    
    for(int i=k-1;i<n;++i) {
        pq.push(ii(arr[i],i));
        
        while(!pq.empty()) {
            ii temp = pq.top();
            if(i - temp.second >= k) {
                pq.pop();
            } else {
                cout<<temp.first<<" ";
                break;
            }
        }
    }
    cout<<endl;
}
int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
