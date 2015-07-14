#include <cstdio>
#define MAX_N 101

using namespace std;

int main(){
    char line[MAX_N], car;
    int add, len;

    scanf("%d %s %d",&len,line,&add);
    add%= 26;

    for(int i=0;i<len;++i){
        car = line[i];
        if(car<='z' && car>='a'){
            car = (car-'a'+add)%26;
            line[i] = car+'a';
        } else if(car<='Z' && car>='A'){
            car = (car-'A'+add)%26;
            line[i] = car+'A';
        } 
    }

    printf("%s\n", line);
    return 0;
}
