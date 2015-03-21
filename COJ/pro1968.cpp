#include <iostream>
#include <vector>
#include <queue>
#define MAX_K 5
#define MAX_N 10000
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
typedef priority_queue<ii> pii;
typedef vector<ii> vii;
int ks[MAX_K];
bool seen[MAX_N];
int distances[MAX_N][MAX_K];
vii graph[MAX_N];
int global_min;

void clean(int n,int k){
    int i,j;
    for(j=0;j<n;j++){
        for(i=0;i<k;i++){
            distances[j][i] = INF;
        }
        graph[i].clear();
    }
}

void dijkstra(int dim, int n){
    pii pq;
    int v = ks[dim]-1;
    int d, y;
    distances[v][dim] = 0;

    for(int i=0;i<n;i++)
        seen[i] = false;

    while(!seen[v]){
        seen[v] = true;
        for(int i=0;i<graph[v].size();i++){
            d = graph[v][i].first;
            y = graph[v][i].second;

            if(distances[v][dim] + d < distances[y][dim]){
                distances[y][dim] = distances[v][dim] + d;
                pq.push(ii(-distances[y][dim], y));
            } 
        }

        while(!pq.empty()){
            v = pq.top().second;
            pq.pop();
            if(!seen[v]) break;
        }
    }
}

bool on_arr(int arr[],int key,int k){
    for(int i=0;i<k;i++)
        if(arr[i]==key) return true;
    return false;
}

bool on_ks(int key,int K){
    for(int i=0;i<K;i++){
        if(ks[i]==key) return true;
    }
    return false;
}

void calc_trip(int arr[],int k,int N){
    int total = 0;
    int x,y;
    //cout<<"trip: "<<ks[arr[1]]-1;
    for(int i=2;i<=k;i++){
        x = ks[arr[i-1]]-1;
        y = ks[arr[i]]-1;
        //cout<<" "<<y<<" +"<<distances[arr[i-1]][y];
        total+= distances[y][arr[i-1]];
    }
    //cout<<" between perm: "<<total<<" ";

    //whats gonna be the starting/ending vertex?
    //well, at least nothing included on ks...
    int min = INF<<1;
    for(int i=0;i<N;i++){
        if(!on_ks(i+1, k)){
            min = (min<distances[i][arr[1]] + distances[i][arr[k]])?min:distances[i][arr[1]]+distances[i][arr[k]];
        }
    }
    total+= min;
    //cout<<"total: "<<total<<endl;
    global_min = (total < global_min)?total:global_min;
}

void backtrack(int arr[],int k,int n,int N){
    if(k==n){
        calc_trip(arr, n, N);
    } else {
        k++;
        for(int i=0;i<n;i++){
            if(on_arr(arr, i, k)) continue;
            arr[k] = i;
            backtrack(arr, k, n, N);
        }
    }
}

int main(){
    int n,m,k,i;
    int x,y,d, temp[MAX_K+1];
    cin>>n>>m>>k;
    clean(n,k);
    
    i = k;
    while(i--){
        cin>>ks[i];
    }

    i = m;
    while(i--){
        cin>>x>>y>>d;
        x--;
        y--;
        graph[x].push_back(ii(d,y));
        graph[y].push_back(ii(d,x));
    }

    i = k;
    while(i--){
        dijkstra(i, n);
    }

    temp[0] = -1;
    global_min = INF<<1;
    backtrack(temp, 0, k, n);

    cout<<global_min<<endl;
    return 0;
}
