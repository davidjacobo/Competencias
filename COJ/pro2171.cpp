#include <cstdio>
#include <cstring>
#define MAX_N 1000001
using namespace std;
int count_in[MAX_N];
int count_out[MAX_N];

int main(){
    int N;
    int x,y;
    scanf("%d",&N);
    memset(count_in, 0, (N+1)*sizeof(int));
    memset(count_out, 0, (N+1)*sizeof(int));

    while(N--){
        scanf("%d %d",&x,&y);
        count_in[x]++;
        count_out[y]++;
    }

    int counter = 0, max_counter = 0;
    for(int i=1;i<MAX_N;i++){
        counter+= count_in[i];
        if(counter>max_counter) 
            max_counter = counter;
        counter-= count_out[i];
    }
    printf("%d\n",max_counter);
    return 0;
}
