#include <iostream>
#include <cmath>
#define MAX_N 200001
using namespace std;
typedef long long int lli;
int arr[MAX_N];

int main(){
    lli A,needed,suma = 0;
    int n,t;
    cin>>n>>A;

    for(int i=0;i<n;i++){
        cin>>t;
        arr[i] = t;
        suma+= t;
    }

        
    lli lower, upper;
    for(int i=0;i<n;i++){
        t = arr[i];
        //todos cayeron dados perfectos, el dado di debe sacar...
        lower = max(A-(suma-t),lli(1));
        //todos valieron cabeza, ergo sacaron el valor minimo, sumando n-1
        upper = min(A-(n-1), (lli)t);
        //cout<<"U: "<<upper<<" L: "<<lower<<endl;
        cout<<t-(upper-lower+1)<<" ";
    }
    return 0;
}
