/* Sample program illustrating input/output */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int C[101], counter[101];

int solve(int N,int K) {
    int ans = 0, i;
    for(i=0;i<K;++i) {
        ans+= C[N-1-i];
        counter[i] = 1;
    }
    
    if(K>=N) return ans;
    
    int j = 0;
    for(i=N-K-1;i>=0;--i) {
        ans+= ((counter[j]+1)*C[i]);
        ++counter[j];
        j = (j+1)%K;
    }
    return ans;
}

int main(void){
   int N, K;
   cin >> N >> K;
   for(int i = 0; i < N; i++){
      cin >> C[i];
   }
   
    sort(C, C+N);
   
   int result = solve(N,K);
   cout << result << "\n";
   
   return 0;
}
