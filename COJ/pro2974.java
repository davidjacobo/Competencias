import java.util.Scanner;
import java.util.Arrays;

public class pro2974{
    public static void main(String[] args){
        pro2974 exe = new pro2974();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        Word[] words = new Word[21];
        int N, counter =1;
        String _rules;

        while(true){
            N = l.nextInt();
            if(N == 0) break;
            _rules = l.next();
            for(int i=0;i<N;i++)
                words[i] = new Word(l.next(), _rules);

            Arrays.sort(words,0, N);
            System.out.println("year "+counter++);
            for(int i=0;i<N;i++)
                System.out.println(words[i].cad);
            Word.rekSheit();
        }
    }
}

class Word implements Comparable<Word>{
    Word(String _cad, String _rules){
        if(rules == null){
            rules = new boolean[26][26];
            int a,b;
            for(int i=0;i<25;i++){
                a = _rules.charAt(i)-'A';
                for(int j=i+1;j<26;j++){
                    b = _rules.charAt(j)-'A';
                    rules[a][b] = true;
                }
            }
        }

        cad = _cad;
    }

    public int compareTo(Word otro){
        int lenA = this.cad.length();
        int lenB = otro.cad.length();

        for(int i=0;i<lenA && i<lenB;i++){
            int A = this.cad.charAt(i)-'A';            
            int B = otro.cad.charAt(i)-'A';
            if(A==B) continue;
                    
            if(rules[A][B]) return -1;
            else return 1;
        }
        if(lenA > lenB) return 1;
        if(lenB > lenA) return -1;
        return 0;
    }

    static void rekSheit(){
        rules = null;
    }
    String cad;
    static boolean[][] rules;
}
