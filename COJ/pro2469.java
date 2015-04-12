import java.util.Scanner;
import java.util.Hashtable;

public class pro2469{
    int MAX_N = 2501;
    int[] A = new int[MAX_N];
    int[] B = new int[MAX_N];
    int[] last = new int[MAX_N];
    int[] nuevo = new int[MAX_N];
    public static void main(String[] args){
        pro2469 exe = new pro2469();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        Hashtable<String,Integer> ht = new Hashtable<String,Integer>();
        String line;
        int n = l.nextInt();
        for(int i=0;i<n;i++){
            line = l.next();
            ht.put(line, i+1);
            A[i+1] = i+1;
        }

        for(int i=0;i<n;i++){
            line = l.next();
            B[i+1] = ht.get(line);
        }
        
        int ans = 0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                if(B[j]>B[i]) ans++;
        System.out.println(ans+"/"+(n*(n-1))/2);
    }
}
