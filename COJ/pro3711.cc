#include <iostream>
#include <cmath>
#include <cstring>
#define MAX_N 26

using namespace std;
bool seen[MAX_N];
int table[MAX_N][MAX_N];

void capture(int n) {
  for(int i=0;i<n;++i) {
    for(int j=0;j<n;++j) {
      cin>>table[i][j];
    }
  }
}

bool check_rows(int n) {
  for(int i=0;i<n;++i) {
    memset(seen, false, sizeof seen);
    for(int j=0;j<n;++j) {
      if(seen[table[i][j]]) return false;
      seen[table[i][j]] = true;
    }
  }
  return true;
}

bool check_cols(int n) {
  for(int j=0;j<n;++j) {
    memset(seen, false, sizeof seen);
    for(int i=0;i<n;++i) {
      if(seen[table[i][j]]) return false;
      seen[table[i][j]] = true;
    }
  }
  return true;
}

bool check_rect(int x,int y,int n) {
  memset(seen, false, sizeof seen);
  for(int i=x;i<x+n;++i) 
    for(int j=y;j<y+n;++j) {
      if (seen[table[i][j]]) return false;
      seen[table[i][j]] = true;
    }
  return true;
} 

bool check_rectangles(int n) {
  int root = round(sqrt(n));
  int x = 0, y = 0;
  for(int i=0;i<root;++i) {
    for(int j=0;j<root;++j) {
      if (!check_rect(x,y,root)) return false;
      y+= root;
    }
    y = 0;
    x+= root;
  } 
  return true;
}

int main() {
  int T, n;
  cin>>T;
  while(T--) {
    cin>>n;
    capture(n);
    if(check_rows(n) && check_cols(n) && check_rectangles(n)) {
      cout<<"yes"<<endl;
    } else {
      cout<<"no"<<endl;
    }
  }
  return 0;
}
