import java.util.*;

public class Main{
    public static void main(String[] args){
        Main exe  = new Main();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        Hashtable<String, Integer> ht = new Hashtable<String, Integer>();
        Boolean[] used = new Boolean[101];
        int T,N,K;
        
        T = l.nextInt();
        while(T-->0){
            N = l.nextInt();
            K = l.nextInt();

            ht.clear();
            for(int i=0;i<N;++i){
                String word = l.next();
                used[i] = false;
                ht.put(word, i);
            }

            for(int i=0;i<K;++i){
                int m = l.nextInt();
                for(int j=0;j<m;++j){
                    String word = l.next();
                    if(ht.containsKey(word)){
                        used[ht.get(word)] = true;
                    }
                }
            }

            for(int i=0;i<N;++i){
                String output = (used[i])?"YES":"NO";
                if(i!=0) System.out.printf(" ");
                System.out.printf("%s",output);
            }
            System.out.println();
        }
    }
}
