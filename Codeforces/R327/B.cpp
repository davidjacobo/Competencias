#include <iostream>
#define MAX_N 200001

using namespace std;

char tab[27], cad[MAX_N];

void init() {
	for(int i=0;i<26;++i)
		tab[i] = i+'a';
}

void print_table() {
	for(int i=0;i<26;++i)
		cout<<tab[i];
	cout<<endl;
}

int where_is(char key){
	for(int i=0;i<26;++i)
		if(tab[i]==key) return i;
	return 0;
}

int main() {
	int m,n;
	char a,b,t;
	cin>>n>>m;
	cin>>cad;
	init();

	for(int i=0;i<m;++i) {
		cin>>a>>b;
		int ia = where_is(a);
		int ib = where_is(b);
		
		tab[ia] = b;
		tab[ib] = a;

	}

	for(int i=0;i<n;++i) {
		cout<<tab[cad[i]-'a'];
	}
	cout<<endl;
	return 0;
}