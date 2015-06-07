#include <cstdio>
#define MAX_N 10001
using namespace std;

int cmp[MAX_N], siz[MAX_N];

int find(int x){
	if(x==cmp[x]) return x;
	return cmp[x] = find(cmp[x]);
}

int main(){
	int v,e, T,x,y,cmp_x,cmp_y;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&v,&e);

		for(int i=1;i<=v;++i){
			cmp[i] = i;
			siz[i] = 0;
		}

		int sets = v;
		for(int i=0;i<e;++i){
			scanf("%d %d",&x,&y);
			cmp_x = find(x);
			cmp_y = find(y);
			if(cmp_x!=cmp_y){
				--sets;
				if(siz[cmp_x] > siz[cmp_y]){
					cmp[cmp_y] = cmp_x;
					siz[cmp_x]+= siz[cmp_y];
				} else {
					cmp[cmp_x] = cmp_y;
					siz[cmp_y]+= siz[cmp_x];
				}
			} 
		}

		sets = (sets*(sets-1))>>1;
		printf("%d\n", sets);
	}
	return 0;
}