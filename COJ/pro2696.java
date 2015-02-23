import java.util.Scanner;

public class pro2696{
    public static void main(String[] args){
        pro2696 exe = new pro2696();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        int N,M;

        N = l.nextInt();
        M = l.nextInt();
        int[] indegree = new int[N+1];
        boolean[][] set = new boolean[N+1][N+1];
        for(int i=0;i<=N;i++) indegree[i] = 0;
        for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) set[i][j] = false;

        int x,y;
        for(int i=0;i<M;i++){
            x = l.nextInt();
            y = l.nextInt();
            if(set[x][y]) continue;
            set[x][y] = true;
            indegree[x] ++;
        }

        int max = 0;
        for(int i=1;i<=N;i++)
            max = Math.max(max, indegree[i]);
        String output = "";
        for(int i=1;i<=N;i++)
            if(max == indegree[i])
                output+= i+" ";        
        System.out.println(output.substring(0,output.length()-1));
    }
}
