import java.util.Scanner;
import java.io.IOException;
import java.io.FileReader;
import java.io.FileWriter;

public class Main {
	boolean added;
	String word;
	int total;
	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Main exe = new Main();
		exe.begin();
	}
	
	void begin() throws IOException{
		Scanner l = new Scanner(new FileReader("autocomplete.txt"));
		FileWriter writer = new FileWriter("output.txt");
		int T, N, counter = 1;
		String input_word;
		
		T = l.nextInt();
		while(T-->0){
			N = l.nextInt();
			
			Node root = new Node();
			total = 0;
			for(int i=0;i<N;i++){
				input_word = l.next();
				added = false;
				word = input_word;
				insertWhile(root,  0);
			}
			
			writer.write("Case #"+(counter++)+": "+total+"\n");
		}
		
		l.close();
		writer.close();
	}
	
	void insert(Node node, int deep){
		//System.out.println("deep "+ deep);
		if(deep >= word.length()){
			total+= (added)?0:deep;
			return;
		}
		
		int num = word.charAt(deep)-'a';
		if(isOn(node, num)){
			insert(node.links[num], deep+1);
		} else{
			turnOn(node, num);
			if(!added){
				added = true;
				total+= deep+1;
			}
			insert(node.links[num], deep+1);
		}
	}
	
	void insertWhile(Node node, int deep){
		//System.out.println("deep "+ deep);
		while(true){
			if(deep >= word.length()){
				total+= (added)?0:deep;
				return;
			}
			
			int num = word.charAt(deep)-'a';
			if(isOn(node, num)){
				//DO NOTHING, REALLY
			} else{
				turnOn(node, num);
				if(!added){
					added = true;
					total+= deep+1;
				}
			}
			
			node = node.links[num];
			deep++;
		}
	}
	
	void turnOn(Node node, int i){
		node.links[i] = new Node();
		node.usedMask |= (1<<i);
	}
	
	boolean isOn(Node node, int i){
		return (node.usedMask & (1<<i)) != 0;
	}

}

class Node{
	Node(){
		usedMask = 0;
		links = new Node[26];
		for(int i=0;i<26;i++)
			links[i] = null;
	}
	
	int usedMask;
	Node[] links;
}
