import java.util.Scanner;

public class pro1952{
    Nodo tree;
    public static void main(String[] args){
        pro1952 exe = new pro1952();
        exe.begin();
    }

    void begin(){
        String line;
        String[] list = new String[30];
        Scanner l = new Scanner(System.in);
        int i = 0;
        tree = null;
        while(true){
            line = l.next();
            list[i] = line;
            if(line.equals("*") || line.equals("$")){
                buildTree(list, i-1);
                System.out.println(preOrder(tree));
                tree = null;
                i = -1;
                if(line.equals("$")) break;

            } 
            i++;
        }
    }

    void buildTree(String[] list,int i){
        if(i<0) return;
        String line = list[i];
        if(tree==null){
            tree = new Nodo(line.charAt(0));
        } else {
            for(int j=0;j<line.length();j++)
                pushTree(tree,line.charAt(j));
        }
        buildTree(list, --i);
    }

    void pushTree(Nodo tree,char car){
        //System.out.println("pushing: "+tree.car);
        if(tree.car == '$') {
            tree.car = car;
        } else {
            if(tree.car > car){
                if(tree.l==null)
                    tree.l = new Nodo('$');
                pushTree(tree.l, car);
            } else {
                if(tree.r==null)
                    tree.r = new Nodo('$');
                pushTree(tree.r,car);
            }
        }
    }

    String preOrder(Nodo tree){
        if(tree==null)return "";
        //System.out.println("passing by: "+tree.car);
        return ((tree.car=='$')?"":tree.car) + preOrder(tree.l) + preOrder(tree.r);
    }
}

class Nodo{
    Nodo(char _a){
        car = _a;
        l = r = null;
    }
    Nodo l,r;
    char car;
}
