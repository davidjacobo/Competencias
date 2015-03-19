import java.util.Scanner;

public class Paper{
    public static void main(String[] args){
        Paper exe = new Paper();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        long a,b,min,max,div, counter = 0;
        min =  a = l.nextLong();
        b = l.nextLong();

        while(a!=b){
            min = Math.min(a,b);
            max = Math.max(a,b);
            if(min==0) break;   

            div = max/min;
            a = min;
            b = max-a*div;
            counter+= div;
        }
        System.out.println(counter);
    }
}
