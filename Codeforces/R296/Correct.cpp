#include <iostream>
#include <cstring>
using namespace std;
bool mat[26][26], usedS[26], usedT[26];
int indexS[26], indexT[26];
char S[200001], T[200001];

void clean(){
    for(int i=0;i<26;i++){
        usedS[i] = usedT[i] = false;
        for(int j=0;j<26;j++)
            mat[i][j] = false;
    }
}

void look_shit(int a,int b,int *carA,int *carB,bool first){
    int len = strlen(S);

    for(int i=0;i<len;i++){
        if(S[i]!=T[i]){
            if((S[i]-'a')==a && (T[i]-'a')==b){
                if(first){
                    *carA = i+1;
                    look_shit(b,a,carA,carB,false);
                    return;
                } else {
                    *carB = i+1;
                    return;
                }
            }
        }
    }
}

void solve(int *a,int *b,int *counter){
    for(int i=0;i<26;i++)
        for(int j=0;j<i;j++)
            if(mat[i][j] && mat[i][j]==mat[j][i]){
                look_shit(i,j,a,b,true);
                (*counter)-= 2;
                return;
            }

    for(int i=0;i<26;i++){
        if(usedS[i] && usedT[i]){
            *a = indexS[i];
            *b = indexT[i];
            (*counter)--;
            return;
        } 
    }
}

int main(){
    int n, counter = 0, a, b, len;
    cin>>n;
    cin>>S>>T;
    len = strlen(S);
    clean();

    for(int i=0;i<len;i++){
        counter+= (S[i]==T[i])?0:1;
        a = S[i]-'a';
        b = T[i]-'a';
        if(S[i]!=T[i]){
            usedS[a] = usedT[b] = true;
            indexS[a] = indexT[b] = i+1;
            mat[a][b] = true;
        }
    }
    
    a = b = -1;
    solve(&a, &b, &counter);
    cout<<counter<<endl;
    cout<<a<<" "<<b<<endl;
    

    return 0;
}
