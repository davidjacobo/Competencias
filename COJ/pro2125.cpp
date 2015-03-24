#include <cstdio>
#include <cmath>
#define MAX_N 100000
using namespace std;
int nega[MAX_N<<2];
int zero[MAX_N<<2];
int A[MAX_N];

char clase(int x){
    if(x==0) return '0';
    if(x > 0) return '+';
    if(x < 0){
        x*= -1;
        if(x&1) return '-';
    }
    return '+';
}

bool same_type(int a,int b){
    if(a==b) return true;
    if(a > 0 && b > 0) return true;
    if(a < 0 && b < 0) return true;
    return false;
}

void build_tree(int ind,int p,int q){
    //Log N levels on a tree with N elements
    //O(N log N) to build the tree
    if(p>q) return;
    if(p==q){
        zero[ind] = nega[ind] = 0;
        if(A[p]==0) {
            zero[ind] = 1;
        } else {
            nega[ind] = (A[p]>=0)?0:1;
        }
        return;
    }

    int negativos = 0, zeroes = 0;
    for(int i=p;i<=q;i++){
        negativos+= (A[i]>=0)?0:1;
        zeroes+= (A[i]==0)?1:0;
    }
    nega[ind] = negativos;
    zero[ind] = zeroes;

    int m = (p+q)/2;
    build_tree(ind<<1    ,p, m);
    build_tree((ind<<1)+1,m+1,q);
}

void update(int ind,int p,int q,int x,int val){
    //Updating just affects a branch on the tree (heap)
    //so it is O(log N) 
    if(p>q) return;
    if(p==q){
        zero[ind] = nega[ind] = 0;
        if(val==0){
            zero[ind] = 1;
        } else if(val<0) {
            nega[ind] = 1;
        } else {
            zero[ind] = nega[ind] = 0;
        }
        A[x] = val;
        return;
    }

    if(val==0){
        zero[ind]++;
        if(A[x]<0)
            nega[ind]--;
    } else if(val<0){
        nega[ind]++;
        if(A[x]==0)
            zero[ind]--;
    } else {
        if(A[x]<0) nega[ind]--;
        if(A[x]==0) zero[ind]--;
    }

    int m = (p+q)/2;
    if(x <= m) update(ind<<1, p, m, x, val);
    else       update((ind<<1)+1,m+1,q,x, val);
}

int query(int ind,int p,int q,int x,int y){
    //Queries shouldn't take that long O(log N)
    if(x==p && y==q){
        if(zero[ind]>0) return 0;
        if(nega[ind]&1) return -nega[ind];
        return 1;
    }

    int m = (p+q)/2, t1, t2;
    if(y <= m) {
        return query(ind<<1    ,p  ,m  ,x  ,y  );
    } else if(x > m) {
        return query((ind<<1)+1,m+1,q  ,x  ,y  );
    } else {
        t1   = query(ind<<1    ,p  ,m  ,x  ,m  );
        t2   = query((ind<<1)+1,m+1,q  ,m+1,y  );
        if(t1==0 || t2==0) return 0;
        if(t1<0 && t2<0) return t1+t2;
        if(t1<0) return t1;
        if(t2<0) return t2;
        return 1;
    }
    return -1;
}

int main(){
    int N, Q;
    char option[10];
    int x,y;
    while(scanf("%d %d",&N,&Q)!=EOF){
        for(int i=0;i<N;i++)
            scanf("%d",&A[i]);
        build_tree(1,0,N-1);
    
        for(int i=0;i<Q;i++){
            scanf("%s %d %d",option,&x,&y);
            if(option[0]=='C'){
                x--;
                //printf("comparing shit-- %d %d\n", A[x], y);  
                if(!same_type(y , A[x])) {
                    update(1,0,N-1,x,y);
                }
            } else {
                x--; y--;
                printf("%c",clase(query(1,0,N-1,x,y)));
            }
        }
        printf("\n");
    }       
    return 0;
}
