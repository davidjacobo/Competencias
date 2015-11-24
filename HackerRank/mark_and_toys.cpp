#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() 
{
    long long n, k; cin >> n >> k;
    vector<int> prices;
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        prices.push_back(p);
    }
    
    int answer = 0;
    
    // Write the code for computing the final answer using n,k,prices
    sort(prices.begin(), prices.end());
    ll sum = 0;
    for(auto x:prices) {
        ++answer;
        sum+= x;
        if(sum>k) {
            --answer;
            break;
        }
    }
   
    cout << answer << endl;
    
    return 0;
}
