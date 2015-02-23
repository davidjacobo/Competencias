import java.util.Scanner;
import java.util.StringTokenizer;

public class pro2634{
    public static void main(String[] args){
        pro2634 exe = new pro2634();
        exe.begin();
    }

    void begin(){
        StringTokenizer st;
        Scanner l = new Scanner(System.in);
        int[] count = new int[13];
        int N = l.nextInt();

        for(int i=0;i<13;i++) count[i] = 0;

        while(N-->0){
            l.nextInt();
            st = new StringTokenizer(l.next(), "/");

            st.nextToken();
            count[Integer.parseInt(st.nextToken())]++;
            st.nextToken();
        }

        for(int i=1;i<13;i++)
            System.out.println(i+" "+count[i]);
    }
}
