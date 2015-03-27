#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;

int main(){
    int g,s,b;
    iiii list[7];
    for(int i=0;i<7;i++){   
        scanf("%d %d %d",&g,&s,&b);
        list[i] = iiii(ii(g,s),ii(b,i+1));
    }
    sort(list, list+7);
    for(int i=6;i>-1;i--)
        printf("Facultad %d %d %d %d\n",list[i].second.second, list[i].first.first,
                                        list[i].first.second, list[i].second.first);
    return 0;
}
