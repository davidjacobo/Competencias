#include <cstdio>
#define MAX_N 1003
using namespace std;
int arr[MAX_N];

int main(){
    char line[MAX_N];
    int T,N,counter = 1;
    scanf("%d",&T);
    while(T--){
        scanf("%d %s",&N,line);

        for(int i=0;i<=N;i++)
            arr[i]= line[i]-'0';

        int ans = 0, people = arr[0];
        for(int i=1;i<=N;i++){
            if(i>people){
                ans+= i-people;
                people+= i-people;
            }
            people+= arr[i];
        }
        printf("Case #%d: %d\n",counter++,ans);
    }
    return 0;
}
