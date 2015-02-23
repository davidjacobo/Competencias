import java.util.Scanner;

public class pro2709{
    public static void main(String[] args){
        pro2709 exe = new pro2709();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        int N, M;

        N = l.nextInt();
        M = l.nextInt();
        boolean[] filler = new boolean[N+1];
        for(int i=0;i<=N;i++) filler[i] = false;
        int t;
        while(M-->0){
            t = l.nextInt();
            if(filler[t]) continue;  
            filler[t] = true;
            N--;
        }

        System.out.println(N);
    }
}
