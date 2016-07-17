#include <iostream>
#include <cstring>
#define MAX_N 100001
#define INV 0

using namespace std;
int codes[27];

void solve(string input) {
  memset(codes, INV, sizeof codes);
  int index = 1;
  for (int i = 0; i < input.size(); ++i) {
    int a = input[i]-'a';
    if (codes[a] == INV)
      codes[a] = index++;

    // Let's print out right away
    switch(codes[a]) {
      case 2:
        cout<<5; break;
      case 5:
        cout<<2; break;
      case 6:
        cout<<9; break;
      case 9:
        cout<<6; break;
      case 12:
        cout<<15; break;
      case 15:
        cout<<12; break;
      case 16:
        cout<<19; break;
      case 19:
        cout<<16; break;
      case 20:
        cout<<50; break;
      case 21:
        cout<<51; break;
      case 22:
        cout<<55; break;
      case 23:
        cout<<53; break;
      case 24:
        cout<<54; break;
      case 25:
        cout<<52; break;
      case 26:
        cout<<59; break;
      default:
        cout<<codes[a];
    }
  }
  cout<<endl;
}

int main() {
  string input;
  while(getline(cin, input)) {
    solve(input);
  }
  return 0;
}
