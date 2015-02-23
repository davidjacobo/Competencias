/*
 * Dfs with cycle detection
 * This code tells if a graph can be bi-colored or not
*/

import java.util.Scanner;

public class pro2927{
    boolean fuckit;
    int[] color;
    int[] time;
    public static void main(String[] args){
        pro2927 exe = new pro2927();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        int N,M;
        int x,y;

        N = l.nextInt();
        M = l.nextInt();
        Node[] graph = new Node[N];
        color = new int[N];
        time = new int[N];

        for(int i=0;i<N;i++){
            color[i] = 0;
            time[i] = 0;
        }

        for(int i=0;i<M;i++){
            x = l.nextInt()-1;
            y = l.nextInt()-1;
            insert(graph, x, y);
            insert(graph, y, x);
        }
        
        fuckit = false;
        for(int i=0;i<N;i++){
            if(color[i]==0){
                dfs(graph, i, 0);
            }
        }

        if(fuckit) System.out.println("NO");
        else System.out.println("YES");
    }

    void dfs(Node[] graph, int v, int deep){
        if(fuckit) return;
        color[v] = 1;
        time[v] = deep;

        Node t = graph[v];
        while(null != t){
            if(color[t.y]==0) {
                dfs(graph, t.y, deep+1);
            } else if(color[t.y]==1) {
                if( (deep - time[t.y])%2==0 ) {
                    fuckit = true;
                    return;
                }
            }
    
            t = t.next;
        }

        color[v] = 2;
    }

    void insert(Node[] graph, int x, int y){
        Node t = graph[x];
        graph[x] = new Node(y);
        if(null != t)
            graph[x].next = t;
    }
}

class Node{
    Node(int _y){
        y = _y;
        next = null;
    }

    Node next;
    int y;
}
