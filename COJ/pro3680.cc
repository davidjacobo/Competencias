#include <iostream>
#include <algorithm>
#define MAX_N 100001

using namespace std;

int main() {
  int elefantes[MAX_N];
  int T,M,W;
  cin>>T;
  while(T--) {
    cin>>M>>W;
    for(int i=0;i<M;++i) cin>>elefantes[i];
    sort(elefantes, elefantes+M);
    int index = 0, suma = 0;
    while(index < M && suma < W) {
      suma+= elefantes[index];
      if (suma > W) break;
      ++index;
    }
    cout<<index<<endl;
  }
  return 0;
}
