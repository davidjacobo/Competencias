import java.util.Scanner;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Main {
	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Main exe = new Main();
		exe.begin();
	}
	
	void begin() throws IOException{
		Scanner l = new Scanner(new FileReader("laser_maze.txt"));
		FileWriter writer = new FileWriter("laser_maze_output.txt");
		int T, N, M, counter = 1;
		int X0,Y0,X1,Y1;
		char[][][] tab = new char[100][100][4];
		String line, output;
		
		T = l.nextInt();
		while(T-->0){
			M = l.nextInt();
			N = l.nextInt();
			X0 = Y0 = X1 = Y1 = -1;
			for(int i=0;i<M;i++){
				line = l.next();
				
				for(int j=0;j<line.length();j++){
					tab[i][j][0] = line.charAt(j);
					if(tab[i][j][0]=='S'){
						tab[i][j][0] = '.';
						X0 = i;
						Y0 = j;
					}else if(tab[i][j][0]=='G'){
						tab[i][j][0] = '.';
						X1 = i;
						Y1 = j;
					}
				}
			}
			
			//build tab[1-3]
			copyTab(tab, M, N);
			//printMat(tab,M,N,0);
			//printMat(tab,M,N,1);
			//printMat(tab,M,N,2);
			//printMat(tab,M,N,3);
			
			//block lazers!
			fill(tab, M, N);
			//printMat(tab,M,N,0);
			//printMat(tab,M,N,1);
			//printMat(tab,M,N,2);
			//printMat(tab,M,N,3);
			
			//bfs
			output = bfs(tab,X0,Y0,X1,Y1,M,N);
			
			//output
			//System.out.println("Case #"+(counter++)+": "+output);
			writer.write("Case #"+(counter++)+": "+output+"\n");
		}
		
		writer.close();
		l.close();
	}
	
	String bfs(char[][][] tab, int X0,int Y0,int X1,int Y1,int M,int N){
		//if(tab[X0][Y0][0]!='.') return "impossible";
		int layer,x,y,distance,nextLayer;
		ArrayList<Cuad> list = new ArrayList<Cuad>();
		list.add(new Cuad(X0,Y0,0,0));
		tab[X0][Y0][0] = '#';
		
		while(!list.isEmpty()){
			Cuad temp = list.remove(0);
			x = temp.x;
			y = temp.y;
			distance = temp.distance;
			layer = temp.layer;
			nextLayer = (layer+1)%4;
			
			if(x==X1 && y==Y1) return String.valueOf(distance);
			
			if(boundCheck(x+1,y,M,N) && tab[x+1][y][nextLayer]=='.'){
				tab[x+1][y][nextLayer] = '#';
				list.add(new Cuad(x+1,y,nextLayer,distance+1));
			}
			if(boundCheck(x-1,y,M,N) && tab[x-1][y][nextLayer]=='.'){
				tab[x-1][y][nextLayer] = '#';
				list.add(new Cuad(x-1,y,nextLayer,distance+1));
			}
			if(boundCheck(x,y+1,M,N) && tab[x][y+1][nextLayer]=='.'){
				tab[x][y+1][nextLayer] = '#';
				list.add(new Cuad(x,y+1,nextLayer,distance+1));
			}
			if(boundCheck(x,y-1,M,N) && tab[x][y-1][nextLayer]=='.'){
				tab[x][y-1][nextLayer] = '#';
				list.add(new Cuad(x,y-1,nextLayer,distance+1));
			}
		}
		
		return "impossible";
	}
	
	void printMat(char[][][] tab,int M,int N,int layer){
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				System.out.print(tab[i][j][layer]);
			}
			System.out.println();
		}
		System.out.println("/////////////");
	}
	
	boolean boundCheck(int x,int y,int M,int N){
		if(x<0 || y<0 || x>=M || y>=N) return false;
		return true;
	}
	
	void fill(char[][][] tab,int M,int N){
		int layer = 0;
		
		while(layer < 4){
			for(int j=0;j<N;j++){
				for(int i=M-1;i>=0;i--){
					if(tab[i][j][layer]=='^'){
						tab[i][j][layer] = '#';
						
						i--;
						while(i>=0 && (tab[i][j][layer]=='.' || tab[i][j][layer]=='x')){
							tab[i][j][layer] = 'x';
							i--;
						}
						i++;
					}
				}
			}
			
			for(int j=0;j<N;j++){
				for(int i=0;i<M;i++){
					if(tab[i][j][layer]=='v'){
						tab[i][j][layer] = '#';
						
						i++;
						while(i<M && (tab[i][j][layer]=='.' || tab[i][j][layer]=='x')){
							tab[i][j][layer] = 'x';
							i++;
						}
						i--;
					}
				}
			}
			
			for(int i=0;i<M;i++){
				for(int j=N-1;j>=0;j--){
					if(tab[i][j][layer]=='<'){
						tab[i][j][layer] = '#';
						
						j--;
						while(j>=0 && (tab[i][j][layer]=='.' || tab[i][j][layer]=='x')){
							tab[i][j][layer] = 'x';
							j--;
						}
						j++;
					}
				}
			}
			
			for(int i=0;i<M;i++){
				for(int j=0;j<N;j++){
					if(tab[i][j][layer]=='>'){
						tab[i][j][layer] = '#';
						
						j++;
						while(j<N && (tab[i][j][layer]=='.' || tab[i][j][layer]=='x')){
							tab[i][j][layer] = 'x';
							j++;
						}
						j--;
					}
				}
			}
			
			layer++;
		}
	}
	
	void copyTab(char[][][] tab, int M, int N){
		int layer = 0;
		
		while(++layer < 4){
			for(int i=0;i<M;i++){
				for(int j=0;j<N;j++){
					tab[i][j][layer] = getNext(tab[i][j][layer-1]);
				}
			}
		}
	}
	
	char getNext(char a){
		if(a=='^') return '>';
		else if(a=='>') return 'v';
		else if(a=='v') return '<';
		else if(a=='<') return '^';
		else return a;
	}

}

class Cuad{
	Cuad(int _x,int _y,int _layer,int _distance){
		x = _x;
		y = _y;
		distance = _distance;
		layer = _layer;
	}
	int x,y,layer,distance;
}