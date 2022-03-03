import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Collections;

public class Kruskal {

    public List<Arco> algoKruskal (Grafo gr,int variable){
        
        ArrayList<Arco> preList = new ArrayList<>();
        
        for(Arco v : gr.getEdgeSet()){
            Arco a= new Arco(v.getNode1(),v.getNode2(),v.getValue());
                preList.add(a);    
        }
        
        Collections.sort(preList, new ArcComparator());
        ArrayList<Arco> ris = new ArrayList<>();
        UFSnode<Object> union = new UFSnode<>();
        int n = 0;
        
        for(Object elem : gr.getNodeSet()){
            union.makeSet(elem);
            n++;
        }
        System.out.println("il numero di nodi  " + n);
        int i = 0;
        int count = 0;
        if(variable == 1){
            while( count < n-3 ){
                Arco arco = preList.get(i);
                if(union.find(arco.node1) != union.find(arco.node2)){
                    union.union(union.find(arco.node1),union.find(arco.node2));
                    ris.add(arco);
                    count ++;
                }
                i++;
            }
            return ris;
        }
        while( count < n-1 ){
            Arco arco = preList.get(i);
            if(union.find(arco.node1) != union.find(arco.node2)){
                union.union(union.find(arco.node1),union.find(arco.node2));
                ris.add(arco);
                count ++;
            }
            i++;
        }
        return ris;
        
    }

    
    class ArcComparator implements Comparator<Arco>{
        
 
        public int compare (Arco t1, Arco t2){
            
            double d1 = Double.parseDouble(t1.value.toString());
            double d2 = Double.parseDouble(t2.value.toString());
            
            if(d1 > d2 ){
                return 1;
            }else if(d1 < d2 ){
                return -1;
            }
            return 0;
        }

    }
}
