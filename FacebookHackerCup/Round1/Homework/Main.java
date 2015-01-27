import java.util.Scanner;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Main exe = new Main();
		exe.begin();
	}
	
	public void begin() throws IOException{
		Scanner l = new Scanner(new FileReader("homework.txt"));
		FileWriter writer = new FileWriter("output.txt");
		int T, A, B, counter = 1;
		long K;
		 T = l.nextInt();
		 
		 while(T-->0){
			 A = l.nextInt();
			 B = l.nextInt();
			 K = l.nextLong();
			 
			 A = countPrimacity(A,B,K);
			 writer.write("Case #"+(counter++)+": "+A+"\n");
		 }
		
		l.close();
		writer.close();
	}
	
	public int countPrimacity(int A,int B,long k){
		int[] primes = new int[B+1];
		int i, primacity = 0;
		long j;
		
		init(primes, B);
		
		for(i=2;i<=B;i++){
			if(primes[i]==0){
				primacity+= (k==1 && A<=i)?1:0;
				
				for(j=i<<1;j<=B;j+=i){
					primes[(int)j]++;
				}
			}else{
				primacity+= (k==primes[i] && A<=i)?1:0;
			}
		}
		
		return primacity;
	}
	
	public void init(int[] primes, int B){
		for(int i=0;i<=B;i++) 
			primes[i] = 0;
	}

}
