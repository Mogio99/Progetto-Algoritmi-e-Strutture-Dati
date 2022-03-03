import java.io.BufferedReader; 
import java.io.FileNotFoundException; 
import java.io.FileReader; 
import java.io.IOException; 
import java.util.StringTokenizer;
import java.util.List;
import java.io.InputStreamReader;


public class Main {

/**
 * funzione utilizzata per riempire il grafo vuoto ricevuto in base ai dati 
 * del file presi dal parametro file
 * @param g grafo vuoto da dover riempire
 * @param file da dove estrappolare i dati
 * @param typeGraph se grafo diretto oppure no
 * @return
 */
    public static Grafo creationGraph(Grafo g, String file,int typeGraph){
        Object node1 = null, node2 = null, value = null;

        try{

            BufferedReader br = new BufferedReader(new FileReader(file));
            StringTokenizer st = null;
            int tokenNumber = 0;

            while ((file = br.readLine()) != null){
                st = new StringTokenizer(file, ",");
                while (st.hasMoreTokens()){
                    tokenNumber ++;
                    node1 = st.nextToken();
                    tokenNumber ++;
                    node2 = st.nextToken();
                    tokenNumber ++;
                    value = st.nextToken();
                }
                g.add(node1,node2,value);
                if(typeGraph == 0){
                    g.add(node2, node1, value);
                }
                tokenNumber = 0;
            }
            br.close();
        }catch (FileNotFoundException e){
            System.out.println("file non esistente o non trovato");
            e.printStackTrace();
        }catch (IOException e) { 
            e.printStackTrace(); 
        } 
        return g;

    }
/**
 * funzione utilizzata per input dati da tastiera e creare un grafo 
 * g in base al file che si vuole utilizzare e la tipologia di grafo 
 * che si vuole avere: 
 * -> 1 grafo diretto
 * -> 2 grafo non diretto 
 * @param g grafo vuoto 
 * @return varible se il file è italian_dist_graph
 */
    public static int inputData(Grafo g){

        int variable = 0;
        int typeGraph = 0; 

        try{
            System.out.println("Indicare il percorso e il nome del file csv");
            InputStreamReader reader = new InputStreamReader (System.in);        
            BufferedReader myInput = new BufferedReader (reader);
            String file = new String (myInput.readLine());
            if(file.equals("../italian_dist_graph.csv")){
                variable = 1;
            }
            System.out.println("Scegliere la tipologia di grafo :");
            System.out.println("1 -> Grafo diretto");
            System.out.println("2 -> Grafo non diretto");
            InputStreamReader readerType = new InputStreamReader (System.in);        
            BufferedReader myInputType = new BufferedReader (readerType);
            String graphType = new String (myInputType.readLine());
            if(graphType.equals("1")){
                System.out.println("Hai scelto grafo diretto");
                typeGraph = 1;
            }
            if(graphType.equals("2")){
                System.out.println("Hai scelto grafo non diretto");
            }
            System.out.println("-->CREAZIONE DEL GRAFO ESTRATTO DAL FILE<--");
            creationGraph(g, file, typeGraph);
            myInput.close();
            myInputType.close();
        }catch (FileNotFoundException e){
            System.out.println("file non esistente o non trovato");
            e.printStackTrace();
        }catch (IOException e) { 
            e.printStackTrace(); 
        } 
        return variable;
    }

    /**
     * funzione utilizzata per applicare l'algoritmo di kruskal al grafo g passato
     * @param g 
     * @param variable 
     */
    public static void appAlgo(Grafo g, int variable){
        Kruskal istance = new Kruskal();
            List<Arco> result = istance.algoKruskal(g,variable);
            
            double d = 0;
            double val = 0;
            for(int i = 0; i < result.size(); i ++){
                if(variable == 1){
                    val = Double.parseDouble(result.get(i).value.toString()) /1000 ;
                }else {
                    val = Double.parseDouble(result.get(i).value.toString());
                }
                d = d + val;
                val = 0;
            }
            
            System.out.println(result.toString());
            System.out.println(">>>>Il numero di arco minimi generati  "  +result.size()+"<<<<");
            System.out.println(d);

    }
    public static void main(String[] args){
        Grafo g = new Grafo();
         /** variabile utilizzata per distinguere file diversi da italian_dist_graph.csv */
        int variable = 0;
        /**varibile utilizzata per distinguere 0 grafo non diretto altrimenti 1 grafo diretto */

            System.out.println("-->INIZIO PROGRAMMA <--");

            variable = inputData(g); /**funzione utilizzata per la creazione del grafo */

            System.out.println("APPLICAZIONE DELL'ALGORITMO DI KRUSKAL");
            appAlgo(g,variable);

            System.out.println("-->TERMINE PROGRAMMA<--");
            
       
      
    }
}

