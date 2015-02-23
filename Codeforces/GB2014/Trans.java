import java.util.Scanner;

public class Trans{
	public static void main(String[] args){
		Trans exe = new Trans();
		exe.begin();
	}

	private void begin(){
		Scanner l = new Scanner(System.in);
		int N, t, step = 1;
		boolean found = false;

		N = l.nextInt();
		t = l.nextInt();
		
		for(int i=1;i<N;i++){
			int x = l.nextInt();
			if(step == i){
				step+= x;
				if(step == t) found = true;
			}
		}

		if(found) System.out.println("YES");
		else System.out.println("NO");
	}
}
