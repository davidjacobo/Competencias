#include <iostream>

using namespace std;

int main(){
	int min3,min1,min2,max1,max2,max3;
	int n,b,c,d;
	cin>>n;
	cin>>min1>>max1>>min2>>max2>>min3>>max3;

	b = min(max1, n-min2-min3);
	c = min(max2, n-b-min3);
	d = n-b-c;


	cout<<b<<" "<<c<<" "<<d;
	return 0;
}