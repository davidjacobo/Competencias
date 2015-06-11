#include <cstdio>
#define MAX_N 5001
#define MAX_NODES 12502501
#define INV -1
#define MOD 1000000007
#define COUNT 26

using namespace std;
typedef long long ll;

int ways[MAX_N][MAX_N], trie[MAX_NODES][27], output[MAX_N], pascal_counter[MAX_N],N, node_counter;
char line[MAX_N];

void pascal(){
    for(int i=0;i<MAX_N;++i)    ways[i][0] = ways[i][i] = 1;

    for(int i=2;i<MAX_N;++i)
        for(int j=1;j<i;++j)
            ways[i][j] = (ways[i-1][j-1] + ways[i-1][j])%MOD;
}

void clear(int n){
    int nodes = (n*(n+1))/2;
    for(int i=0;i<=nodes;++i){
        for(int j=0;j<26;++j){
            trie[i][j] = INV; 
        }
        trie[i][COUNT] = 0;
    }

    for(int i=0;i<=n;++i) {
        pascal_counter[i] = 0;
        output[i] = 0;
    }
}

void build(int i,int ind){
    if(ind>0){
        --pascal_counter[trie[ind][COUNT]];
        ++trie[ind][COUNT];
        ++pascal_counter[trie[ind][COUNT]];
    }

    if(i+1<=N) {
        int next = line[i]-'a';
        if(trie[ind][next]==INV)
            trie[ind][next] = node_counter++;
    
        build(i+1, trie[ind][next]);
    }
}

void final_count(int N){
    int t, m;
    for(int n=1;n<=N;++n){
        if(pascal_counter[n]==0) continue;
        m = n>>1;
       
        for(int k=n;k>m;--k){
            t = ((ll)ways[n][k] * pascal_counter[n]) % MOD;
            output[k] = (output[k] + t) % MOD;
            output[n-k] = (output[n-k] + t) % MOD;
        }

        if((n&1)==0) {
            t = ((ll)ways[n][m] * pascal_counter[n]) % MOD;
            output[m] = (output[m] + t) % MOD;
        }
    }
}

int main(){
    char input[MAX_N<<1];
    int T,Q,k;
    pascal();

    sscanf(gets(input),"%d",&T);
    while(T--){
        sscanf(gets(input),"%d %d",&N,&Q);
        sscanf(gets(input),"%s", line);
        clear(N);

        //prepare dummy root
        node_counter = 1;
        for(int i=0;i<N;++i){
            build(i, 0);
        }

        final_count(N);

        while(Q--){
            sscanf(gets(input),"%d",&k);
            
            if(k > N) {
                printf("0\n");
            } else {
                printf("%d\n", (output[k]+MOD)%MOD);
            }
        }
    }
    return 0;
}
