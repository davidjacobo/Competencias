import java.util.Scanner;

public class pro2752{
    public static void main(String[] args){
        pro2752 exe = new pro2752();
        exe.begin();
    }

    void begin(){
        Scanner l = new Scanner(System.in);
        int[] ID = new int[1001];
        int N = l.nextInt();
        Pair[] arr = new Pair[N];
        String line;
        int id;

        for(int i=0;i<N;i++){
            line = l.next();
            id = l.nextInt();
            arr[i] = new Pair(line, id);
            ID[Math.abs(id)]+= id;
        }

        System.out.println("FOREVER ALONE ones:");
        for(int i=0;i<N;i++){
            if(ID[Math.abs(arr[i].id)]!=0)
                System.out.println(arr[i].name);
        }
    }
}

class Pair{
    Pair(String _name,int _id){
        name = _name;
        id = _id;
    }

    int id;
    String name;
}
