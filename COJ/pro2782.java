/*
 *  dfs 
 *  sometimes judges are just playing around with data
 *  for this scenario a dfs with prune works, switching the goal
 *  and the starting point
*/

import java.util.Scanner;

public class pro2782{
    boolean[][] maze = new boolean[10][10];
    int minDis;
    public static void main(String[] args){
        pro2782 exe = new pro2782();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        int N, x0, y0, x1, y1;
        String line;
        N = l.nextInt();

        x1 = x0 = y0 = y1 = -1;
        for(int i=0;i<N;i++){
            line = l.next();
            for(int j=0;j<N;j++){
                if(line.charAt(j)=='#'){
                    x0 = i;
                    y0 = j;
                    maze[i][j] = true;
                } else if(line.charAt(j)=='m'){
                    x1 = i;
                    y1 = j;
                    maze[i][j] = true;
                } else if(line.charAt(j)=='.'){
                    maze[i][j] = true;
                } else {
                    maze[i][j] = false;
                }
            }
        }

        if(x1==-1 || x0==-1) {
            System.out.println(-1);
        } else {
            minDis = 2000000000;
            dfs(x0, y0, x1, y1, N, 0);
            if(minDis == 2000000000) {
                System.out.println(-1);
            } else {
                System.out.println(minDis);
            }
        }
    }

    void dfs(int x0,int y0,int x1,int y1,int N,int deep){
        if(deep > minDis) return;
        if(x1==x0 && y1==y0) {
            minDis = Math.min(minDis, deep);
            return;
        }

        maze[x0][y0] = false;
        
        if(x0-1 >= 0 && maze[x0-1][y0])
            dfs(x0-1, y0, x1, y1, N, deep+1);
        if(x0+1 < N && maze[x0+1][y0])
            dfs(x0+1, y0, x1, y1, N, deep+1);
        if(y0-1 >= 0 && maze[x0][y0-1])
            dfs(x0, y0-1, x1, y1, N, deep+1);
        if(y0+1 < N && maze[x0][y0+1])
            dfs(x0, y0+1, x1, y1, N, deep+1);

        maze[x0][y0] = true;
    }
}
