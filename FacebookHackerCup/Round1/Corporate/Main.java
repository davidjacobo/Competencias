import java.util.Scanner;
import java.util.BitSet;
import java.io.IOException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class Main {
	public int[] indegree;
	public int[] minPrice;
	public Node[] graph, graph2;
	public int INF = 2000000000;
	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Main exe = new Main();
		exe.begin();
	}

	public void begin() throws IOException{
		Scanner l = new Scanner(new FileReader("corporate_gifting.txt"));
		FileWriter writer = new FileWriter("output.txt");
		int T, N;
		int x,y,counter = 1;
		
		indegree = new int[200001];
		minPrice = new int[200001];
		graph = new Node[200001];
		graph2 = new Node[200001];
		
		T = l.nextInt();
		while(T-->0){
			N = l.nextInt();
			init(N);
			
			for(int i=0;i<N;i++){
				y = l.nextInt();
				insert(graph, i+1, y);
				insert(graph2, y, i+1);
				indegree[y]++;
			}
			
			x = solve(N);
			writer.write("Case #"+(counter++)+": "+x+"\n");
		}
		
		l.close();
		writer.close();
	}
	
	public int solve(int N){
		ArrayList<Integer> list = new ArrayList<Integer>();
		BitSet bitset = new BitSet(N+1);
		int i,x,y,total = 0;
		for(i=1;i<=N;i++)
			if(indegree[i]==0){
				list.add(i);
				minPrice[i] = 1;
			}
		
		while(!list.isEmpty()){
			x = list.remove(0);
			if(x==0) break;
			Node t1 = graph[x];
			Node t2 = graph2[x];
			
				bitset.clear();
				
				//quitar indegree hacia arriba
				while(t1!=null){
					y = t1.y;
					indegree[y]--;
					if(indegree[y]==0) list.add(y);
					t1 = t1.next;
				}
				
				if(minPrice[x]==INF){
					while(t2!=null){
						y = t2.y;
						bitset.set(minPrice[y]);
						t2 = t2.next;
					}
					minPrice[x] = bitset.nextClearBit(1);
				}
				
				total+= minPrice[x];
				//System.out.println("minof "+x+" "+minPrice[x]);
		}
		
		//System.out.println("out "+total+" /////////////////////////////////");
		
		return total;
	}
	
	public void init(int N){
		for(int i=0;i<=N;i++){
			indegree[i] = 0;
			graph[i] = null;
			graph2[i] = null;
			minPrice[i] = INF;
		}
	}
	
	public void insert(Node[] graph, int x, int y){
		Node temp = graph[x];
		graph[x] = new Node(y);
		if(temp!=null)
			graph[x].next = temp;
	}
}

class Node{
	public Node(int _y){
		y = _y;
		next = null;
	}
	int y;
	Node next;
}
