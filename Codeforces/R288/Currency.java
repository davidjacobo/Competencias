import java.util.Scanner;

public class Currency{
	public static void main(String[] args){
		begin();
	}	

	public static void begin(){
		Scanner l = new Scanner(System.in);
		char[] num = l.next().toCharArray();
		int i,len = num.length;

		for(i=0;i<len;i++)
			num[i]-='0';

		boolean done = false;
		for(i=0;i<len-1;i++){
			if(((num[i]&1)==0) && num[i]<num[len-1]){
				num[i]^= num[len-1];
				num[len-1]^= num[i];
				num[i]^= num[len-1];
				done = true;
				break;
			}
		}

		for(i=len-2;i>=0 && !done;i--){
			if((num[i]&1)==0){
				num[i]^= num[len-1];
				num[len-1]^= num[i];
				num[i]^= num[len-1];
				done = true;
			}	
		}

		if(done){
			for(i=0;i<len;i++)
				System.out.print((char)(num[i]+'0'));
			System.out.println();
		}else{
			System.out.println(-1);
		}
	}
}
