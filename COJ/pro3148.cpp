#include <iostream>
using namespace std;

int main(){
    int n;
    char cad[3];
    cin>>n;
    while(n--){
        cin>>cad;
        cout<<((((cad[0]-'a')&1) == ((cad[1]-'1')&1))?"WHITE":"BLACK")<<endl;
    }
    return 0;
}
