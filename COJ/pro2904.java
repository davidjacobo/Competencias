import java.util.Scanner;
import java.math.BigInteger;

public class pro2904{
    public static void main(String[] args){
        pro2904 exe = new pro2904();
        exe.begin();
    }

    void begin(){
        BigInteger big = new BigInteger("0");
        Scanner l = new Scanner(System.in);
        int N;

        N = l.nextInt();
        while(N-->0){
            big = big.add(l.nextBigInteger());
        }

        System.out.println(big.toString());
    }
}
