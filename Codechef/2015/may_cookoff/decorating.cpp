#include <iostream>
#include <cstring>
#include <cmath>
#define MAX_LEN 100001
using namespace std;

int first_empty(char line[],int len){
    for(int i=0;i<len;++i)  
        if(line[i]=='0') return i;
    return -1;
}

int main(){
    char line[MAX_LEN];
    int T,len, rep[26], car, ind;

    cin>>T;
    while(T--){
        cin>>line;
        len = strlen(line);
        memset(rep, 0, sizeof(rep));

        int max_rep = 0;
        for(int i=0;i<len;++i){
            rep[line[i]-'a']++;
            if(rep[line[i]-'a'] > max_rep)
                max_rep = rep[line[i]-'a'];
        }

        if(max_rep > ceil(len/2.0)) {
            cout<<-1<<endl;
        } else {
            memset(line, '0', sizeof(line));
            ind = 0;
          
            do{
                max_rep = 0;
                for(int i=0;i<26;++i){
                    if(rep[i]>max_rep){
                        max_rep = rep[i];
                        car = i;
                    }           
                }

                while(rep[car]){
                    line[ind] = (char)(car+'a');

                    ind+=2;
                    if(ind >= len)
                        ind = first_empty(line, len);     
                    --rep[car];
                } 
            }while(max_rep);
            line[len] = '\0';   
            cout<<line<<endl;
        }

        
    }
    return 0;
}
