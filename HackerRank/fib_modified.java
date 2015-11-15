import java.math.BigInteger;
import java.util.Scanner;

public class fib_modified {
	public static void main(String[] args) {
		fib_modified exe = new fib_modified();
		exe.begin();
	}

	void begin() {
		Scanner l = new Scanner(System.in);
		BigInteger a,b,c;
		a = new BigInteger(l.nextInt()+"");
		b = new BigInteger(l.nextInt()+"");
		int n = l.nextInt()-2;

		while(n-->0) {
			c = b.multiply(b).add(a);
			a = b;
			b = c;
		}

		System.out.println(b.toString());
	}
}