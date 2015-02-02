import java.util.Scanner;

public class Snake{
	public static void main(String[] args){
		Snake exe = new Snake();
		exe.begin();
	}

	void begin(){
		Scanner l= new Scanner(System.in);
		int m,n;
		m = l.nextInt();
		n = l.nextInt();
		
		int side = 0;
		for(int i=0;i<m;i++){
			if(i%2==0){
				for(int j=0;j<n;j++)
					System.out.print("#");
				System.out.println();
			} else {
				if(side%2==0){
					for(int j=0;j<n-1;j++)
						System.out.print(".");
					System.out.println("#");
					
				} else {
					System.out.print("#");
					for(int j=0;j<n-1;j++)
						System.out.print(".");
					System.out.println();
				}
				side++;
			}
		}
	}
}
