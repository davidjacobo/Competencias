#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX_N 101
#define MAX_MONEY 10001
#define DIM 2
#define INV -1

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> ii_i;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ii_i> vii_i;
bool hate_mat[MAX_N][MAX_N], seen[DIM][MAX_N];
vi D,P;
vii to_opt;
vii_i components;
int L,R,cmp_sum;

void dfs(int v,int side,int d,int p) {
	seen[side][v] = true;
	int other_side = 1 - side;

	if(side==0) {
		++L;
		cmp_sum+= D[v];
		for(int j=0;j<p;++j) {
			if(hate_mat[v][j] && !seen[other_side][j]) dfs(j, other_side, d, p);
		}
	} else {
		++R;
		cmp_sum+= P[v];
		for(int i=0;i<d;++i) {
			if(hate_mat[i][v] && !seen[other_side][i]) dfs(i, other_side, d, p);
		}
	}
}

int pre_process() {
	int ans = 0;
	to_opt.clear();
	to_opt.push_back(ii(INV,INV));

	for(int i=0;i<components.size();++i) {
		int L = components[i].first.first;
		int R = components[i].first.second;
		int cost = components[i].second;

		ans+= L;
		if(R>L) {
			to_opt.push_back(ii(cost, R-L));
		}

		//swap for the other side
		components[i].first.first = R;
		components[i].first.second = L;
	}

	sort(to_opt.begin(), to_opt.end());
	return ans;
}

int solve(int budget) {
	int last[MAX_MONEY], newr[MAX_MONEY];
	memset(last, INV, sizeof last);
	memset(newr, INV, sizeof newr);
	last[0] = 0;
	//cout<<"Assign memory "<<to_opt.size()<<endl;

	for(int i=1;i<to_opt.size();++i) {
		int cost = to_opt[i].first;
		int earn = to_opt[i].second;
		//cout<<"cost: "<<cost<<" earn: "<<earn<<endl;

		for(int j=0;j<budget;++j) {
			if(last[j]!=INV) {
				int k = cost + j;
				if(k<=budget) {
					newr[k] = max(newr[k], last[j]+earn);
				}

				//we maybe didnt project anything, but still can propagate my previous
				//answers
				newr[j] = max(newr[j], last[j]);
			}
		}

		memcpy(last, newr, sizeof(int)*MAX_MONEY);
	}

	int ans = 0;
	for(int i=0;i<=budget;++i) 
		ans = max(ans, newr[i]);
	return ans;
}

int main() {
	int d,p,r,b,t,x,y;
	cin>>d>>p>>r>>b;
	for(int i=0;i<d;++i) {
		cin>>t;
		D.push_back(t);
	}

	for(int i=0;i<p;++i) {
		cin>>t;
		P.push_back(t);
	}

	memset(hate_mat, false, sizeof hate_mat);
	for(int i=0;i<r;++i) {
		cin>>x>>y;
		--x; --y;
		hate_mat[x][y] = true;
	}

	memset(seen, false, sizeof seen);
	for(int i=0;i<d;++i) {
		if(!seen[0][i]) {
			L = R = cmp_sum = 0;
			dfs(i, 0, d, p);
			components.push_back(ii_i(ii(L,R),cmp_sum));
		}
	}

	for(int i=0;i<p;++i) {
		if(!seen[1][i])
			components.push_back(ii_i(ii(0,1),P[i]));
	}

	//cout<<"Completed component analysis"<<endl;

	int ans = pre_process();
	//cout<<"Pre-process works "<<to_opt.size()<<endl;
	ans+= solve(b);
	cout<<ans<<" ";

	ans = pre_process();
	ans+= solve(b);
	cout<<ans;

	return 0;
}