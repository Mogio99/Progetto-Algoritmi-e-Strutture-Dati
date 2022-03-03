import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;
public class TestMain {
    public static void main(String [] args){
        Result test = JUnitCore.runClasses(Unit_Test.class);
        System.out.println("Prova dei test");

        for (Failure failure : test.getFailures()) {
            System.out.println(failure.toString());
        }
      
        System.out.println("I test fatti hanno risultato -> " + test.wasSuccessful());
    }
}
