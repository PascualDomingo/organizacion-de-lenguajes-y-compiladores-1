
package objetos;

public class ErrorLexico {
    private String lexico;
    private int linea;
    private int columna;
    private String tipo;
    private String descripcion;

    public ErrorLexico(String lexico, int linea, int columna, String tipo, String descripcion) {
        this.lexico = lexico;
        this.linea = linea;
        this.columna = columna;
        this.tipo = tipo;
        this.descripcion = descripcion;
    }

    public String getLexico() {
        return lexico;
    }

    public void setLexico(String lexico) {
        this.lexico = lexico;
    }

    public int getLinea() {
        return linea;
    }

    public void setLinea(int linea) {
        this.linea = linea;
    }

    public int getColumna() {
        return columna;
    }

    public void setColumna(int columna) {
        this.columna = columna;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }
    
    
    
    
}
