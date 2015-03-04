#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cmath>
int nums[101];

using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int n,i,t,j;

    i = 0;
    while(scanf("%d",&t)!=EOF){
        //if(t<=0) break;
        nums[i++] = t;
    }

    n = i;
    sort(nums, nums+n);
    int max_gcd = 1;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            t = gcd(nums[j],nums[i]);
            max_gcd = max(max_gcd, t);
        }
    }

    printf("%d\n", max_gcd);
    return 0;
}
