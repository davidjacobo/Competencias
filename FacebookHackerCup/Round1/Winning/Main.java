import java.util.Scanner;
import java.io.IOException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class Main {
	int[][] W,L;
	int mod = 1000000007;
	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Main exe = new Main();
		exe.begin();
	}
	
	void begin() throws IOException{
		Scanner l = new Scanner(new FileReader("winning_at_sports.txt"));
		FileWriter writer = new FileWriter("output.txt");
		StringTokenizer st;
		int T, counter = 1, A,B,min,max;
		String line;
		
		init();
		
		T = l.nextInt();
		while(T-->0){
			line = l.next();
			st = new StringTokenizer(line, "-");
			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			
			min = W[B][A];
			A = Math.min(A, B);
			max = L[A][A];
			
			writer.write("Case #"+(counter++)+": "+min+" "+max+"\n");
		}
		
		
		l.close();
		writer.close();
	}

	void init(){
		int N = 2000;
		W = new int[2001][2001];
		L = new int[2001][2001];
		
		for(int j=0;j<=N;j++)
			W[0][j] = 1;
		for(int i=0;i<=N;i++)
			W[i][i] = 0;
		
		for(int i=1;i<=N;i++){
			for(int j=i+1;j<=N;j++){
				W[i][j] = (W[i-1][j] + W[i][j-1])%mod;
			}
		}
		
		for(int i=0;i<=N;i++)
			L[i][0] = 1;
		
		for(int i=1;i<=N;i++){
			for(int j=1;j<i;j++){
				L[i][j] = (L[i-1][j] + L[i][j-1])%mod;
			}
			
			L[i][i] = L[i][i-1];
		}
		
		//for(int i=1;i<=N;i++)
			//L[i][i] = L[i][i-1];
	}
}
