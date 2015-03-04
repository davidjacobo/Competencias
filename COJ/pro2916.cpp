#include <stdio.h>
#include <map>
#include <cmath>

using namespace std;
std::map<int, bool> tree;
bool fail;

void factors(int n){
    int root = sqrt(n)+1;
    
    while(!(n&1)){
        if(tree[2])
            fail = true;
        tree[2] = true;
        n>>=1;
    }

    int div = 3;
    while(div <= root){
        if(n%div==0){
            if(tree[div]) 
                fail = true;

            tree[div] = true;
            n= n/div;
            root = sqrt(n)+1;
        } else {
            div+= 2;
        }
    }

    if(1!=n){
        if(tree[n])
            fail = true;
        tree[n] = true;
    }
}

int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        tree.clear();
        fail = false;
        factors(a);
        factors(b);

        if(fail)
            printf("NO\n");
        else 
            printf("YES\n");
    }
    return 0;
}
