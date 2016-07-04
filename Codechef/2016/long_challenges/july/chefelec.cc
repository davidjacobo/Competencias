#include <iostream>
#include <stack>
#define MAX_N 100003

using namespace std;

// Finding the group for a given X node, using path compression at the same
// time

int main() {
  int x_coord[MAX_N+2];
  int T, N, temp, x, y;
  string cities;
  cin>>T;
  while(T--) {
    cin>>N>>cities;

    stack<int> cities_stack;
    for(int i=0;i<N;++i) { 
      cin>>x_coord[i];
      if(cities[i]=='1') cities_stack.push(i);
    }
    
    int total = 0;
    while(cities_stack.size() > 1) {
      int y = cities_stack.top(); cities_stack.pop();
      int x = cities_stack.top();

      // This case is for consecutive cities, no cable needed.
      if(y-1 == x) continue;
  
      int max_gap = 0;
      int total_gap = 0;
      for(int i=x+1;i<=y;++i) {
        max_gap = max(max_gap, x_coord[i]-x_coord[i-1]);
        total_gap += (x_coord[i]-x_coord[i-1]);
      }    
      total+= (total_gap - max_gap);
    }

    // Ok, start from left and right, add every still disconected city.
    for(int i=0;i<N;++i) {
      if(cities[i]=='1') break;
      total+= (x_coord[i+1] - x_coord[i]);
    }

    for(int i=N-1;i>=0;--i) {
      if(cities[i]=='1') break;
      total+= (x_coord[i] - x_coord[i-1]);
    }

    cout<<total<<endl; 
  }
  return 0;
}
