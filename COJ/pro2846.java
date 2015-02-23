import java.util.Scanner;

public class pro2846{
    public static void main(String[] args){
        pro2846 exe = new pro2846();
        exe.begin();
    }

    int digitSum(String cad){
        int total = 0;
        for(int i=0;i<cad.length();i++)
            total+= cad.charAt(i)-'0';
        return total;
    }

    String add1000(String cad){
        int total = Integer.parseInt(cad) + 1000;
        return String.valueOf(total);
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        int N = l.nextInt();
        String line, total;
        int len;

        while(N-->0){
            line = l.next();
            len = line.length();
            total = String.valueOf(Integer.parseInt(line.substring(len-3,len))*10 + digitSum(line));
            len = total.length();
            total = (len == 4)?total:((len > 4)?total.substring(len-4,len):add1000(total));
            System.out.println(total);
        }
    }
}
