import java.util.Scanner;

public class Chess{
    public static void main(String[] args){
        Scanner l = new Scanner(System.in);
        String line;
        char car;
        int white, black;

        white = black = 0;
        for(int i=0;i<8;i++){
            line = l.next();
            for(int j=0;j<8;j++){
                car = line.charAt(j);
                if(car=='Q') {
                    white+= 9;
                } else if(car =='R'){
                    white+= 5;
                } else if(car =='B'){
                    white+= 3;
                } else if(car=='N'){
                    white+= 3;
                } else if(car=='P'){
                    white+=1;
                } else if(car=='q') {
                    black+= 9;
                } else if(car =='r'){
                    black+= 5;
                } else if(car =='b'){
                    black+= 3;
                } else if(car=='n'){
                    black+= 3;
                } else if(car=='p'){
                    black+=1;
                }
            }
        }

        if(white > black) System.out.println("White");
        else if(white < black) System.out.println("Black");
        else System.out.println("Draw");
    }
}
