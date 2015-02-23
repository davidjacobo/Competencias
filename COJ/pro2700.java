import java.util.Scanner;

public class pro2700{
    static int[] counter = new int[26];
    public static void main(String[] args){
        Scanner  l = new Scanner(System.in);
        String line;
        int i;
        for(i=0;i<26;i++) counter[i] = 0;

        line = l.next();
        for(i=0;i<line.length();i++) counter[line.charAt(i)-'A']+=2;
        line = l.next();
        for(i=0;i<line.length();i++) counter[line.charAt(i)-'A']-=1;

        System.out.print("First:");
        for(i=0;i<26;i++)
            if(counter[i]==2) System.out.print((char)(i+'A'));
    
        System.out.println();
        System.out.print("Second:");
        for(i=0;i<26;i++)
            if(counter[i]==-1) System.out.print((char)(i+'A'));

        System.out.println();
        System.out.print("First&Second:");
        for(i=0;i<26;i++)   
            if(counter[i]==1) System.out.print((char)(i+'A'));
        System.out.println();
    }
}
