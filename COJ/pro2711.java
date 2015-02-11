import java.util.Scanner;
import java.util.Arrays;

public class pro2711{
    public static void main(String[] args){
        pro2711 exe = new pro2711();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        int N = l.nextInt();
        Par[] arr = new Par[N];

        for(int i=0;i<N;i++){
            arr[i] = new Par(i, l.nextInt());
        }
        Arrays.sort(arr);
        for(int i=N-1;i>=0;i--)
            System.out.println(arr[i].i+1);
    }
}

class Par implements Comparable<Par>{
    Par(int _i,int _power){
        i = _i;
        power = _power;
    }

    public int compareTo(Par otro){
        if(this.power > otro.power) return 1;
        if(this.power < otro.power) return -1;
        return 0;
    }
    int i,power;
}
