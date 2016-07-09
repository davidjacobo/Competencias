#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 10002

using namespace std;
int A[MAX_N], B[MAX_N];
bool used[MAX_N];

bool is_valid_array(int pivot, int N) {
  for(int i=1;i<N-1;++i) {
    for(int j=0;j<4;++j) {
      int new_cell_value = A[i];
      if(!used[i-1]) new_cell_value += B[i-1];

      if((j&1)!=0) {
        if(used[i]) continue;
        new_cell_value += B[i];
      }
      if((j&2)!=0) {
        if(used[i+1]) continue;
        new_cell_value += B[i+1];
      }

      if(new_cell_value != pivot) continue;
      // If we hit this part is because  we have a solution for A[i], and as we
      // are trying the subsets from left to right we use the first that works!
      if((j&1)!=0) used[i] = true;
      if((j&2)!=0) used[i+1] = true;
      break; 
    }  
  }

  // Ok lets see if A[N-1] needs to group any other cell
  int new_cell_value = A[N-1];
  if(!used[N-1]) new_cell_value += B[N-1];
  if(!used[N-2]) new_cell_value += B[N-2];
  if(new_cell_value != pivot) return false;

  return true;
}

int solve(int N) {
  // Ok, this is the fun part, lets build all the possible combinations for
  // the first number on the array and use it as a reference.
  int ans = -1;
  for(int i=0;i<4;++i){
  memset(used, false, sizeof used);
  int pivot = A[0];
  if((1&i)!=0) {
    used[0] = true;
    pivot+= B[0];
  }
  if((2&i)!=0) {
    used[1] = true;
    pivot+= B[1];
  }

  if(is_valid_array(pivot, N))
    ans = max(ans, pivot);
  }
  return ans;
}

int main() {
  int T, N;
  cin>>T;
  while(T--) {
    cin>>N;
    for(int i=0;i<N;++i) cin>>B[i];
    for(int i=0;i<N;++i) cin>>A[i];

    if(N==1) {
      cout<<(A[0]+B[0])<<endl;
    } else {
      int ans = solve(N);
      reverse(A, A+N);
      reverse(B, B+N);
      ans = max(ans, solve(N));
      cout<<ans<<endl;
    }
    
  }
  return 0;
}
