import java.util.Scanner;
import java.util.ArrayList;

public class Names{
	boolean fail;
	public static void main(String[] args){
		Names exe = new Names();
		exe.begin();
	}
		
	void begin(){
		Scanner l = new Scanner(System.in);
		int N = l.nextInt();
		String[] list = new String[N];
//		Nodo[] graph = new Nodo[26];
		boolean[][] graph = new boolean[26][26];
		int x,y;

		for(int i=0;i<N;i++){
			list[i] = l.next();
		}

		fail = false;
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				compareThisShit(list[i],list[j],graph);
			}
		}

		if(fail) System.out.println("Impossible");
		else
			topsort(graph);
	}

	void topsort(boolean[][] graph){
		ArrayList<Integer> list = new ArrayList<Integer>();
		int i,j;
		int[] indegree = new int[26];
		for(i=0;i<26;i++) indegree[i] = 0;

		for(i=0;i<26;i++){
			for(j=0;j<26;j++){
				if(graph[i][j])
					indegree[j]++;
			}
		}

		for(i=0;i<26;i++)
			if(indegree[i]==0)
				list.add(i);
		
		int x;
		String output = "";
		while(!list.isEmpty()){
			x = list.remove(0);
			output+= (char)(x+'a');

			for(j=0;j<26;j++){
				if(graph[x][j]){
					indegree[j]--;
					if(indegree[j]==0)
						list.add(j);
				}
			}
		}

		if(output.length()!=26)	System.out.println("Impossible");
		else System.out.println(output);
	}

	void compareThisShit(String A,String B,boolean[][] graph){
		int lenA = A.length();
		int lenB = B.length();
		int i,j;
		for(i=0,j=0;i<lenA && j<lenB;i++,j++){
			if(A.charAt(i) != B.charAt(j)){
				insert(graph, A.charAt(i)-'a' , B.charAt(j)-'a');
				return;
			}
		}

		if(lenB < lenA){
			fail = true;
		}
	}

	void insert(boolean[][] graph, int x,int y){
		graph[x][y] = true;
	}
}
