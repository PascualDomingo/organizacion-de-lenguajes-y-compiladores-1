
package objetos;

import java.util.ArrayList;
import java.util.LinkedList;


public class ExpresionRegular {
    private String id;
    Nodo miNodo;
    private LinkedList<Nhojas> hojas;

    public ExpresionRegular(String id, Nodo miNodo, LinkedList<Nhojas> hojas) {
        this.id = id;
        this.miNodo = miNodo;
        this.hojas = hojas;
    }

    public LinkedList<Nhojas> getHojas() {
        return hojas;
    }

    public void setHojas(LinkedList<Nhojas> hojas) {
        this.hojas = hojas;
    }
    


    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public Nodo getMiNodo() {
        return miNodo;
    }

    public void setMiNodo(Nodo miNodo) {
        this.miNodo = miNodo;
    }

    

    
    
    
}
