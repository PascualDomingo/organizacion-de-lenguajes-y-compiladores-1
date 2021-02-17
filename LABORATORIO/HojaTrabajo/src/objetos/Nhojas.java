
package objetos;

public class Nhojas {
    private String valor;
    private String id;
    private String sig;

    public Nhojas(String valor, String id, String sig) {
        this.valor = valor;
        this.id = id;
        this.sig = sig;
    }

    public String getSig() {
        return sig;
    }

    public void setSig(String sig) {
        this.sig = sig;
    }


    public String getValor() {
        return valor;
    }

    public void setValor(String valor) {
        this.valor = valor;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }
    
    
}
