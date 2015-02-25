import java.util.Scanner;
import java.util.Arrays;

public class pro2763{
    Pair[] ordered;
    int[] arr;
    int index;
    public static void main(String[] args){
        pro2763 exe = new pro2763();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        int N,K;

        K = l.nextInt();
        N = (int)Math.pow(2, K)-1;
        arr = new int[N];
        ordered = new Pair[N];

        for(int i=0;i<N;i++)
            arr[i] = l.nextInt();

        index = 0;
        build(1, 0, N-1);
        Arrays.sort(ordered);
        
        String output;
        N  =1;
        index = 0;
        int j;
        for(int i=0;i<K;i++){
            j = 0;
            output = "";
            while(j++<N){
                output+=" "+ordered[index++].num;
            }
            System.out.println(output.substring(1, output.length()));
            N<<=1;
        }
    }

    void build(int level,int p,int q){
        if(p==q){
            ordered[index++] = new Pair(arr[p], level);
        } else {
            int m = (p+q)/2;
            build(level+1, p, m-1);
            ordered[index++] = new Pair(arr[m], level);
            build(level+1, m+1, q);
        }
    }
}

class Pair implements Comparable<Pair>{
    Pair(int _num,int _level){
        num = _num;
        level = _level;
    }

    public int compareTo(Pair otro){
        return (this.level == otro.level)?0:((this.level > otro.level)?1:-1);
    }
    int num, level;
}
