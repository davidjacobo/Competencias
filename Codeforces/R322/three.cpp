#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define CLEAR 0
using namespace std;
char mat[101][101];

void print_mat(int n){
    cout<<n<<endl;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
}

bool copy(int i,int j,int x,int y,int side,char car){
    for(int ci=0;ci<x;++ci){
        for(int cj=0;cj<y;++cj){
            if(i+ci>=side || j+cj>=side) return false;

            if(mat[i+ci][j+cj]!=CLEAR){ 
                return false;
            }else{
                mat[i+ci][j+cj] = car;
            }
        }
    }
    return true;
}

void print_stripe(int x,int y,char car){
    for(int i=0;i<x;++i){
        for(int j=0;j<y;++j){
            cout<<car;
        }
        cout<<endl;
    }
}

int main(){
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(x1 > y1) swap(x1,y1);
    if(x2 > y2) swap(x2,y2);
    if(x3 > y3) swap(x3,y3);

    int area = x1*y1+x2*y2+x3*y3;
    int root = (int)sqrt(area);
    if(root*root!=area){
        cout<<-1;
        return 0;
    }else{
        if(y1==y2 && y1==y3 && x1+x2+x3==y1){
            cout<<root<<endl;
            print_stripe(x1,y1,'A');
            print_stripe(x2,y2,'B');
            print_stripe(x3,y3,'C');
            return 0;
        }else{
            memset(mat, CLEAR, sizeof mat);
            copy(0,0,x1,y1,root,'A');
            if(copy(x1,0,x2,y2,root,'B')){
                if(copy(0,y1,x3,y3,root,'C')){
                    print_mat(root);
                    return 0;
                }

                memset(mat, CLEAR, sizeof mat);
                copy(0,0,x1,y1,root,'A');
                copy(x1,0,x2,y2,root,'B');

                if(copy(x1,y2,x3,y3,root,'C')){
                    print_mat(root);
                    return 0;
                }
            }
            
            memset(mat, CLEAR, sizeof mat);
            copy(0,0,x1,y1,root,'A');
            if(copy(x1,0,x2,y2,root,'B')){
                if(copy(0,y1,y3,x3,root,'C')){
                    print_mat(root);
                    return 0;
                }

                memset(mat, CLEAR, sizeof mat);
                copy(0,0,x1,y1,root,'A');
                copy(x1,0,x2,y2,root,'B');

                if(copy(x1,y2,y3,x3,root,'C')){
                    print_mat(root);
                    return 0;
                }
            }

            memset(mat, CLEAR, sizeof mat);
            copy(0,0,x1,y1,root,'A');
            if(copy(x1,0,y2,x2,root,'B')){
                if(copy(0,y1,x3,y3,root,'C')){
                    print_mat(root);
                    return 0;
                }   

                memset(mat, CLEAR, sizeof mat);
                copy(0,0,x1,y1,root,'A');
                copy(x1,0,y2,x2,root,'B');
                if(copy(x1,x2,x3,y3,root,'C')){
                    print_mat(root);
                    return 0;
                }   
            }   

            memset(mat, CLEAR, sizeof mat);
            copy(0,0,x1,y1,root,'A');    
            if(copy(x1,0,y2,x2,root,'B')){
                if(copy(0,y1,y3,x3,root,'C')){
                    print_mat(root);
                    return 0;
                }   

                memset(mat, CLEAR, sizeof mat);
                copy(0,0,x1,y1,root,'A');
                copy(x1,0,y2,x2,root,'B');
                if(copy(x1,x2,y3,x3,root,'C')){
                    print_mat(root);
                    return 0;                                                                                                                         }               
            }  

            swap(x2,x3);
            swap(y2,y3);

            memset(mat, CLEAR, sizeof mat);
            copy(0,0,x1,y1,root,'A');
            if(copy(x1,0,x2,y2,root,'C')){
                if(copy(0,y1,x3,y3,root,'B')){
                    print_mat(root);
                    return 0;
                }

                memset(mat, CLEAR, sizeof mat);
                copy(0,0,x1,y1,root,'A');
                copy(x1,0,x2,y2,root,'C');

                if(copy(x1,y2,x3,y3,root,'B')){
                    print_mat(root);                                                                                                                      return 0;                                                                                                                         }
            }

            memset(mat, CLEAR, sizeof mat);
            copy(0,0,x1,y1,root,'A');
                                                                        if(copy(x1,0,x2,y2,root,'C')){
                                                                                            if(copy(0,y1,y3,x3,root,'B')){
                                                                                                                    print_mat(root);
                                                                                                                                        return 0;
                                                                                                                                                        }

                                                                                                            memset(mat, CLEAR, sizeof mat);
                                                                                                                            copy(0,0,x1,y1,root,'A');
                                                                                                                                            copy(x1,0,x2,y2,root,'C');

                                                                                                                                                            if(copy(x1,y2,y3,x3,root,'B')){
                                                                                                                                                                                    print_mat(root);
                                                                                                                                                                                                        return 0;
                                                                                                                                                                                                                        }
                                                                                                                                                                        }

                                                                                    memset(mat, CLEAR, sizeof mat);
                                                                                                copy(0,0,x1,y1,root,'A');
                                                                                                            if(copy(x1,0,y2,x2,root,'C')){
                                                                                                                                if(copy(0,y1,x3,y3,root,'B')){
                                                                                                                                                        print_mat(root);
                                                                                                                                                                            return 0;
                                                                                                                                                                                            }

                                                                                                                                                memset(mat, CLEAR, sizeof mat);
                                                                                                                                                                copy(0,0,x1,y1,root,'A');
                                                                                                                                                                                copy(x1,0,y2,x2,root,'C');
                                                                                                                                                                                                if(copy(x1,x2,x3,y3,root,'B')){
                                                                                                                                                                                                                        print_mat(root);
                                                                                                                                                                                                                                            return 0;
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                            }

                                                                                                                        memset(mat, CLEAR, sizeof mat);
                                                                                                                                    copy(0,0,x1,y1,root,'A');
                                                                                                                                                if(copy(x1,0,y2,x2,root,'C')){
                                                                                                                                                                    if(copy(0,y1,y3,x3,root,'B')){
                                                                                                                                                                                            print_mat(root);
                                                                                                                                                                                                                return 0;
                                                                                                                                                                                                                                }

                                                                                                                                                                                    memset(mat, CLEAR, sizeof mat);
                                                                                                                                                                                                    copy(0,0,x1,y1,root,'A');
                                                                                                                                                                                                                    copy(x1,0,y2,x2,root,'C');
                                                                                                                                                                                                                                    if(copy(x1,x2,y3,x3,root,'B')){
                                                                                                                                                                                                                                                            print_mat(root);
                                                                                                                                                                                                                                                                                return 0;                                                                                                                         }
                                                                                                                                                                                                                                                }

        }
    }
    cout<<"-1";
    return 0;
}
