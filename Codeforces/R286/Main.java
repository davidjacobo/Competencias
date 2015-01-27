import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Main exe = new Main();
		exe.begin();
	}
	
	public void begin(){
		Scanner l = new Scanner(System.in);
		String input;
		
		input = l.next();
		System.out.println(solve(input));
	}
	
	public boolean isPalindrome(String cad){
		int len = cad.length();
		int m = cad.length()/2;
		
		for(int i=0,j=len-1;i<m;i++,j--){
			if(cad.charAt(i)!=cad.charAt(j)) 
				return false;
		}
		return true;
	}
	
	public String solve(String cad){
		int len = cad.length();
		if(isPalindrome(cad)){
			if(len%2==0)
				return cad.substring(0,len/2)+"a"+cad.substring(len/2,len);
			else
				return cad.substring(0,len/2+1)+cad.substring(len/2,len);
		} else {
			for(int i=0;i<=len;i++){
				String t = cad.substring(0, i) + ((i>len/2)?cad.charAt(len-i):cad.charAt(len-1-i)) + cad.substring(i,len);
				//System.out.println(t);
				if(isPalindrome(t))
					return t;
			}
		}
		return "NA";
	}
}