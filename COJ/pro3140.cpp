#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAX_N 1000001
using namespace std;
int A[2000000];

int main(){
    int N,t;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &t);
        A[t]++;
    }
    
    //sort(A, A+N);
    for(int i=0;i<2000000;i++)
        while(A[i]--)
            printf("%d\n", i);
    return 0;
}
