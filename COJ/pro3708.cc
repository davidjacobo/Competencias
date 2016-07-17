#include <iostream>
#include <cstring>
#define MAX_N 201

using namespace std;
typedef long long ll;

ll pascal[MAX_N][MAX_N];

void Init() {
  memset(pascal, 0, sizeof pascal);
  for(int i=0;i<MAX_N;++i) 
    pascal[i][0] = pascal[i][i] = 1;

  for(int i=1;i<MAX_N;++i) {
    for(int j=1;j<i;++j) {
      pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
    }
  }
}

int main() {
  Init();
  int T, n;
  cin>>T;
  while(T--) {
    cin>>n;
    cout<<(1+pascal[n][2]+pascal[n][4])<<endl;
  }
  return 0;
}
