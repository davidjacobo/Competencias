import java.util.Scanner;

public class pro2958{
    int[][] mat = new int[3001][3001];
    public static void main(String[] args){
        pro2958 exe = new pro2958();
        exe.begin();
    }
        
    void preProcess(){
        int i,j;
        int mod = 1000000007;
        for(i=0;i<3001;i++)
            mat[i][0] = mat[i][i] = 1;

        for(i=2;i<3001;i++)
            for(j=1;j<i;j++)
                mat[i][j] = (mat[i-1][j]+mat[i-1][j-1])%mod;
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        int N,t,n;
        double root;

        preProcess();
        N = l.nextInt();
        while(N-->0){
            n = t = l.nextInt();
            root = (double)(Math.ceil(Math.log(t+0.1)/Math.log(2.0)-1));

            n = (int)(Math.pow(2.0, root));
            t = (n<<1)-1-t;
            //System.out.println("n "+n+" k "+t);
            System.out.println(mat[n][t]-1);
        }
    }
}
