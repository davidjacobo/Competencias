#include <iostream>
#include <cstring>
#define MAX_N 11

using namespace std;

void FillArray(char arr[], const string input) {
  memset(arr, 0, MAX_N * sizeof(char));
  int len = input.size();
  int index = 0;
  arr[index++] = input[0];
  for(int i = 1; i < len; ++i) {
    if (input[i-1] == ' ') 
      arr[index++] = input[i];
  }
}

bool SameInitials(const char A[], const char B[]) {
  for(int i = 0; i < MAX_N; ++i)
    if (A[i] != B[i]) return false;
  return true;
}

int main() {
  string A, B;
  char Ainit[MAX_N], Binit[MAX_N];
  while(getline(cin, A)) {
    getline(cin, B);

    FillArray(Ainit, A);
    FillArray(Binit, B);
    if (SameInitials(Ainit, Binit)) {
      cout<<"yes"<<endl;
    } else {
      cout<<"no"<<endl;
    }
  }
  return 0;
}
