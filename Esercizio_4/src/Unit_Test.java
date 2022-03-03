
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.List;

import org.junit.Test;


public class Unit_Test {
    
    
    Grafo grafo = new Grafo();

    @Test
    public void testGraphEmpty() throws Exception{
        assertTrue(grafo.isEmpty());
    }
    @Test
    public void testNewNode() throws Exception{
        grafo.addObject("testNode");
        System.out.println("Test creazione di un nuovo nodo <testNode>");
        assertTrue(grafo.node.containsKey("testNode"));
        grafo.removeObject("testNode");
    }

    @Test
    public void testNewArc() throws Exception{
        System.out.println("Test creazione di un nuovo arco <arc1,arc2,13.123>");
        Arco arc1 = new Arco("arc1","arc2",13.123);
        assertTrue(grafo.addArc(arc1));
        grafo.removeArc(arc1);
    }
    @Test
    public void testPresNode() throws Exception{
        System.out.println("Test se un nodo è presente nel grafo <test2>");
        grafo.addObject("test2");
        assertTrue(grafo.node.containsKey("test2"));
        System.out.println("Test se un nodo non è presente nel grafo <test3>");
        assertFalse(grafo.node.containsKey("test3"));
    }

    @Test
    public void testPresArc() throws Exception{
        System.out.println("Test se arco è presente nel grafo <arc4,arc3,13A21>");
        Arco testArc = new Arco("arc4","arc3","13A21");
        grafo.addArc(testArc);
        assertTrue(grafo.contains(testArc));
        grafo.removeArc(testArc);
    }

    @Test
    public void testRemoveArc() throws Exception{
        Arco testRemove1 = new Arco("rem1","rem2",1254.53);
        Arco testRemove2 = new Arco("rem1","rem3",111.543);
        Arco testRemove3 = new Arco("rem1","rem4",1653.54);
        Arco testRemove4 = new Arco("rem2","rem4",1254.53);
        grafo.addArc(testRemove1);
        grafo.addArc(testRemove2);
        grafo.addArc(testRemove3);
        grafo.addArc(testRemove4);
        System.out.println("L'insieme di archi e': " + grafo.getEdgeSet());
        System.out.println("rimozione arco <rem1,rem2,1254.53>");
        assertFalse(grafo.contains(grafo.removeArc(testRemove1)));
        System.out.println("L'insieme di archi e': " + grafo.getEdgeSet());
        grafo.removeArc(testRemove2);
        grafo.removeArc(testRemove3);
        grafo.removeArc(testRemove4);
    }

    @Test
    public void testRemoveNode() throws Exception{
        System.out.println("Rimosso nodo <test2>");
        grafo.removeObject("test2");
        assertFalse(grafo.node.containsKey("test2"));
    }

    @Test
    public void numNode() throws Exception{
        System.out.println("Test sul numero dei nodi");
        Arco testRemove1 = new Arco("rem1","rem2",1254.53);
        Arco testRemove2 = new Arco("rem1","rem3",111.543);
        Arco testRemove3 = new Arco("rem1","rem4",1653.54);
        Arco testRemove4 = new Arco("rem2","rem4",1254.53);
        grafo.addArc(testRemove1);
        grafo.addArc(testRemove2);
        grafo.addArc(testRemove3);
        grafo.addArc(testRemove4);
        assertEquals(4,grafo.get_node_number());
        grafo.removeArc(testRemove1);
        grafo.removeArc(testRemove2);
        grafo.removeArc(testRemove3);
        grafo.removeArc(testRemove4);
    }

    @Test
    public void numArc() throws Exception{
        System.out.println("Test sul numero di archi");
        Arco testNum1 = new Arco("rem1","rem2",1254.53);
        Arco testNum2 = new Arco("rem1","rem3",111.543);
        Arco testNum3 = new Arco("rem1","rem4",1653.54);
        Arco testNum4 = new Arco("rem2","rem4",1254.53);
        grafo.addArc(testNum1);
        grafo.addArc(testNum2);
        grafo.addArc(testNum3);
        grafo.addArc(testNum4);
        assertEquals(4,grafo.get_arch_number());
        grafo.removeArc(testNum1);
        grafo.removeArc(testNum2);
        grafo.removeArc(testNum3);
        grafo.removeArc(testNum4);
    }

    /**
     * Test sull'utilizzo dell'algoritmo di kruskal
     * Creo un semplice grafo con 6 grafi, utilizzando
     * come etichette lettere dell'alfabeto.
     * Con 12 archi
     * il risultato del grafo è 21
     */
    @Test
    public void testKruskal() throws Exception{
        Grafo graph = new Grafo();
        graph.add("A", "B", 21);
        graph.add("A", "F", 5);
        graph.add("F", "B", 4);
        graph.add("A", "C", 7);
        graph.add("A", "E",6);
        graph.add("B", "C",16);
        graph.add("B", "D", 8);
        graph.add("C", "E", 12);
        graph.add("D", "F", 14);
        graph.add("F", "E", 2);
        graph.add("D", "E", 9);
        graph.add("C", "D", 3);
        
        Kruskal test = new Kruskal();
        List<Arco> res_test = test.algoKruskal(graph,0);
        /**
         * calcolo la distanza minima trovata
         */
        double val = 0;
        for(int i = 0; i < res_test.size(); i++){
            val = val + Double.parseDouble(res_test.get(i).value.toString());
        }
        assertEquals(true, (21 == val));
    }
}