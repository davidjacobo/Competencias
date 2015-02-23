import java.util.Scanner;

public class Secret{
	public static void main(String[] args){
		Secret exe = new Secret();
		exe.begin();
	}
	
	private void begin(){
		Scanner l = new Scanner(System.in);
		int N = l.nextInt();
		char[] arr = new char[N<<1];
		
		copy(arr, l.next(), N);
		String output = solve(arr, N);
		while(output.length()<N)
			output = "0"+output;
		System.out.println(output);
	}
	
	private String solve(char[] arr, int N){
		int i,j;
		String min="", temp;		
		
		for(i=0;i<N;i++){
			temp = "";
			for(j=0;j<N-1;j++){
				temp+= diff(arr[j+i+1]-arr[i]);
				//System.out.println("building "+temp);
			}
			
			//System.out.println(i+" "+temp);
			if(min.equals("") || min.compareTo(temp)>0)
				min = temp;
		}
		
		return min;
	}
	
	private int diff(int a){
		return (a>=0)?a:diff(a+10);
	}
	
	private void copy(char[] arr, String cad, int N){
		for(int i=0;i<N;i++)
			arr[i] = arr[i+N] = cad.charAt(i);
	}
}