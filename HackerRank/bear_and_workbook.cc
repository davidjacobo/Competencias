#include <iostream>

using namespace std;

int main() {
  int n, k, t, ans = 0, total_pages, problem_number;
  int low, up;
  cin>>n>>k;
  int page = 1;
  for (int i = 0; i < n; ++i) {
    cin>>total_pages;
    int low = up = problem_number = 1;
    while (problem_number <= total_pages) {
      low = up;
      problem_number+= k;
      up = min(problem_number-1, total_pages);
      if (page <= up && page >= low) ++ans;
      ++page;
      ++up;
    }
  }
  cout<<ans;
  return 0;
}
