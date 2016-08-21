#include <iostream>

using namespace std;

bool capture(int N,int M) {
  char a;
  for(int i=0;i<N;++i) {
    for(int j=0;j<M;++j) {
      cin>>a;
      if(a=='C' || a=='M' || a=='Y') return false;
    }
  }
  return true;
}

int main() {
  int N,M;
  cin>>N>>M;
  if(capture(N,M)) {
    cout<<"#Black&White";
  } else {
    cout<<"#Color";
  }
  return 0;
}
