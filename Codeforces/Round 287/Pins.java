import java.util.Scanner;

public class Pins{
	public static void main(String[] args){
		Pins exe = new Pins();
		exe.begin();
	}
	
	public void begin(){
		Scanner l = new Scanner(System.in);
		int r,x0,y0,x1,y1;
		double d;
		
		r = l.nextInt();
		x0 = l.nextInt();
		y0 = l.nextInt();
		x1 = l.nextInt();
		y1 = l.nextInt();
		
		if(x0==x1 && y0==y1){
			System.out.println(0);
		}else{
			d = distance(x0,y0,x1,y1);
			x0 = (int)Math.ceil(d/(r<<1));
			System.out.println(x0);
		}
	}
	
	public double distance(int x0,int y0,int x1,int y1){
		return Math.sqrt(Math.pow(x1-x0,2) + Math.pow(y1-y0, 2));
	}
}