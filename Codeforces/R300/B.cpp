#include <cstdio>
#include <vector>
#define MAX_N 1000001
#define INF 1000000000
using namespace std;
vector<int> quasi;
int selected[MAX_N];

void gen_quasi_binary(){
    int num = 0, decimal, bit;
    for(num=0;num<64;num++){
        decimal = 0;
        for(bit=5;bit>=0;bit--){
            decimal*= 10;
            decimal+= (num & (1<<bit))?1:0;
        }
        quasi.push_back(decimal);
    }
}

int dp(int N){
    int nuevo[MAX_N];
    int i,j;

    for(j=0;j<MAX_N;j++) {nuevo[j] = INF; selected[j] = 1;}
    nuevo[0] = 0;

    for(i=1;i<64;i++){
        for(j=1;j<=N;j++){
            if(j >= quasi[i]){
                if(nuevo[j-quasi[i]]+1 < nuevo[j]) {
                    nuevo[j] = nuevo[j-quasi[i]]+1;
                    selected[j] = i;
                }
            }
        }
    }
    return nuevo[N];
}

void path(int N){
    while(N>0){
        printf("%d ", quasi[selected[N]]);
        N-= quasi[selected[N]];
    }
}

int main(){
    int N;
    scanf("%d",&N);
    if(N==1000000){
        printf("%d\n", 1);
        printf("1000000");
        return 0;
    }

    gen_quasi_binary();
    printf("%d\n", dp(N));
    path(N);
    return 0;
}
