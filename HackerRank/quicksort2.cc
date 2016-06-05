#include <iostream>
#include <vector>

using namespace std;

vector<int> print_array(const vector<int> left, int pivot, const vector<int> right) {
  vector<int> output;
  for (int i = 0;i < left.size();++i) {
    cout<<left[i]<<" ";
    output.push_back(left[i]);
  }
  cout<<pivot<<" ";
  output.push_back(pivot);
  for (int i = 0;i < right.size();++i) {
    cout<<right[i]<<" ";
    output.push_back(right[i]);
  }
  cout<<endl;
  return output;
}

vector<int> partition(vector<int> input) {
  if (input.size() == 1) return input;

  int pivot = input[0];
  vector<int> left, right;
  for (int i = 1;i < input.size();++i) {
    if (input[i] < pivot)  left.push_back(input[i]);
    else right.push_back(input[i]);
  }

  if (left.size() > 0)  left = partition(left);
  if (right.size() > 0)  right = partition(right);
  return print_array(left, pivot, right);
}

int main() {
  int n, t;
  vector<int> input;
  cin>>n;
  for (int i = 0;i < n;++i) {
    cin>>t;
    input.push_back(t);
  }
  
  if (n == 1) {
    cout<<input[0];
  } else {
    partition(input);
  }

}
