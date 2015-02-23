import java.util.Scanner;
import java.util.Hashtable;

public class pro2712{
    public static void main(String[] args){
        pro2712 exe = new pro2712();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        Hashtable<String, Integer> ht = new Hashtable<String, Integer>();
        String line;
        String[] words;
        int N,T;
        
        N = Integer.parseInt(l.nextLine());
        while(N-->0){
            line = l.nextLine();
            words = line.split(" ");
            if(ht.containsKey(words[1])) {
                ht.put(words[1], ht.get(words[1])+1);
            } else {
                ht.put(words[1], 1);
            }
        }

        T = Integer.parseInt(l.nextLine());
        while(T-->0){
            line = l.nextLine();
            words = line.split(" ");
            if(ht.containsKey(words[1])) {
                System.out.println(ht.get(words[1]));
            } else {
                System.out.println(0);
            }            
        }
    }
}
