#include <iostream>

using namespace std;

int main() {
  int T, N, t, total;
  bool min_grade, max_grade;
  cin>>T;
  while(T--) {
    cin>>N;
    total = 0;
    min_grade = max_grade = false;
    for(int i=0;i<N;++i) {
      cin>>t;
      total+= t;
      if(t==5) max_grade|= true;
      if(t==2) min_grade|= true;
    }

    if (((double)total / N < 4.0) || min_grade || !max_grade) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
  }
  return 0;
}
