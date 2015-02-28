import java.util.Scanner;

public class pro2736{
    int[] pot = new int[30];
    public static void main(String[] args){
        pro2736 exe = new pro2736();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        String line;

        line = l.next();
        int bitcount = 0;
        while(true){
            System.out.println(line);
            bitcount = countBits(line);
            if(1 == bitcount) break;
            line = Integer.toBinaryString(bitcount);
        }
    }

    int countBits(String line){
        int counter = 0;
        for(int i=0;i<line.length();i++){
            counter+= (line.charAt(i)=='1')?1:0;
        }
        return counter;
    }
}
