import java.util.Scanner;

public class pro2699{
    public static void main(String[] args){
        Scanner l = new Scanner(System.in);
        double sum = 0;
        for(int i=0;i<30;i++)
            sum+= l.nextInt();
         sum += (double)(sum/30.0);
        System.out.printf("%.3f\n",sum);
    }
}
