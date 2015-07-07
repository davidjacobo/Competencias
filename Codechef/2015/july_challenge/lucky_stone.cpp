#include <cstdio>
#include <stack>

using namespace std;
typedef long long ll;
stack<int> digits;

ll remove_zeroes(ll num){
    while(num%10==0){
        digits.push(num%10);
        num/= 10;
    }
    return num;
}

void solve(ll A){
    int digit;
 
    while(A>0){
        A = remove_zeroes(A);
        digit = A%10;
        if(digit!=5) break;

        A<<=2;
    }

    while(A>0){
        digit = A%10;
        digits.push(digit);
        A/=10;
    }

    while(!digits.empty()){
        printf("%d",digits.top()), digits.pop();
    }
    printf("\n");
}

int main(){
    int N, A;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&A);
        solve(A);
    }
    return 0;
}
