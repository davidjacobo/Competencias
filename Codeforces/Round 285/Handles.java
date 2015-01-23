import java.util.Scanner;
import java.util.Hashtable;
public class Handles{
	public static void main(String[] args){
		Handles exe = new Handles();
		exe.begin();
	}
	
	void begin(){
		String[] original = new String[1001];
		String[] last = new String[1001];
		Hashtable<String,Integer> ht = new Hashtable<String, Integer>();
		Scanner l = new Scanner(System.in);
		String oldName, newName;
		int q = l.nextInt();
		int index, counter = 0;
		
		while(q-->0){
			oldName = l.next();
			newName = l.next();
			
			if(ht.containsKey(oldName)){
				index = ht.get(oldName);
				ht.put(newName, index);
				last[index] = newName;
			}else{
				ht.put(newName, counter);
				last[counter] = newName;
				original[counter++] = oldName;
			}
		}
		
		System.out.println(counter);
		for(int i=0;i<counter;i++){
			System.out.println(original[i]+" "+last[i]);
		}
	}
}