#include <cstdio>
#include <cstring>
#define MAX_N 12

using namespace std;

char S[MAX_N], T[MAX_N];

int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        scanf("%s %s",S,T);
        int len = strlen(S);

        bool fail = false;
        for(int i=0;i<len;++i){
            if(S[i]!='?' && T[i]!='?' && S[i]!=T[i]){
                fail = true;
                break;
            }
        }

        if(fail) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}
