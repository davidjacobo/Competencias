import java.util.Scanner;

public class Contest{
	public static void main(String[] args){
		Contest exe = new Contest();
		exe.begin();
	}
	
	public void begin(){
		Scanner l = new Scanner(System.in);
		int a,b,c,d;
		a = l.nextInt();
		b = l.nextInt();
		c = l.nextInt();
		d = l.nextInt();
		
		int outMisha = calculate(a,c);
		int outVasya = calculate(b,d);
		if(outMisha == outVasya){
			System.out.println("Tie");
		}else if(outMisha > outVasya){
			System.out.println("Misha");
		}else{
			System.out.println("Vasya");
		}
	}
	
	public int calculate(int p,int t){
		return Math.max((3*p)/10, p-(p*t)/250);
	}
}