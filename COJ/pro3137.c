#include <stdio.h>
int is_valid(int a,int b,int c){
    if(a+b==c)  return 1;
    if(a-b==c)  return 1; 
    if(a*b==c)  return 1; 
    if(b!=0){
        if(a/b==c)  return 1;
        if(a%b==c)  return 1;
    }
    return 0;
}

int main(){
    int t, a, b, c;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&a,&b,&c);
        printf("%s\n",(is_valid(a,b,c))?"YES":"NO");
    }
    
    return 0;
}
