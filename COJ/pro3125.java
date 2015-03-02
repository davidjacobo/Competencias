import java.util.Scanner;

public class pro3125{
    public static void main(String[] args){
        pro3125 exe = new pro3125();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        String line = l.next();
        int len = line.length();
        int i=0;
        if(len%3==1){
            System.out.printf("%s", toOctal(line, 0, 1));
            i = 1;
        } else if(len%3==2){
            System.out.printf("%s", toOctal(line, 0, 2));
            i = 2;
        } 

        for(;i<len;i+=3){
            System.out.printf("%s", toOctal(line, i, i+3));
        }
        System.out.println();
    }

    String toOctal(String line, int p,int q){
        int n = Integer.parseInt(line.substring(p,q), 2);
        return Integer.toString(n, 8);
    }
}
