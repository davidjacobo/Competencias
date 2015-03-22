#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long int lii;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef pair<ii, lii> iil;
typedef map<ii, int> miii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<iil> viil;
viil m_out;


void swap(int *a,int *b){
    *a^= *b;
    *b^= *a;
    *a^= *b;
}

long long int binary(int x,int y){
    int p = 0, q = m_out.size()-1,m;
    int indx, indy;

    while(p<=q){
        m = (p+q)/2;
        indx = m_out[m].first.first;
        indy = m_out[m].first.second;
        if(x==indx && y==indy) return m_out[m].second;
        else if(x < indx)
            q = m-1;
        else if(x > indx)
            p = m+1;
        else{
            //x == indx, are we done? nope
            if(y < indy)
                q = m-1;
            else 
                p = m+1;
        }
    }
    return -1;
}

int dfs(vi graph[],bool seen[],int parent, int v,int N){
    seen[v] = true;
    int y;
    int total = 1;
    for(int i=0;i<graph[v].size();i++){
        y = graph[v][i];
        if(!seen[y])
            total+= dfs(graph,seen, v, y,N);   
    }
    
    //m_out[ii(min(parent, v), max(parent, v))] = total*(N-total);
    if(-1!=parent)
        m_out.push_back(iil(ii(min(parent, v), max(parent, v)), (long long int)total*(N-total)));

    return total;
}

int main(){
    int N, x, y, i;
    scanf("%d",&N);
    vi graph[N];
    vii pair_list;
    bool seen[N];

    for(i=0;i<N;i++) seen[i] = false;

    i = 1;
    while(i<N){
        i++;
        scanf("%d %d",&x,&y);
        x--; y--;
        if(y < x) swap(&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
        pair_list.push_back(ii(x,y));
    }

    dfs(graph,seen, -1, 0, N);
    //need to reduce the access time, probably the vertex
    //list is degenerated or something (sorted?) so it affects
    //the accesing time?

    //Proposal: store shit on a list (indexa,indexb, value)
    //sort and access thru a binary search
    sort(m_out.begin(), m_out.end());
    for(i=0;i<pair_list.size();i++){
        //cout<<m_out[ii(pair_list[i].first, pair_list[i].second)]<<endl;
        x = pair_list[i].first;
        y = pair_list[i].second;
        printf("%lld\n", binary(x,y));
    }
    return 0;
}
