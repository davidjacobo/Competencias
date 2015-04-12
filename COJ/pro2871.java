import java.util.Scanner;
import java.util.ArrayList;
public class pro2871{
    int MAX_N = 150002;
    String line;
    int ans;
    public static void main(String[] args){
        pro2871 exe = new pro2871();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        line = l.next();
        Nodo root = new Nodo();
        for(int i=0;i<line.length();i++)
            insert(root,i);

        ans = 0;
        traverse(root,0,0,0);
        System.out.println(ans-root.pass_by);
    }

    void traverse(Nodo root,int a,int b,int c){
        vertex[] list = new vertex[MAX_N];
        for(int i=0;i<MAX_N;i++)
            list[i] = new vertex(null,0,0,0);
        int ind = 0;
        list[ind].root = root;
        list[ind].a = a;
        list[ind].b = b;
        list[ind].c = c;
        ind++;

        while(ind>0){
            ind--;
            root = list[ind].root;
            a = list[ind].a;
            b = list[ind].b;
            c = list[ind].c;
        
            if(a==b && b==c) ans+= root.pass_by;

            for(int i=0;i<26;i++){
                if(root.car[i]==null) continue;    
    
                if(i==0) {
                    //traverse(root.car[i],a+1,b,c);
                    list[ind].root = root.car[i];
                    list[ind].a = a+1;
                    list[ind].b = b;
                    list[ind].c = c;
                    ind++;
                } else if(i==1) {
                    //traverse(root.car[i],a,b+1,c);
                    list[ind].root = root.car[i];
                    list[ind].a = a;
                    list[ind].b = b+1;
                    list[ind].c = c;
                    ind++;
                } else if(i==2) {
                    //traverse(root.car[i],a,b,c+1);
                    list[ind].root = root.car[i];
                    list[ind].a = a;
                    list[ind].b = b;
                    list[ind].c = c+1;
                    ind++;
                } else {
                    //traverse(root.car[i],a,b,c);
                    list[ind].root = root.car[i];
                    list[ind].a = a;
                    list[ind].b = b;
                    list[ind].c = c;
                    ind++;
                }
            }
        }
    }

    void insert(Nodo root,int i){
        while(true){
            root.pass_by++;
            if(i>=line.length()) return;
            int car = line.charAt(i)-'a';

            if(root.car[car]==null)
                root.car[car] = new Nodo();
            root = root.car[car];
            i++;
        }
    }
}

class vertex{
    public vertex(Nodo _root,int _a,int _b,int _c){
        root = _root;
        a = _a;
        b = _b;
        c = _c;
    }
    Nodo root;
    int a,b,c;
}

class Nodo{
    public Nodo(){
        car = new Nodo[26];
        for(int i=0;i<26;i++)
            car[i] = null;
        pass_by = 0;
    }
    Nodo[] car;
    int pass_by;
}
