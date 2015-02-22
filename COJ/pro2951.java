import java.util.Scanner;
import java.util.HashSet;

public class pro2951{
    public static void main(String[] args){
        pro2951 exe = new pro2951();
        exe.begin();
    }

    String repeat(int i,int n){
        char car = (char)(i+'0');
        String output="";
        while(n-->0)
            output+=car;
        return output;
    }

    String buildCad(String line){
        int[] arr = new int[10];
        for(int i=0;i<line.length();i++)
            arr[line.charAt(i)-'0']++;
        String output="";
        for(int i=0;i<10;i++)
            output+= repeat(i,arr[i]);
        return output;
    }

    void begin(){
        HashSet<String> ht = new HashSet<String>();
        Scanner l = new Scanner(System.in);
        String line;
        int N = l.nextInt(), counter = 0;

        while(N-->0){
            line = l.next();
            line = buildCad(line);
            if(!ht.contains(line)){
                ht.add(line);
                counter++;
            }
        }

        System.out.println(counter);
    }
}
