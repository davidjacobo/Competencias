import java.util.Scanner;
import java.math.BigInteger;

public class pro3080{
    public static void main(String[] args){
        pro3080 exe = new pro3080();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        BigInteger A,B,C,D;
        int N = l.nextInt();
        char op;
        boolean fail;

        while(N-->0){
            A = l.nextBigInteger();     
            op = l.next().charAt(0);
            B = l.nextBigInteger();
            l.next();
            D = l.nextBigInteger();
            fail = false;            

            C = BigInteger.ZERO;
            if(op=='/'){
                if(B.equals(BigInteger.ZERO)){
                    fail = true;
                } else {    
                    C = A.divide(B);
                }
            } else if(op=='+'){
                C = A.add(B);
            } else if(op=='-'){
                C = A.subtract(B);
            } else {
                C = A.multiply(B);
            }

            if(fail || !C.equals(D)) System.out.println("No");
            else System.out.println("Yes");
        }
    }
}
