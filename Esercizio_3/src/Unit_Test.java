
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Test;


public class Unit_Test {
    UFSnode<Object> test = new  UFSnode<>();

    @Test 
    public void testEmpty() throws Exception{
        System.out.println("Test Empty -> " + test.elemMap.isEmpty());
        assertTrue(test.elemMap.isEmpty());
    }
    @Test
    public void testMakeSet() throws Exception{
        test.makeSet("Torino");
        System.out.println("Test new Node -> " + test.elemMap.containsKey("Torino"));
        assertTrue(test.elemMap.containsKey("Torino"));
    }

    @Test
    public void testFind() throws Exception{
        test.makeSet("Torino");
        System.out.println("Test Find Torino -> " + test.find("Torino"));
        assertEquals("Torino", test.find("Torino"));  
    }

    @Test
    public void testUnion() throws Exception{
        test.makeSet("Torino");
        test.makeSet("Biella");
        test.union("Torino","Biella");
        System.out.println(test.elemMap.entrySet());
        assertEquals(test.elemMap.get("Torino"), test.elemMap.get("Biella").parent);
    }
    
    @Test
    public void testRank() throws Exception{
        test.makeSet("Torino");
        test.makeSet("Biella");
        test.union("Torino","Biella");
        assertEquals(2, test.elemMap.get("Torino").rank);
    }

    @Test
    public void testRm() throws Exception{
        test.makeSet("Torino");
        test.elemMap.remove("Torino");
        System.out.println("Test Remove Torino ");
        assertFalse(test.elemMap.containsKey("Torino"));
    }

    @Test
    public void testParent() throws Exception{
        test.makeSet("Torino");
        test.makeSet("Biella");
        test.makeSet("Borgaro");
        test.union("Torino", "Biella");
        test.union("Torino","Borgaro");
        assertEquals(test.elemMap.get("Torino"), test.elemMap.get("Biella").parent);
        assertEquals(test.elemMap.get("Torino"), test.elemMap.get("Borgaro").parent);
    }

}
