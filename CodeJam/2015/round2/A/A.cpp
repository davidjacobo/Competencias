#include <iostream>
#define MAX_N 101
using namespace std;
int R,C, addX[] = {1,-1,0,0}, addY[] = {0,0,1,-1};
char mat[MAX_N][MAX_N];

bool can_reach_arrow(int x,int y,int previous){
    if(x<0 || y<0 || x>=R || y>=C) return false;
    if(mat[x][y]!='.') return true;   

    if(mat[x][y]=='.') {
        if(previous==0)
            return can_reach_arrow(x-1,y,previous);
        else if(previous==1) 
            return can_reach_arrow(x+1,y,previous);
        else if(previous==2) 
            return can_reach_arrow(x, y+1, previous);
        else 
            return can_reach_arrow(x,y-1,previous);
    }
}

int solve(int blanks){
    int ans = 0;
    if(R==1 && C==1) {
        if(blanks==1) return 0;
        return -1;
    } else {
        bool flag, native,temp;
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                if(mat[i][j]!='.'){
                    flag = native = temp = false;
                    int x = i, y=j; 

                        temp = can_reach_arrow(x,y+1,2);
                        flag|= temp;
                        if(mat[i][j]=='>')
                            native = temp;

                        temp = can_reach_arrow(x,y-1,3);
                        flag|= temp;
                        if(mat[i][j]=='<')
                            native = temp;

                        temp = can_reach_arrow(x-1,y,0);
                        flag|= temp;
                        if(mat[i][j]=='^')
                            native = temp;

                        temp = can_reach_arrow(x+1,y,1);
                        flag|= temp;
                        if(mat[i][j]=='v')
                            native = temp;

                    if(!flag) return -1;
                    if(!native) ++ans;
                }
            }
        }
    }
    return ans;
}

int main(){
    char line[MAX_N];
    int T, counter = 1, blanks;
    cin>>T;
    while(T--){
        cin>>R>>C;
        blanks = 0;
        for(int i=0;i<R;++i){
            cin>>line;
            for(int j=0;j<C;++j){
                mat[i][j] = line[j];
                if(mat[i][j]=='.') blanks++;
            }
        }

        cout<<"Case #"<<counter++<<": ";
        int ans = solve(blanks);
        if(ans==-1) {
            cout<<"IMPOSSIBLE"<<endl;
        } else {
            cout<<ans<<endl;
        }
    }
    
    return 0;
}
