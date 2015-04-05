#include <cstdio>
using namespace std;

int main(){
    char table[101];
    int N;
    scanf("%d %s",&N,table);

    int step,start,counter;
    bool win = false;
    for(step=1;step<N && !win;step++){
        for(start=0;start<N && !win;start++){
            counter = 0;
            //printf("--start: %d\n",start);
            while(counter<5){
                //printf("try %d\n",start+counter*step);
                if(start+counter*step>=N || table[start+counter*step]!='*')
                    break;
                counter++;
            }
        
            if(counter==5)
                win = true;
        }
    }

    if(win) printf("yes\n");
    else printf("no\n");
    return 0;
}
