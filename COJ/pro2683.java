import java.util.Scanner;

public class pro2683{
    public static void main(String[] args){
        Scanner l = new Scanner(System.in);
        int N = l.nextInt();
        int t, base;

        while(N-->0){
            System.out.println(Integer.toString(l.nextInt(), l.nextInt()).toUpperCase());
        }
    }
}
