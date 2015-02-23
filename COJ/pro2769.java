import java.util.Scanner;

public class pro2769{
    public static void main(String[] args){
        pro2769 exe = new pro2769();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        int N = l.nextInt();
    
        for(int i=1;i<=N;i++)
            System.out.println(i+": I am participating in the Engineer's day.");
    }
}
