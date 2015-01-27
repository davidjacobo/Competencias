import java.util.Scanner;

public class Columns{
	public static void main(String[] args){
		Columns exe = new Columns();
		exe.begin();
	}
	
	public void begin(){
		Scanner l = new Scanner(System.in);
		int M = l.nextInt();
		int N = l.nextInt();
		char[][] mat = new char[M+1][N+1];
		
		for(int i=0;i<M;i++){
			String temp = l.next();
			for(int j=0;j<N;j++){
				mat[i][j] = temp.charAt(j);
			}
		}
		
		int solutions = 0;
		boolean[] ban = new boolean[N];
		while(toBan(mat, M, N, ban))
			solutions++;
			
		System.out.println(solutions);
	}
	
	public boolean toBan(char[][] mat,int M,int N,boolean[] ban){
		for(int i=1;i<M;i++){
			for(int j=0;j<N;j++){
				if(ban[j]) continue;
				
				if(mat[i][j] > mat[i-1][j]) j = N;
				else if(mat[i][j] < mat[i-1][j]){
					ban[j] = true;
					return true;
				}
			}
		}
		return false;
	}
}