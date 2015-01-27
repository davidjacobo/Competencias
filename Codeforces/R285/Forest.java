import java.util.Scanner;
import java.util.ArrayList;

public class Forest{
	public static void main(String[] args){
		Forest exe = new Forest();
		exe.begin();
	}
	
	public void begin(){
		Scanner l = new Scanner(System.in);
		int N = l.nextInt();
		
		int[] deg = new int[N];
		int[] xor = new int[N];
		int i = 0;
		
		while(i<N){
			deg[i] = l.nextInt();
			xor[i] = l.nextInt();
			i++;
		}
		
		solve(sum, deg, xor, N);
	}
	
	public void solve(int[] sum, int[] deg, int[] xor, int N){
		ArrayList<Integer> list = new ArrayList<Integer>();
		int[] lx = new int[N];
		int[] ly = new int[N];
		int i, j, counter = 0;
		int x,y;
		
		for(i=0;i<N;i++)
			if(deg[i]==1)
				list.add(i);
			
		while(!list.isEmpty()){
			x = list.remove(0);
			y = xor[x];
			
			if(deg[x]<=0) continue;
			lx[counter] = x;
			ly[counter] = y;
			counter++;
			
			xor[y]^= x;
			deg[y]--;
			if(deg[y]==1)
				list.add(y);
		}
		
		System.out.println(counter);
		while(counter-->0){
			System.out.println(lx[counter]+" "+ly[counter]);
		}
	}
}