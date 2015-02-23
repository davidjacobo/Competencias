import java.util.Scanner;

public class pro2948{
    int[][] mat;
    public static void main(String[] args){
        pro2948 exe = new pro2948();
        exe.begin();
    }

    int digitRoot(int n){
        if(n<10) return n;
        String numero = String.valueOf(n);
        return digitRoot(numero.charAt(0)+numero.charAt(1)-'0'-'0');
    }

    void build(){
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                mat[i][j] = digitRoot(i+j);
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        mat = new int[10][10];
        String line;
        int N = l.nextInt();
        int out,len;
        build();

        while(N-->0){
            out = 0;
            line = l.next();
            len = line.length();
            out = line.charAt(0)-'0';
            for(int i=1;i<len;i++){
                out = mat[out][line.charAt(i)-'0'];
            }

            System.out.println(digitRoot(out));
        }
    }
}
