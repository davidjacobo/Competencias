#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX_N 501
using namespace std;
int N,M,F,mod, lines[MAX_N], last[MAX_N][MAX_N], nuevo[MAX_N][MAX_N];

int dp(){
    last[0][0] = 1;

    for(int i=1;i<=N;++i){
        for(int j=0;j<=M;++j){
            for(int k=0;k<=F;++k){
                if(last[j][k]!=-1){
                    //try to sum coder i as much as possible, project to nuevo
                    nuevo[j][k] = (nuevo[j][k]+last[j][k]) % mod;
                    int written_lines = j+1;
                    int failures = k + lines[i];

                    while(written_lines <= M && failures<=F){
                        nuevo[written_lines][failures] = (nuevo[written_lines][failures] + last[j][k]) % mod;

                        written_lines++;
                        failures+= lines[i];
                    }
                }
            }
        }
        for(int l=0;l<=M;++l) for(int p=0;p<=F;++p) last[l][p] = nuevo[l][p];
        memset(nuevo, 0, sizeof nuevo);
    }
    
    int ans = 0;
    for(int i=0;i<=F;++i)
        ans = (ans + last[M][i]) % mod;

    return ans;
}

int main(){
    //cin>>N>>M>>F>>mod;
    scanf("%d %d %d %d",&N,&M,&F,&mod);
    for(int i=1;i<=N;++i)
        //cin>>lines[i];
        scanf("%d",&lines[i]);

    memset(last, -1, sizeof last);
    memset(nuevo, 0, sizeof nuevo);


    //cout<<dp()<<endl;
    printf("%d\n",dp());
    return 0;
}
