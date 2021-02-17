
package hojatrabajo;
import analizador.AnalizadorLexico;
import analizador.analisis_sintactico;
import java.io.*; 
import java.util.*;

public class HojaTrabajo {

    public static void main(String[] args) {
        //Interfaz frmInterfaz = new Interfaz();
        //frmInterfaz.show();
        String datos = Arrays.toString(args);
        AnalizadorLexico lexico = new AnalizadorLexico(new BufferedReader(new StringReader(datos)));
        analisis_sintactico sin = new analisis_sintactico(lexico);
        try {
            sin.parse();
            System.out.println(sin.salida);
        } catch (Exception e) {
            System.out.println("error del programador XD: " + e);
        }
        

    }
    
}
