#include <iostream>
#include <map>
#define MAX_N 10000001
#define MOD 1000000007
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> ii;
 
int A[MAX_N];
int st[MAX_N<<2];
ll a,b,c,d,e,f;
ll r,s,t;
int N,K,Q;
ll Lm, Dm, m;
ll L1, La, Lc, D1, Da, Dc;
 
int build_tree(int ind,int p,int q){
    if(p==q){
        return st[ind] = A[p];
    }
 
    int  m = (p+q)>>1;
    int left = ind<<1;
    int right = left+1;
 
    left = build_tree(left, p, m);
    right = build_tree(right, m+1, q);
    return st[ind] = min(left, right);
}
 
int query_st(int ind,int p,int q,int i,int j){
    if(i==p && j==q)
        return st[ind];
 
    int m = (p+q)>>1;
    int left = ind<<1;
    int right = left+1;
    if(i > m){
        return query_st(right, m+1, q, i, j);
    } else if(j <= m){
        return query_st(left, p, m, i, j);
    } else {
        return min(query_st(left,p,m,i,m), query_st(right,m+1,q,m+1,j));
    }
}
 
void build_A(){
    A[0] = 0;
    ll t_mod = t % s;
    t_mod = (t_mod * t_mod) % s;
    for(int x=2;x<=N;++x){
        if(t_mod <= r)
            //A[x] = (int)((A[x-1]*(((ll)(a*A[x-1])%m) + b) + c) % m);
            //A[x] = (int)(A[x-1]*(a*A[x-1]+b)%m+c)%m;
            //A[x] = (int)((A[x-1]%m)*(((a*A[x-1])%m) + (b%m))%m+(c%m))%m;
            A[x] = (int)( ( (a%m)*(((A[x-1]%m)*(A[x-1]%m))%m) + (b%m)*(A[x-1]%m)%m + (c%m) ) % m);
        else
            //A[x] = (int)((A[x-1]*(((ll)(d*A[x-1])%m) + e) + f) % m);
            //A[x] = (int)(A[x-1]*(d*A[x-1]+e)%m+f)%m;
            //A[x] = (int)((A[x-1]%m)*(((d*A[x-1])%m) + (e%m))%m+(f%m))%m;
            A[x] = (int)( ( (d%m)*(((A[x-1]%m)*(A[x-1]%m))%m) + (e%m)*(A[x-1]%m)%m + (f%m) ) % m);
 
        t_mod = ((t_mod%s) * (t%s)) % s;
    }   
}
 
void queries(){
    int L,R,temp;
    ll sum = 0, mul = 1;
    build_tree(1,1,N);
    map<ii, int> el_senior_mapa; 
 
    for(int i=1;i<=Q;++i){
        L1 = ((La%Lm) * (L1%Lm) + (Lc%Lm)) % Lm;
        D1 = ((Da%Dm) * (D1%Dm) + (Dc%Dm)) % Dm;
    
        L = L1 + 1;
        R = min((int)(L + K + D1 -1), N);    
    //cout<<"range "<<L<<" : "<<R<<endl;
 
    if(el_senior_mapa.count(ii(L,R))>0){
        temp = el_senior_mapa[ii(L,R)];
    } else {
        temp = query_st(1,1,N,L,R);
        el_senior_mapa[ii(L,R)] = temp;
    }
 
        sum+= temp;
        mul = ((mul%MOD) * (temp%MOD)) % MOD;
    }   
    cout<<sum<<" "<<mul<<endl;
}
 
int main(){
    cin>>N>>K>>Q;
    cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>A[1];
    cin>>L1>>La>>Lc>>Lm>>D1>>Da>>Dc>>Dm;
 
    build_A();   
    queries();
    return 0;
}
