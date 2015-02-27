import java.util.Scanner;
import java.util.HashSet;

public class pro2995{
    public static void main(String[] args){
        pro2995 exe = new pro2995();
        exe.begin();
    }

    void begin(){
        HashSet<String> hs = new HashSet<String>();
        Scanner l = new Scanner(System.in);
        String[] palabras = new String[101];
        String[] line;
        int N, T = Integer.parseInt(l.nextLine());

        while(T-->0){
            line = l.nextLine().split(" ");
            N = 0;
            for(int i=0;i<line.length;i++){
                palabras[i] = line[i];
                N++;
            }

            hs.clear();
            while(true){
                line = l.nextLine().split(" ");
                if(line[1].equals("does"))
                    break;
    
                hs.add(line[2]);
            }

            String output = "";
            for(int i=0;i<N;i++){
                if(!hs.contains(palabras[i]))
                    output+= palabras[i]+" ";
            }
            System.out.println(output.substring(0, output.length()-1));
        }
    }
}
