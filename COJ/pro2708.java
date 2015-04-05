import java.util.Scanner;
import java.util.ArrayList;

public class pro2708{
    ArrayList<Integer> list;
    int char_len[] = {2,4,4,3,1,4,3,4,2,4,3,4,2,2,3,4,4,3,3,1,3,4,3,4,4,4,4,4,4,4};
    String[] char_code = new String[30];
    
    public static void main(String[] args){
        pro2708 exe = new pro2708();
        exe.begin();
    }

    void preWork(){
        char_code[0] = ".-";
        char_code[1] = "-...";
        char_code[2] = "-.-.";
        char_code[3] = "-..";
        char_code[4] = ".";
        char_code[5] = "..-.";
        char_code[6] = "--.";
        
        char_code[7] = "....";
        char_code[8] = "..";
        char_code[9] = ".---";
        char_code[10] = "-.-";
        char_code[11] = ".-..";
        char_code[12] = "--";
        char_code[13] = "-.";
    
        char_code[14] = "---";
        char_code[15] = ".--.";
        char_code[16] = "--.-";
        char_code[17] = ".-.";
        char_code[18] = "...";
        char_code[19] = "-";
        char_code[20] = "..-";

        char_code[21] = "...-";
        char_code[22] = ".--";
        char_code[23] = "-..-";
        char_code[24] = "-.--";
        char_code[25] = "--..";
    
        char_code[26] = "..--";
        char_code[27] = "---.";
        char_code[28] = ".-.-";
        char_code[29] = "----";
    }

    char morseToChar(String input){
        int i = 0;
        for(;i<30;i++)
            if(char_code[i].equals(input)) break;

        if(i<26) return (char)(i+'A');
        if(i==26) return '_';
        if(i==27) return '.';
        if(i==28) return ',';
        return '?';
    }

    int charToIndex(char A){
        if(A<='Z' && A>='A') return A-'A';
        if(A=='_') return 26;
        if(A=='.') return 27;
        if(A==',') return 28;
        return 29;
    }

    String charToMorse(char A){
        if(A<='Z' && A>='A') return char_code[A-'A'];
        if(A=='_') return char_code[26];
        if(A=='.') return char_code[27];
        if(A==',') return char_code[28];
        return char_code[29];
    }

    String toStream(String input){
        String output = "";
        char car;
        int ind;
        for(int i=0;i<input.length();i++){
            car = input.charAt(i);
            ind = charToIndex(car);
            list.add(char_len[ind]);
            output+= charToMorse(car);
        }
        return output;
    }

    String decode(String input){
        String output = "";
        int last = 0, len;
        for(int i=list.size()-1;i>=0;i--){
            len = list.get(i);
            output+= morseToChar(input.substring(last,last+len));    
            last+= len;
        }
        return output;
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        list = new ArrayList<Integer>();
        String morseStream, line;
        preWork();

        while(l.hasNext()){
            line = l.next();
            morseStream = toStream(line);
            System.out.println(decode(morseStream));
            list.clear();
        }
    }
}
