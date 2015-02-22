import java.util.Scanner;

public class pro2655{
    public static void main(String[] args){
        pro2655 exe = new pro2655();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        String line, pattern = "FBI", output = "";
        line = l.next();
        if(line.indexOf(pattern) != -1)
            output+=" 1";
        
        line = l.next();
        if(line.indexOf(pattern) != -1)
            output+=" 2";
    
        line = l.next();
        if(line.indexOf(pattern) != -1)
            output+=" 3";
    
        line = l.next();
        if(line.indexOf(pattern) != -1)
            output+=" 4";

        line = l.next();
        if(line.indexOf(pattern) != -1)
            output+=" 5";

        if(output.length()==0) System.out.println("HE GOT AWAY!");
        else System.out.println(output.substring(1, output.length()));
    }
}
