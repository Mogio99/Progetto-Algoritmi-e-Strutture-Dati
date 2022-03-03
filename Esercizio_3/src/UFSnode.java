import java.util.HashMap;

public class UFSnode <T> {

    protected HashMap<Object,Node<Object>> elemMap;   

    public UFSnode(){
        elemMap = new HashMap<>();
    }

    public void makeSet(Object element){
        if(elemMap.containsKey(element)){
            System.out.println("Elemento già esistente in un nodo");
        }
        elemMap.put(element, new Node<>(element));
    }
    public Object find (Object e){
        Node<Object> node = elemMap.get(e);
        if(node == null){
            System.err.println("elemento non esistente");
        }
        if(node.parent == null){
            return (Object) node.element;
        }else {
            node.parent = elemMap.get(find((Object)node.parent.element));
        }
        return (Object)node.parent.element;
    }
    
    public void union(Object a, Object b){
        Node<Object> node1 = elemMap.get(a);
        Node<Object> node2 = elemMap.get(b);

        node2.parent = node1;
        node1.rank += node2.rank;
    }
 
    class Node<V>{

        Node<Object> parent;
        Object element;
        int rank;

        public Node(){
            this(null);
        }

        public Node(Object elem){
            element = elem;
            rank = 1;
            parent = null;
        }
    }

}