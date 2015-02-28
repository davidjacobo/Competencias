#include <stdio.h>
#define INF 1000000000
int miguel[26][26];
int apus[26][26];

void clean(int N){
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            miguel[i][j] = apus[i][j] = INF;

    for(i=0;i<N;i++)
        miguel[i][i] = apus[i][i] = 0;
}

void floyd(int N){
    int i,j,k,distance;

    for(k=0;k<N;k++){
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                distance = miguel[i][k] + miguel[k][j];
                if(miguel[i][j] > distance)
                    miguel[i][j] = distance;

                distance = apus[i][k] + apus[k][j];
                if(apus[i][j] > distance)
                    apus[i][j] = distance;
            }
        }
    }
}

int main(){
    int N;
    int distance, i, j;
    char age, direction, x, y, space;
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        clean(26);
        for(i=0;i<N;i++){
            scanf("%*c %c %c %c %c %d",&age,&direction, &x,&y,&distance);
            //printf("%c %c %c %c %d\n",age,direction,x,y,distance);
            x-= 'A';
            y-= 'A';

            if(age=='Y'){
                if(distance < apus[x][y])
                    apus[x][y] = distance;
                if(direction=='B' && distance<apus[y][x])
                    apus[y][x] = distance;
            } else {
                if(distance < miguel[x][y])
                    miguel[x][y] = distance;
                if(direction=='B' && distance<miguel[y][x])
                    miguel[y][x] = distance;
            }
        }

        floyd(26);
        scanf("%*c %c %c",&x,&y);
        x-= 'A';
        y-= 'A';
        int minimo = INF;
        for(i=0;i<26;i++)
            if(apus[x][i]+miguel[y][i] < minimo)
                minimo = apus[x][i] + miguel[y][i];

        if(minimo < INF){
            printf("%d", minimo);
            for(i=0;i<26;i++)
                if(apus[x][i]+miguel[y][i]==minimo)
                    printf(" %c",(char)(i+'A'));
            printf("\n");
        } else {
            printf("You will never meet.\n");
        }
        
    }
    return 0;
}
