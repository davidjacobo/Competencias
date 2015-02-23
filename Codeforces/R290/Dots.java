import java.util.Scanner;

public class Dots{
	boolean done;
	public static void main(String[] args){	
		Dots exe = new Dots();
		exe.begin();
	}

	void begin(){
		Scanner l = new Scanner(System.in);
		int m,n;
		m = l.nextInt();
		n = l.nextInt();
		char[][] mat = new char[m][n];
		int[][] status = new int[m][n];

		for(int i=0;i<m;i++){
			String line = l.next();
			for(int j=0;j<n;j++)
				mat[i][j] = line.charAt(j);
		}//captured

		done = false;
		for(int i=0;i<m && !done;i++){
			for(int j=0;j<n && !done;j++){
				for(int x=0;x<m;x++) for(int y=0;y<n;y++) status[x][y] = 0;
				dfs(mat,status,i,j,m,n,1);
			}
		}

		if(done)
			System.out.println("Yes");
		else	
			System.out.println("No");
	}

	void dfs(char[][] mat,int[][] status,int i,int j,int m,int n,int deep){
		if(status[i][j]!=0 && deep-status[i][j]>=4) done = true;
		if(status[i][j]!=0) return;
		if(done) return;

//		System.out.print(deep-status[i][j]);

		status[i][j] = deep; //processing

		if(i+1<m && mat[i+1][j]==mat[i][j]){
			dfs(mat,status,i+1,j,m,n,deep+1);
		}
		if(i-1>=0 && mat[i-1][j]==mat[i][j]){
			dfs(mat,status,i-1,j,m,n,deep+1);
		}
		if(j+1<n && mat[i][j+1]==mat[i][j]){
			dfs(mat,status,i,j+1,m,n,deep+1);
		}
		if(j-1>=0 && mat[i][j-1]==mat[i][j]){
			dfs(mat,status,i,j-1,m,n,deep+1);
		}

		status[i][j] = 0; //ended
	}
}
