import java.util.Scanner;

public class pro2693{
    public static void main(String[] args){
        Scanner l = new Scanner(System.in);
        double n = l.nextDouble();
        int pos = l.nextInt();

        if(pos==0) System.out.printf("%.0f\n", n);
        if(pos==1) System.out.printf("%.1f\n", n);
        if(pos==2) System.out.printf("%.2f\n", n);
        if(pos==3) System.out.printf("%.3f\n", n);
        if(pos==4) System.out.printf("%.4f\n", n);
        if(pos==5) System.out.printf("%.5f\n", n);
        if(pos==6) System.out.printf("%.6f\n", n);
    }
}
