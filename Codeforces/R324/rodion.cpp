#include <iostream>
using namespace std;

int main(){
  int n,t;
  cin>>n>>t;
  if(n==1) {
    if(t==10) {
      cout<<-1<<endl;
    } else {
      cout<<t<<endl;
    }
  } else {
    cout<<t;
    if(t==10) --n;
    for(int i=1;i<n;++i)
      cout<<0;
    cout<<endl;
  }
  return 0;
}
