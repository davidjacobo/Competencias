import java.util.Scanner;
import java.util.ArrayList;

public class pro2119{
    public static void main(String[] args){
        pro2119 exe = new pro2119();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        ArrayList<String> list = new ArrayList<String>();;
        String line;
        int N;
        Nodo root;

        while(l.hasNext()){
            N = l.nextInt();
            root = new Nodo();
            list.clear();

            for(int i=0;i<N;i++){
                line = l.next();
                list.add(line);
                insert(root, line,0);
            }

            int ans = 0;
            for(int i=0;i<N;i++){
                line = list.get(i);
                ans+= 1+press(root.car[line.charAt(0)-'a'], line,1);
                //System.out.println("so far "+i+" sum: "+ans);
            }

            System.out.printf("%.2f\n",(double)ans/N);
        }
    }

int press(Nodo root,String cad,int i){
    if(i>=cad.length()) return 0;
    int car = cad.charAt(i)-'a';
    int t = 0;
 
    //if(cad.length()-1==i) {
    //    //no more jumps
    //    return 0;
    //} else {
        if(root.sons > 1 || (root.palabra && root.suffix)){ 
            t = 1;
        } else {
            t = 0;
        }
        return t+press(root.car[car], cad, i+1);
    //}
}

void insert(Nodo root,String cad,int i){
    if(i>=cad.length()){
        root.palabra = true;
        return;
    }
    int car = cad.charAt(i)-'a';
    
    root.suffix = true;

    if(root.car[car]!=null) {
        //nada
    } else {
        root.sons++;
        root.car[car] = new Nodo();
    }
    insert(root.car[car], cad, i+1);
}
}

class Nodo{
    Nodo(){
        sons = 0;
        palabra = suffix = false;
        car = new Nodo[26];
        for(int i=0;i<26;i++) car[i] = null;
    }
    int sons;
    boolean palabra, suffix;
    Nodo[] car;
}
