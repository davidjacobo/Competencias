#include <cstring>
#include <cstdio>

using namespace std;
char colors[][10] = {"black", "blue", "red", "green", "yellow", "orange"};
int arr[6];
int sols[][3] = {{0,2,4},{0,2,5},{0,3,4},{0,3,5},{1,2,4},{1,2,5},{1,3,4},{1,3,5} };

int get_index(char str[]){
    for(int i=0;i<6;++i){
        if(strcmp(str, colors[i])==0) return i;
    }
    return false;
}

bool valid_perm(){
    int i,j;
    for(i=0;i<8;++i){
        int target = arr[sols[i][0]];
        for(j=1;j<3;++j){
            if(arr[sols[i][j]]!=target) break;
        }

        if(j==3) return true;
    }
    return false;
}

int main(){
    char line[10];
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<6;++i) {
            scanf("%s",line);
            arr[i] = get_index(line);
        }

        if(valid_perm()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
