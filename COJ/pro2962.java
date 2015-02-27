import java.util.Scanner;

public class pro2962{
    public static void main(String[] args){
        pro2962 exe = new pro2962();
        exe.begin();
    }

    void begin(){
        String[] arr = new String[16];
        Scanner l = new Scanner(System.in);
        build(arr);
        int n;
    
        while(true){
            n = l.nextInt();
            if(-1 == n) break;
            System.out.println(arr[n]);
        }
    }

    String reverse(String cad){
        String output="";
        for(int i=cad.length()-1;i>=0;i--){
            output+= (cad.charAt(i)=='L')?'R':'L';
        }
        return output;
    }

    void build(String[] arr){
        arr[0] = "";
        arr[1] = "L";
        for(int i=2;i<16;i++)
            arr[i] = arr[i-1]+'L'+reverse(arr[i-1]);
    }
}
