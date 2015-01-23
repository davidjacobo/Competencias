import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
public class Main {
	int[][] arr = new int[20][3];
	boolean end;
	int a,b,c,N;
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Main exe = new Main();
		exe.begin();
	}
	
	void begin() throws IOException{
		Scanner l = new Scanner(new FileReader("new_years_resolution.txt"));
		FileWriter writer = new FileWriter("out.txt");
		
		boolean[] solution = new boolean[20];
		int T, counter=1;
		T = l.nextInt();
		while(T-->0){
			a = l.nextInt();
			b = l.nextInt();
			c = l.nextInt();
			N = l.nextInt();
			
			for(int i=0;i<N;i++){
				arr[i][0] = l.nextInt();
				arr[i][1] = l.nextInt();
				arr[i][2] = l.nextInt();
				solution[i] = false;
			}
			
			end = false;
			deepShit(0, solution);
			
			writer.write("Case #"+counter+++": ");
			if(end){
				writer.write("yes\n");
			}else{
				writer.write("no\n");
			}
		}
		
		l.close();
		writer.close();
	}
	
	void deepShit(int deep, boolean[] solution){
		if(end) return;
		if(deep >= N){ 
			test(solution);
		}else{
			solution[deep] = false;
			deepShit(deep+1, solution);
			solution[deep] = true;
			deepShit(deep+1, solution);
		}
	}
	
	void test(boolean[] solution){
		int a1,b1,c1;
		a1 = b1 = c1 = 0;
		for(int i=0;i<N;i++){
			if(solution[i]){
				a1 += arr[i][0];
				b1 += arr[i][1];
				c1 += arr[i][2];
			}
		}
		
		if(a1==a && b1==b && c1==c){
			end=true;
		}
	}

}
