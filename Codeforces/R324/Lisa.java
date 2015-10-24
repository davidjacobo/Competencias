import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;

public class Lisa{
	ArrayList<Integer> lst;
	HashSet<Integer> set;
	public static void main(String[] args) {
		Lisa exe =  new Lisa();
		exe.begin();
	}

	void build_primes(int n) {
		lst = new ArrayList<Integer>();
		set = new HashSet<Integer>();
		boolean prime[] = new boolean[100000000];
		for(int i=0;i<n;++i)
			prime[i] = true;

		set.add(2);
		lst.add(2);

		for(int i=3;i<n;i+=2) {
			if(prime[i]) {
				set.add(i);
				lst.add(i);
				for(int j=2*i;j<n;j+=i) {
					prime[j] = false;
				}
			}
		}
	}

	int closestPrime(int n) {
		if(isPrime(n)) return n;

		for(int i=n-4;i>0;--i){
			if(isPrime(i)) return i;
		}
		return -1;
	}

	boolean isPrime(int n) {
		int root;
		int div = 2;
		int ori = n;

		while(n%div==0)	n/=2;

		div = 3;
		root = (int)Math.sqrt(n)+1;
		while(div<root) {
			while(n%div==0) {
				n/=div;
				root = (int)Math.sqrt(n)+1;
			}

			div+= 2;
		}
		return (n==ori)?true:false;
	}

	void begin() {
		Scanner l = new Scanner(System.in);
		int n = l.nextInt();

		int bp = closestPrime(n);
		if(bp == n){
			System.out.println(1);
			System.out.println(n);
		} else {
			System.out.println(3);
			build_primes(n-bp);
			int a,b;
			a = b = 0;
			for(int i=0;i<lst.size();++i) {
				a = lst.get(i);
				b = n-bp-a;
				if(set.contains(b)) {
					break;
				}
			}

			System.out.println(bp+" "+a+" "+b);
		}

	}
}