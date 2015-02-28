import java.util.Scanner;
import java.util.HashMap;

public class Compilation{
    public static void main(String[] args){
        Compilation exe = new Compilation();
        exe.begin();
    }

    void begin(){
//        HashMap<Integer,Integer> hs = new HashMap<Integer,Integer>();
        Scanner l = new Scanner(System.in);
        int N = l.nextInt(),t;
        long total = 0;

        for(int i=0;i<N;i++){
            t = l.nextInt();
            total+= t;
       }

        long sum = 0;
        for(int i=0;i<N-1;i++)
            sum+= l.nextInt();

        System.out.println(total-sum);

        total = 0;
        for(int i=0;i<N-2;i++)
            total+= l.nextInt();
        System.out.println(sum-total);
    }
}
