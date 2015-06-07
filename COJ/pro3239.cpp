#include <cstdio>
#include <cstring>
#include <stack>
#define MAX_LEN 100001
#define INV -1

using namespace std;
char line[MAX_LEN];
int last_index[26];
bool seen[26];

void solve(int len){
    memset(last_index, INV, sizeof last_index);
    memset(seen, false, sizeof seen);
    stack<int> output;
    output.push(-1);
    seen[line[len-1]-'a'] = true;
    last_index[line[len-1]-'a'] = len;

    bool found;
    int closer_ind;
    for(int i=len-2;i>=0;--i){
        int k = line[i]-'a';
        seen[k] = true;
        last_index[k] = i+1;

        closer_ind = len+1;
        for(int j=k+1;j<26;++j){
            if(seen[j])
                closer_ind = min(closer_ind, last_index[j]);
        }       
        if(closer_ind == len+1) output.push(-1);
        else output.push(closer_ind);
    }

    printf("%d",output.top()); output.pop();

    while(!output.empty()){
        printf(" %d",output.top()); output.pop();
    }
    printf("\n");
}

int main(){
    int T, len;
    scanf("%d",&T);
    while(T--){
        scanf("%d %s",&len, line);       
        solve(len);
    }
    return 0;
}
