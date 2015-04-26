#include <cstdio>
#include <cstring>
#define MAX_N 101
using namespace std;

char line[MAX_N];

bool test(int i,int j,int len){
    if(len-(j-i+1)!=10) return false;
    char word[MAX_N];
    char codeforces[] = "CODEFORCES";

    int ind = 0;
    for(int k=0;k<len;k++)
        if(k<i || k>j)
            word[ind++] = line[k];
    word[10] = '\0';
    //printf("%s\n", word);

    for(int k=0;k<10;k++)
        if(word[k]!=codeforces[k]) return false;
    return true;
}

int main(){
    int i,j;
    scanf("%s",line);
    int len = strlen(line);

    bool win = false;
    for(i=0;i<len;i++){
        for(j=i;j<len;j++){
            if(test(i,j,len)){
                win = true;
            }
        }
    }

    if(win) printf("YES\n");
    else printf("NO\n");
    return 0;
}
