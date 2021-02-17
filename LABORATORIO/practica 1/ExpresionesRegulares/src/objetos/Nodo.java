
package objetos;

import java.util.ArrayList;

public class Nodo {
    public String raiz;
    public ArrayList <Nodo> hijos = new ArrayList<>();
    public String  valor;
    public int idN;
    public String anulables;
    public String primeros;
    public String ultimos;

       
    public void AddHijos(Nodo hijo){
        hijos.add(hijo);
    }

    public String getPrimeros() {
        return primeros;
    }

    public void setPrimeros(String primeros) {
        this.primeros = primeros;
    }

    public String getUltimos() {
        return ultimos;
    }

    public void setUltimos(String ultimos) {
        this.ultimos = ultimos;
    }
    
    
    
    public String getAnulables() {
        return anulables;
    }

    public void setAnulables(String anulables) {
        this.anulables = anulables;
    }
    
    public String getRaiz() {
        return raiz;
    }

    public void setRaiz(String raiz) {
        this.raiz = raiz;
    }

    public ArrayList<Nodo> getHijos() {
        return hijos;
    }

    public void setHijos(ArrayList<Nodo> hijos) {
        this.hijos = hijos;
    }

    public String getValor() {
        return valor;
    }

    public void setValor(String valor) {
        this.valor = valor;
    }

    public int getIdN() {
        return idN;
    }

    public void setIdN(int idN) {
        this.idN = idN;
    }

    
}
