import java.util.Scanner;

public class pro2701{
    public static void main(String[] args){
        pro2701 exe = new pro2701();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        String line;
        int N;

        line = l.next();
        N = sum(line);
        System.out.println(toCad((int)Math.floor(N/2.0))+" "+toCad((int)Math.ceil(N/2.0)));
    }

    String toCad(int N){
        if(N <=26) {
            return ""+(char)(N+'A'-1);
        } else {
            return 'Z'+toCad(N-26);
        }
    }

    int sum(String line){
        int t=0;
        for(int i=0;i<line.length();i++)
            t+= line.charAt(i)-'A'+1;
        return t;
    }
}
