#include <iostream>
#include <cstring>
#define MAX_N 105
#define REKT -1
#define VALID 0
#define HERO 1
using namespace std;
typedef pair<int,int> ii;

int mat[5][MAX_N], temp[5][MAX_N];

void init(int n){
    //Placing a REKT frame on the matrix, so the user HERO 
    //cannot go out the grid
    for(int i=0;i<5;++i){
        mat[i][0] = REKT;
    }

    for(int j=0;j<MAX_N;++j){
        mat[0][j] = mat[4][j] = REKT;
    }
}

void clean_hero(int n){
    //Clean the HERO positions on the matrix
    for(int i=0;i<3;++i){
        for(int j=0;j<MAX_N;++j){
            if(mat[i+1][j+1]==HERO) mat[i+1][j+1] = VALID;
        }
    }
}

void move_hero(int n){
    //Push to any possible position, as classic as it sounds
    //the hero needs to go right
    memcpy(temp, mat, sizeof mat);
    clean_hero(n);
    for(int i=0;i<3;++i){
        for(int j=0;j<MAX_N-2;++j){
            if(temp[i+1][j+1]==HERO){
                if(temp[i+1][j+2]==VALID){
                    mat[i+1][j+2] = HERO;
                    if(i>0 && temp[i][j+2]==VALID){
                        mat[i][j+2] = HERO;
                    }
                    if(i+2<=3 && temp[i+2][j+2]==VALID){
                        mat[i+2][j+2] = HERO;
                    }
                }
            }
        }
    }
}

void move_train(int n){
    //Move every train +2 to the left
    for(int i=0;i<3;++i){
        for(int j=0;j<MAX_N-1;++j){
            if(mat[i+1][j+1]==REKT){
                if(j-1>=0)  mat[i+1][j-1] = REKT;
                mat[i+1][j+1] = VALID;
            }
        }
    }
}

ii rekt_count(int n){
    //Cound the amount of cells occupied by trains
    //and heroes
    int train = 0, hero = 0;
    for(int i=0;i<3;++i){
        for(int j=0;j<MAX_N-1;++j){
            if(mat[i+1][j+1]==REKT) ++train;
            if(mat[i+1][j+1]==HERO) ++hero;
        }
    }
    return ii(train,hero);
}

int main(){
    char line[MAX_N];
    int n,t,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        memset(mat, VALID, sizeof mat);
        init(n);

        for(int i=0;i<3;++i){
            cin>>line;
            for(int j=0;j<n;++j){
                if(line[j]=='.'){
                    mat[i+1][j+1] = VALID;
                }else if(line[j]=='s'){
                    mat[i+1][j+1] = HERO;
                }else{
                    mat[i+1][j+1] = REKT;
                }
            }
        }

        //end as soon as all the trains are gone, and if
        //there still is a hero, then he managed to win :)
        ii state = rekt_count(n);
        int max_it = (MAX_N)<<1;
        while(state.first > 0 && max_it--){
            move_hero(n);
            move_train(n);
            state = rekt_count(n);
        }

        if(state.second > 0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
