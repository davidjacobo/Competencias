#include <iostream>
#include <fstream>
#include <cstdlib>
#define MAX_N 21
using namespace std;
int num[MAX_N];

int sum_arr(int n){
    int ans = 0;
    for(int i=0;i<n;++i) ans+= num[i];
    return ans;
}

int sum_bits(int numero,int n){
    int ans = 0;
    for(int i=0;i<n;++i){
        if(numero&(1<<i)) ans+= num[i];
    }
    return ans;
}

int main(){
    int n,ind, i, sum;
    char car, line[10];
    cin>>n;
    cin.get(car);

    ind=i=0;
    while(n--){
        while(1){
            cin.get(car);
            if(car=='\n') {
                line[ind] = '\0';
                num[i++] = atoi(line);
                sum = sum_arr(i);
                if(sum&1){
                    cout<<"NO"<<endl;
                } else {
                   sum>>=1;
                    bool win = false;
                   for(int numero=0;numero<(1<<i);++numero){
                        if(sum_bits(numero, i)==sum){
                            win = true;
                            break;
                        }
                   }

                    if(win) {
                        cout<<"YES"<<endl;
                    } else {
                        cout<<"NO"<<endl;
                    }
                }

                ind = i = 0;
                break;
            }

            if(car==' '){   
                line[ind] = '\0';
                num[i++] = atoi(line);   
                ind = 0;
            } else {
                line[ind++] = car;
            }
        }
    }
    return 0;
}
