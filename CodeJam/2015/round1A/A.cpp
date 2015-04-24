#include <cstdio>
#include <algorithm>
#define MAX_N 1001
using namespace std;

int main(){
    int T,N,counter = 1;
    int suma1, suma2, maximo;
    int arr[MAX_N];

    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%d",&arr[i]);
        suma1 = suma2 = maximo = 0;

        for(int i=1;i<N;i++){
            if(arr[i] < arr[i-1]){
                suma1+= arr[i-1]-arr[i];
                maximo = max(maximo, arr[i-1]-arr[i]);
            }
        }

        for(int i=0;i<N-1;i++)
            suma2+= (maximo > arr[i])?arr[i]:maximo;
        printf("Case #%d: %d %d\n",counter++,suma1,suma2);
        
    }   
    return 0;
}
