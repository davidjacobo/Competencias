#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *p;
    p = (char *)malloc(53);
    int n, counter,i,len,used[26],j, fail_counter;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        scanf("%s",p);
        
        counter = fail_counter = 0;
        len = strlen(p);
        for(i=0;i<26;i++) used[i] = 0;

        for(i=0;i<len;i++){
            j = p[i]-'A';
            if(used[j]==0) {
                used[j] = 1;
                if(counter < n){
                    counter++;
                } else {
                    used[j] = -1;
                    fail_counter++;
                }
            } else if(used[j]==1){
                counter--;
            }
        }

        if(fail_counter == 0){
            printf("All customers tanned successfully.\n");
        } else {
            printf("%d customer(s) walked away.\n", fail_counter);
        }
    }
    return 0;
}
