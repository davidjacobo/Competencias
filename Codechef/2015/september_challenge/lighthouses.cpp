#include <cstdio>
#include <algorithm>
#define MAX_N 100001
#define INF (1<<30)

using namespace std;
typedef pair<int,int> ii;
ii points[MAX_N];

int look(int key,int dim,int N){
    int x,y;
    for(int i=0;i<N;++i){
        x = points[i].first;
        y = points[i].second;
        if(dim==0 && key==x) return i+1;
        if(dim==1 && key==y) return i+1;
    }
    return -1;
}

int main(){
    int T,N;
    int x,y;
    int min_x,min_y,max_x,max_y;

    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        max_x = max_y = -INF;
        min_x = min_y = INF;
        for(int i=0;i<N;++i){
            scanf("%d %d",&x,&y);
            points[i] = ii(x,y);
            max_x = max(max_x, x);
            max_y = max(max_y, y);
            min_x = min(min_x, x);
            min_y = min(min_y, y);
        }

        //if all the islands can be placed over a line
        //or there is a pivot island, we can cover with
        //a single lighthouse, otherwise, pick 2, leftmost
        //and rightmost
       
        bool done = false;
        int same_x = 0, same_y = 0;
        for(int i=0;i<N && !done;++i){
            x = points[i].first;
            y = points[i].second;

            if(x == min_x) ++same_x;
            if(y == min_y) ++same_y;

            if(x == min_x && y == min_y){
                printf("1\n%d NE\n",(i+1));
                done = true;
            }else if(x==min_x && y==max_y){
                printf("1\n%d SE\n",(i+1));
                done = true;
            }else if(x==max_x && y==min_y){
                printf("1\n%d NW\n",(i+1));
                done = true;
            }else if(x==max_x && y==max_y){
                printf("1\n%d SW\n",(i+1));
                done = true;
            }   
        }

        if(done) continue;
        if(same_x==N){
            printf("1\n%d NE\n",look(min_y,1,N));
        }else if(same_y==N){
            printf("1\n%d NE\n",look(min_x,0,N));
        }else{
            //pick leftmost and rightmost
            same_x = look(min_x,0,N);
            same_y = look(max_x,0,N);
            if(points[same_x-1].second >= points[same_y-1].second){
                printf("2\n%d SE\n%d NW\n",same_x,same_y);
            }else{
                printf("2\n%d NE\n%d SW\n",same_x,same_y);
            }
        }
    }
    return 0;
}
