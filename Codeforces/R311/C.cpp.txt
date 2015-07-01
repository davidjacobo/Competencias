#include <iostream>
#include <cstring>
#include <queue>
#define MAX_N 100001

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
int energy[MAX_N], altura[MAX_N], total;
int rep_altura[MAX_N], rep_energy[MAX_N];
vi graph[MAX_N];

int solve(int n){
	vi vec;
	priority_queue<int> pq;
	int ans = 0;

	//we must select an altura, t patas, then choose t-1 patas with max sum(altura)
	for(int i=0;i<MAX_N;++i){
		if(rep_altura[i]==0) continue;

		//find the maximum di over the elements < i
		int it = rep_altura[i]-1;
		int sum = rep_energy[i], j=0;
		vec.clear();

		while(!pq.empty() && j<it){
			sum+= pq.top();
			vec.push_back(pq.top());
			pq.pop();
			++j;			
		}

		ans = max(ans, sum);

		for(j=0;j<graph[i].size();++j){
			pq.push(graph[i][j]);
		}
		for(j=0;j<vec.size();++j){
			pq.push(vec[j]);
		}
	}

	return total - ans;
}

int main(){
	int n;
	cin>>n;

	memset(rep_altura, 0, sizeof rep_altura);
	memset(rep_energy, 0, sizeof rep_energy);
	for(int i=0;i<n;++i){
		cin>>altura[i];
		++rep_altura[altura[i]];
	}
	for(int i=0;i<n;++i){
		cin>>energy[i];
		rep_energy[altura[i]]+= energy[i];
		graph[altura[i]].push_back(energy[i]);
		total+= energy[i];
	}

	if(n==1){
		cout<<0<<endl;
	} else if(n==2){
		if(altura[0]==altura[1])
			cout<<0<<endl;
		else
			cout<<min(energy[0], energy[1])<<endl;
	} else{
		cout<<solve(n)<<endl;
	}
	return 0;
}