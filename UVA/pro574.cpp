#include <iostream>
#include <cstring>
#define MAX_N 13

using namespace std;

int rep[MAX_N], num[MAX_N], total_solutions;

int size_rep(){
    int i=1;
    while(rep[i++]);
    return i-2;
}

void look_and_insert(int temp){
    int i=1;
    while(rep[i]){
        if(num[i]==temp) break;
        ++i;
    }
    
    ++rep[i];
    num[i] = temp;
}

void print_sol(int state[],int n){
    bool first = true;
    ++total_solutions;

    for(int i=1;i<=n;++i){
        int bak = state[i];
        while(state[i]>0){
            if(!first) cout<<"+";
            first = false;
            cout<<num[i];           
            --state[i];
        }       
        state[i] = bak;
    }
    cout<<endl;
}   

bool valid(int state[],int n,int m){
    int ans = 0;

    for(int i=1;i<=n;++i){
        ans+= (state[i]*num[i]);
    }
    return ans==m;
}

void backtracking(int state[],int k,int n,int m){
    if(k==n){
        if(valid(state, n, m)){
            print_sol(state, n);
        }
    } else {
        ++k;
        for(int i=rep[k];i>=0;--i){
            state[k] = i;
            backtracking(state, k, n, m);
        }
    }
}

int main(){
    int t,m,n,temp;
    while(1){
        cin>>t>>m;
        if(m==0) break;
        memset(num, 0, sizeof(num));
        memset(rep, 0, sizeof(rep));

        for(int i=0;i<m;++i){
            cin>>temp;
            look_and_insert(temp);
        }

        n = size_rep();

        cout<<"Sums of "<<t<<":"<<endl;
        int state[MAX_N];
        state[0] = 0;
        total_solutions = 0;
        backtracking(state, 0, n, t);
        if(total_solutions==0){
            cout<<"NONE"<<endl;
        }
    }
    return 0;
}
