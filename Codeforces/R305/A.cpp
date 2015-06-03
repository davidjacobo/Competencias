#include <iostream>
#include <cstring>
#define MAX_N 1001

using namespace std;
char line[MAX_N];
int len,k;

bool valid_palindrome(int i,int j){
    for(;i<=j;++i,--j){
        if(line[i]!=line[j]) return false;
    }
    return true;
}

bool palindrome(){
    int siz = len / k;
    for(int i=0;i<k;++i){
        if(!valid_palindrome(i*siz, i*siz+siz-1))
            return false;
    }
    return true;
}

int main(){
    cin>>line>>k;
    len = strlen(line);
    if(len%k!=0 || !palindrome()) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
    }
    return 0;
}
