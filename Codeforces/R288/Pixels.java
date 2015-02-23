import java.util.Scanner;

public class Pixels{
	public static void main(String[] args){
		Pixels exe = new Pixels();
		exe.begin();
	}

	public void begin(){
		Scanner l = new Scanner(System.in);
		int M,N;
		M = l.nextInt();
		N = l.nextInt();
		int x,y;
		boolean[][] used = new boolean[M][N];
		int Q = l.nextInt();
		int counter = 1;
		boolean done = false;
		
		while(Q-->0){
			x = l.nextInt()-1;
			y = l.nextInt()-1;
			if(!used[x][y]){
				done = setCell(used,x,y,M,N);
				if(done) break;
			}
			counter++;
		}

		if(done) System.out.println(counter);
		else System.out.println(0);
	}

	public void init(boolean[][] used, int M, int N){
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				used[i][j] = false;
	}

	public boolean inBound(int x,int y,int M,int N){
		if(x<0 || y<0 || x>=M || y>=N) return false;
		return true;
	}

	public boolean setCell(boolean[][] used,int x,int y,int M,int N){
		used[x][y] = true;
		if(inBound(x-1,y-1,M,N) && used[x-1][y-1]){
			if(used[x-1][y] && used[x][y-1])
				return true;
		}
		if(inBound(x-1,y+1,M,N) && used[x-1][y+1]){
			if(used[x-1][y] && used[x][y+1])
				return true;
		}
		if(inBound(x+1,y-1,M,N) && used[x+1][y-1]){
			if(used[x][y-1] && used[x+1][y])
				return true;
		}
		if(inBound(x+1,y+1,M,N) && used[x+1][y+1]){
			if(used[x+1][y] && used[x][y+1])
				return true;
		}
		return false;
	}
}
