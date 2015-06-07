#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX_N 101

using namespace std;
typedef long long ll;

int main(){
	char line[MAX_N];
	int T, len;
	ll n;

	cin>>T;
	while(T--){
		scanf("%lld %s",&n,line);
		len = strlen(line);

	 	int counter = 0;
	 	int i = n%len;
	 	i = (len-i)%len;
		while(counter++<len){
			printf("%c",line[i]);
			i = (i+1)%len;
		}
		printf("\n");
	}
	return 0;
}