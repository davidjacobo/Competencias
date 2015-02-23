import java.util.Scanner;

public class pro2698{
  public static void main(String[] args){
    pro2698 exe = new pro2698();
    exe.begin(); 
  }

  void begin(){
    Scanner l = new Scanner(System.in);
    String line;
    int out = 0;

    line = l.next();
    for(int i=0;i<line.length();i++)
      out+= line.charAt(i)-'A'+1;
    System.out.println(out);
  }
}
