import java.util.Scanner;

public class pro2815{
    public static void main(String[] args){
        pro2815 exe = new pro2815();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        String line, pattern;
        int N;

        N = l.nextInt();
        while(N-->0){
            line = l.next()+"*";
            pattern = l.next();

            int index, counter = 0;
            while((index = line.indexOf(pattern)) != -1) {
                line = line.substring(0, index) + line.substring(index + pattern.length(), line.length());          
                counter++;
            }
            System.out.println(counter);
        }
    }
}
