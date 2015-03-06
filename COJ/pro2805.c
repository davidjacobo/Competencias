#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *p = (char *) malloc(53);
    int i,j,len,rep;
    char car;
    p[0] = '*';
    scanf("%d", &j);
    scanf("%s",&p[1]);
    len = strlen(p);
    p[len++] = '*';
    p[len] ='\0';

    int total = 0;
    for(i=1;i<len-1;i++){
        car = p[i];
        j = i+1;
        while(p[j]==car){
            j++;
        }   
        rep = j-i;
        if(car=='S' && (p[i-1]!='L' || p[j]!='L')) {
            total+= rep;
        } else if(car=='L') {
            total+= (rep>2)?1+(rep>>1):rep;
        } else{
            total+= rep-1;
        }

        i = j-1;
    }

    printf("%d\n", total);

    return 0;
}
