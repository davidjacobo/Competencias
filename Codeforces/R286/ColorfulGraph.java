import java.util.Scanner;
public class ColorfulGraph {
	boolean[][][] mat;
	int[][] counter;
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ColorfulGraph exe = new ColorfulGraph();
		exe.begin();
	}
	
	void begin(){
		Scanner l = new Scanner(System.in);
		int N,M,Q;
		int x,y,color;
		N = l.nextInt();
		M = l.nextInt();
		
		init(N,M);
		
		for(int i=0;i<M;i++){
			x = l.nextInt();
			y = l.nextInt();
			color = l.nextInt();
			mat[x][y][color] = mat[y][x][color] = true;
			counter[x][y]++;
			counter[y][x]++;
		}
		
		floyd(N,M);
		
		Q = l.nextInt();
		while(Q-->0){
			x = l.nextInt();
			y = l.nextInt();
			System.out.println(counter[x][y]);
		}
		
		l.close();
	}
	
	void floyd(int N,int M){
		for(int color=1;color<=M;color++){
			for(int k=1;k<=N;k++)
				for(int i=1;i<=N;i++)
					for(int j=1;j<=N;j++){
						boolean t = mat[i][k][color] & mat[k][j][color];
						if(t && !mat[i][j][color]){
							//System.out.println("adding "+i+" "+j+" "+color);
							mat[i][j][color] = mat[j][i][color] = true;
							counter[i][j]++;
							counter[j][i]++;
						}
					}
		}
	}
	
	void init(int N, int M){
		mat = new boolean[N+1][N+1][M+1];
		counter = new int[N+1][N+1];
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++){
				counter[i][j] = 0;
				for(int k=1;k<=M;k++)
					mat[i][j][k] = false;
			}
	}

}
