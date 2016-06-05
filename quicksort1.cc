#include <iostream>
using namespace std;

int main() {
  const int MAX_N = 1000;
  const int INV = (1<<30);
  int n, p, arr[MAX_N], repetitions = 1;
  cin>>n>>p;
  for(int i = 1;i < n;++i) {
    cin>>arr[i];
    if (arr[i] < p) {
      cout<<arr[i]<<" ";
      arr[i] = INV;
    } else if (arr[i] == p) {
      ++repetitions;
      arr[i] = INV;
    }
  }

  while(repetitions--) {
    cout<<p<<" ";
  }

  for(int i=1;i < n;++i)
    if (arr[i] != INV)  cout<<arr[i]<<" ";
  return 0;
}
