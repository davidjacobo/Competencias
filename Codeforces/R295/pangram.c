#include <stdio.h>
#include <stdlib.h>

int main(){
    int counter[26];
    int n;
    char *p = (char *)malloc(101);

    scanf("%d",&n);
    scanf("%s",p);
    int i;
    char car;
    for(i=0;i<26;i++) counter[i]=0;

    for(i=0;i<n;i++){
        car = p[i];
        if(car>='a' && car<='z')  
            counter[car-'a']++;
        else
            counter[car-'A']++;
    }

    int fuck=0;
    for(i=0;i<26;i++)
        if(counter[i]==0)
            fuck=1;
    if(fuck==0) printf("YES\n");
    else printf("NO\n");
    return 0;
}
