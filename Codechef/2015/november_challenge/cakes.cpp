#include <cstdio>
using namespace std;

int gcd(int a,int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int m,n,t,ans;
	scanf("%d",&t);

	while(t--) {
		scanf("%d %d",&n,&m);
		if(m==0) {
			ans = 1;
		} else {
			ans = gcd(n,m);
			ans = n/ans;
		}

		if(ans == n) {
			printf("Yes\n");
		} else {
			printf("No %d\n", ans);
		}
	}
	return 0;
}