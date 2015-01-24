import java.util.Scanner;
import java.util.PriorityQueue;

public class Music{
	public static void main(String[] args){
		Music exe = new Music();
		exe.begin();
	}
	
	public void begin(){
		Scanner l = new Scanner(System.in);
		int N = l.nextInt();
		int time = l.nextInt();
		int[] out = new int[N];
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
		int i=1, j;
		
		while(N-->0){
			pq.add(new Pair(i++, l.nextInt()));
		}
		
		i = 0;
		while(!pq.isEmpty() && time>=0){
			int value = pq.peek().val;
			int index = pq.poll().i;
			
			time-= value;
			if(time>=0)
				out[i++] = index;
		}
		
		System.out.println(i);
		String output="";
		for(j=0;j<i;j++)
			output+= " "+out[j];
		if(output.length()>0)
			System.out.println(output.substring(1,output.length()));
	}
}

class Pair implements Comparable<Pair>{
	Pair(int _i, int _val){
		i = _i;
		val = _val;
	}
	
	public int compareTo(Pair otro){
		return (this.val==otro.val)?0:((this.val>otro.val)?1:-1);
	}
	
	int i,val;
}