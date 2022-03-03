import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
public class Grafo  {
    HashMap<Object,Set<Arco>> node;
    int nArchi;
    //costruttore grafo vuoto
    public Grafo(){
        node = new HashMap<Object, Set<Arco>>();
        nArchi = 0;
    }
    //funzioni get
    public int get_node_number(){
        return node.size();
    }

    public int get_arch_number(){
        return nArchi;
    }
    public boolean isEmpty(){
        return (this.node).isEmpty();
    }
    /**
     * funzione utilizzata per aggiungere un Object al grafo
     * @param x 
     */
    public void addObject(Object x){
        if(!node.containsKey(x)){
            Set<Arco> lista = new HashSet<Arco>();
            node.put(x,lista); 
        }
    }

    /**
     * funzione utilizzata per rimuover un Object dal grafo
     * @param x 
     */
    public void removeObject(Object x){
        if(node.containsKey(x)){
            Iterator<Arco> arcoIncide = ((HashSet<Arco>) node.get(x) ).iterator();
            Arco a;
            Object y;
            while (arcoIncide.hasNext()){
                a = arcoIncide.next();
                y = (a.getNode1().equals(x) ) ? a.getNode2() : a.getNode1();
                if( ((HashSet<Arco>) node.get(y)).remove(a)){
                    nArchi --;
                }
            }
            node.remove(x);
        }
    }

    /**
     * funzione utilizzare per aggiungere due nodi e creare un arco tra i due
     * @param x
     * @param y
     * @param value
     * @return true se l'arco è stato creato altrimenti false 
     */
    public boolean add(Object x, Object y, Object value){
        boolean flag = false;
        boolean flag1 = false;
        
        if(!node.containsKey(x)){
            addObject(x);
        }
        if(!node.containsKey(y)){
            addObject(y);
        }
        Arco a = new Arco(x,y,value);

        flag = (node.get(x)).add(a);
        flag1 = (node.get(y)).add(a);
        
        if(flag && flag1){
            nArchi++;
        }
        return (flag && flag1);
    }

    /**
     * funzione utilizzata per creare nuovo arco
     * @param a
     * @return true se arco creato, false altrimenti
     */
    public boolean addArc(Arco a){
        return add(a.getNode1(),a.getNode2(),a.getValue());
    }
    /**
     * funzione returna true se a è presente, false altrimenti
     * @param a
     * @return
     */
    public boolean contains(Object a){
            if (a instanceof Arco) {
                return true;
            }
            return false;
    }

    
    public boolean removeArc(Arco a){
        boolean flag = false;
        boolean flag1 = false;
        if(node.containsKey(a.getNode1()) && node.containsKey(a.getNode2())){
            flag = ( (HashSet<Arco>) node.get(a.getNode1()) ).remove(a);
            flag1 = ( (HashSet<Arco>) node.get(a.getNode2())).remove(a);
        }
        return flag || flag1;
    }

    public Set<Arco> getEdgeSet(){
        Set<Arco> setArchi = new HashSet<Arco>();
        Iterator<Set<Arco>> hashSet = node.values().iterator();
        while (hashSet.hasNext()){
            setArchi.addAll(hashSet.next());
        }
        return setArchi;
    }

    public Set<Arco> getEdgeSet(Object nodo){
        if(node.containsKey(nodo))
            return node.get(nodo);
        else
            return null;
    }

    public Set<Object> getNodeSet(){
        return node.keySet();
    }

    public String toString(){
        StringBuffer out = new StringBuffer();
        Object nodo;
        Arco arc;
        Iterator<Arco> arco1;
        Iterator<Object> nodo1 = node.keySet().iterator();
        while (nodo1.hasNext()){
            arco1 = node.get( nodo = nodo1.next()).iterator();
            out.append("Nodo " + nodo.toString() + ": ");
            while (arco1.hasNext()){
                arc = arco1.next();
                out.append(arc.toString() + ", ");
            }
            out.append("\n");
        }
        return out.toString();
    }

}


