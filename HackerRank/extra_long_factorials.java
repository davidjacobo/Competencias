import java.util.*;
import java.math.*;

public class extra_long_factorials{
    public static void main(String[] args){
        extra_long_factorials exe= new extra_long_factorials();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        int n = l.nextInt();
        BigInteger N = new BigInteger(n+"");

        while(--n>1){
            N = N.multiply(new BigInteger(n+""));
        }
        System.out.println(N.toString());
    }
}
