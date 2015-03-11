#include <iostream>

using namespace std;
char mat[10][10];

void build(){
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            mat[i][j] = 0;

    mat[2][2] = 1;
    mat[3][3] = 1;
    mat[4][2] = 2;
    mat[4][3] = 1;
    mat[5][5] = 1;
    mat[6][3] = 1;
    mat[6][5] = 1;
    mat[7][7] = 1;
    mat[8][2] = 3;
    mat[8][7] = 1;
    mat[9][2] = 1;
    mat[9][3] = 2;
    mat[9][7] = 1;
}

void addVals(int *p,int val){
    for(int i=0;i<10;i++)
        p[i]+= mat[val][i];
}

int main(){
    build();
    int n;
    int count[10];
    char cad[16];
    cin>>n>>cad;
    for(int i=0;i<10;i++)   count[i] = 0;

    for(int i=0;i<n;i++)
        addVals(count, cad[i]-'0');

    for(int i=9;i>=0;i--){
        while(count[i]--)
            cout<<(char)(i+'0');
    }
    cout<<endl;
    
    return 0;
}
