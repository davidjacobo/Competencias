import java.util.Scanner;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Main exe = new Main();
		exe.begin();
	}
	
	void begin() throws IOException{
		Scanner l = new Scanner(new FileReader("cooking_the_books.txt"));
		FileWriter writer = new FileWriter("cooking_the_books_output.txt");
		int T, len, counter = 1, min, max;
		int index;
		String number, minimo, maximo;
		char[] arr;
		char tmp;
		
		T = l.nextInt();
		while(T-->0){
			number = l.next();
			minimo = "flail";
			maximo = "flail";
			len = number.length();
			
			arr = number.toCharArray();
			for(int k=0;k<len-1;k++){
				index = -1;
				max = arr[k];
				//for(int i=k+1;i<len;i++){ change?
				for(int i=len-1;i>k;i--){
					if(arr[i] > max){
						index = i;
						max = arr[i];
					}
				}
				if(index != -1){
					tmp = arr[k];
					arr[k] = arr[index];
					arr[index] = tmp;
					maximo = String.valueOf(arr);
					break;
				}
			}
			
			arr = number.toCharArray();
			for(int k=0;k<len-1;k++){
				index = -1;
				min = arr[k];
				for(int i=len-1;i>k;i--){
				//for(int i=k+1;i<len;i++){
					if(arr[i] < min && arr[i] > '0'){
						index = i;
						min = arr[i];
					}
				}
				if(index != -1){
					tmp = arr[k];
					arr[k] = arr[index];
					arr[index] = tmp;
					minimo = String.valueOf(arr);
					break;
				}
			}
			
			if(minimo.equals("flail")) minimo = number;
			if(maximo.equals("flail")) maximo = number;
			
			//System.out.println(minimo + " " + maximo);
			writer.write("Case #"+(counter++)+": "+minimo+" "+maximo+"\n");
		}
		l.close();
		writer.close();
	}

}
