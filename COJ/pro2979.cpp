#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, T, counter;
    cin >> T;
    while(T-->0){
        cin>>N;
        int arr[N], sorted[N];
        for(int i=0;i<N;i++) {
            cin>>arr[i];
            sorted[i] = arr[i];
        }

        sort(sorted, sorted+N);
        counter = 0;
        for(int i=0;i<N;i++)
            if(sorted[i]!=arr[i]) counter++;
        cout<<counter<<endl;
    }
    return 0;
}
