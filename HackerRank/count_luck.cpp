#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_N 102
using namespace std;
typedef pair<int,int> ii;
char mat[MAX_N][MAX_N];
bool seen[MAX_N][MAX_N];
ii parent[MAX_N][MAX_N];
int x_start, y_start, x_end, y_end;
int add_x[] = {0,0,1,-1};
int add_y[] = {1,-1,0,0};

void capture(int& m,int& n) {
    cin>>m>>n;
    for(int i=0;i<MAX_N;++i) for(int j=0;j<MAX_N;++j) mat[i][j] = 'X';
    
    string input;
    for(int i=0;i<m;++i) {
        cin>>input;
        for(int j=0;j<n;++j) {
            mat[i+1][j+1] = input[j];
            if(input[j]=='*') {
                mat[i+1][j+1] = '.';
                x_end = i+1;
                y_end = j+1;
            } else if(input[j]=='M') {
                mat[i+1][j+1] = '.';
                x_start = i+1;
                y_start = j+1;
            }
        }
    }
}

void dfs(int x,int y) {
    seen[x][y] = true;
    int x1,y1;
    
    for(int i=0;i<4;++i) {
        x1 = x+add_x[i];
        y1 = y+add_y[i];
        if(!seen[x1][y1] && mat[x1][y1]=='.') {
            parent[x1][y1].first = x;
            parent[x1][y1].second = y;
            dfs(x1,y1);
        }
    }
}

int degree(int x,int y) {
    int ans = 0;
    for(int i=0;i<4;++i) {
        int x1 = x + add_x[i];
        int y1 = y + add_y[i];
        if(mat[x1][y1]=='.') ++ans;
    }
    return ans;
}

int count_ways(int x,int y) {
    int ans = 0, i,j;
        i = parent[x][y].first;
        j = parent[x][y].second;
        x = i;
        y = j;
    
    while(x!=-1 && y!=-1) {
        ans+= (degree(x,y)-2 >0)?1:0;
        i = parent[x][y].first;
        j = parent[x][y].second;
        x = i;
        y = j;
    }
    
    if(degree(x_start, y_start)==2) ++ans;
    return ans;
}

void clean() {
    for(int i=0;i<MAX_N;++i) 
        for(int j=0;j<MAX_N;++j) {
            parent[i][j].first = -1;
            parent[i][j].second = -1;
            seen[i][j] = false;
        }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,m,n;
    cin>>t;
    while(t--) {
        capture(m,n);
        //fill(seen[0][0], seen[MAX_N][0], 0);
        clean();
        dfs(x_start, y_start);
        m = count_ways(x_end,y_end);
        //cout<<"caminos "<<m<<endl;
        cin>>n;
        if(m==n) {
            cout<<"Impressed"<<endl;
        } else {
            cout<<"Oops!"<<endl;
        }
    }
    return 0;
}
