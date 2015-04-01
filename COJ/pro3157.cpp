#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX_N 100002
using namespace std;
char cow[] = "COW";
char word[MAX_N];
int counter;

void dfs(int ind,int i,int len){
    if(ind==3){
        counter++;
        return;
    }

    char car = cow[ind];
    for(int j=i;j<len;j++)
        if(car==word[j]) dfs(ind+1,j+1,len);
}

int main(){
    int len;
    scanf("%d %s", &len, word);
    counter = 0;
    dfs(0,0,len);
    printf("%d\n",counter);
    return 0;
}
