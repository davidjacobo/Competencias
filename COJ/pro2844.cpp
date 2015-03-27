#include <cstdio>
#include <cstring>
using namespace std;

bool explicit_check(char *pattern,char *line,int len,int i){
    int j = 0;
    while(j<len){
        if(pattern[j]!=line[i+j]) 
            return false;
        j++;
    }
    return true;
}

int wrapper_shit(char *pattern,char *line){
    int pat_len = strlen(pattern);
    int lin_len = strlen(line);
    int counter = 0;
    
    for(int i=0;i<lin_len-pat_len+1;i++)
        if(explicit_check(pattern,line,pat_len,i)){
            counter++;
            i+= pat_len-1;
        }
    return counter;
}

int main(){
    char pattern[21];
    char line[251];
    int total = 0;

    scanf("%s", pattern);
    while(scanf("%s", line)!=EOF){
        total+= wrapper_shit(pattern,line);
    }
    printf("%d\n", total);
    return 0;
}
