#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    if(a+b+c!=180) printf("Error\n");
    else if(a==b && b==c) printf("Equilateral\n");
    else if(a==b || a==c || b==c) printf("Isosceles\n");
    else printf("Scalene\n");
    return 0;
}
