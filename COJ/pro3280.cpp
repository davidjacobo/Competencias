#include <cstdio>
#define MAX_N 14143
using namespace std;
int book_size;

int binary(int s){
        int p = 0, q = MAX_N, m;
            int pages, pages2;

                while(p<=q){
                            book_size = m = (p+q)>>1;

                                    pages = (m*(m+1))>>1;
                                            pages2 = ((m-1)*(m))>>1;

                                                    if(pages==s || (pages > s && pages2 < s)) return pages;
                                                            if(pages > s) q = m-1;

                                                                    else p = m+1;
                                                                        }
                    return pages;
}

int main(){
        char line[1001];
        int s, pages;
            while(1){
                sscanf(gets(line), "%d", &s);
                if(s==0) break;
                        pages = binary(s);
                                if(pages==s) {
                                                printf("%d %d\n",book_size+1, book_size+1);
                                                        } else {
                                                                        printf("%d %d\n",pages-s,book_size);
                                                                                }
                                    }
                return 0;
}
