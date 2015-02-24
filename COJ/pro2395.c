#include <stdio.h>
#include <stdlib.h>

int minimo(int a,int b){
    return (a<b)?a:b;
}

int maximo(int a,int b){
    return (a>b)?a:b;
}

void build_tree(int *arr,int *tree_min,int *tree_max,int id,int p,int q){
    if(p>q) return;
    if(p==q){
        tree_min[id] = tree_max[id] = arr[p];
        return;
    }
    int i, min, max;
    min = 2000000;
    max = 0;

    for(i=p;i<=q;i++){
        min = minimo(min, arr[i]);
        max = maximo(max, arr[i]);
    }
    tree_min[id] = min;
    tree_max[id] = max;
    int m = (p+q)/2;

    build_tree(arr, tree_min, tree_max, id<<1, p, m);
    build_tree(arr, tree_min, tree_max, (id<<1)+1, m+1, q);
}

void query(int *tree_min,int *tree_max, int id, int p,int q,int x,int y,int *min,int *max){
    //printf("%d - %d\n",p,q);
    if(x==p && y==q) {
        *min = minimo(*min, tree_min[id]);
        *max = maximo(*max, tree_max[id]);
        return;
    }
    int m = (p+q)/2;
    if(x > m) {
        query(tree_min, tree_max, (id<<1)+1, m+1, q, x, y, min, max);
    } else if(y <= m){
        query(tree_min, tree_max, id<<1, p  , m, x, y, min, max);
    } else {
        query(tree_min, tree_max, id<<1, p, m, x, m, min, max);
        query(tree_min, tree_max, (id<<1)+1, m+1, q, m+1, y, min, max);
    }
}

int main(){
    int *p,*tree_min,*tree_max, min, max;
    int N,Q,i,x,y;
    scanf("%d %d",&N,&Q);
    p = (int *)malloc(sizeof(int)*N);
    tree_min = (int *)malloc(sizeof(int)*(N<<2));
    tree_max = (int *)malloc(sizeof(int)*(N<<2));

    i = 0;
    while(i++<N){
        scanf("%d",&p[i-1]);
    }    

    build_tree(p ,tree_min, tree_max ,1 ,0 ,N-1);

    i=0;
    while(i++<Q){
        scanf("%d %d",&x,&y);
        x--; y--;
        min = 2000000;
        max = 0;
        query(tree_min, tree_max, 1, 0, N-1, x, y,&min,&max);
        printf("%d\n",max-min);
    }

    //rek sheit
    free(p);
    free(tree_min);
    free(tree_max);
    return 0;
}
