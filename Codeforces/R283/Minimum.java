import java.util.Scanner;

public class Minimum{
	public static void main(String[] args){
		Minimum exe = new Minimum();
		exe.begin();
	}
	
	public void begin(){
		Scanner l = new Scanner(System.in);
		int N = l.nextInt();
		int[] arr = new int[N];
		
		int i = 0;
		while(i<N){
			arr[i++] = l.nextInt();
		}
		
		System.out.println(solve(arr, N));
	}
	
	public int solve(int[] arr,int N){
		int min = (1<<30);
		int maximo;
		for(int i=1;i<N-1;i++){
			maximo = 0;
			for(int j=1;j<N;j++){
				if(j==i)
					maximo = Math.max(maximo, arr[j+1]-arr[j-1]);
				else
					maximo = Math.max(maximo, arr[j]-arr[j-1]);
			}
			//System.out.println("maximo for "+i+" "+maximo);
			min = Math.min(maximo, min);
		}
		return min;
	}
}