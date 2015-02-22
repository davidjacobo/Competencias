#include <stdio.h>
#include <stdlib.h>

int main(){
    char *cad, car;
    int vowel, consonant;
    vowel = consonant = 0;
    cad = (char *)malloc(1001); 
    scanf("%s",cad);
    for(;*cad != '\0'; cad++) {
        car = *cad;
        if(car=='A' || car=='E' || car=='I' || car=='O' || car=='U') {
            vowel++;
        } else {
            consonant++;
        }
    }

    printf("%d %d\n",vowel,consonant);
    return 0;
}
